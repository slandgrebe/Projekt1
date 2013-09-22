
#include <iostream>
#include "MyWindow.h"

bool MyWindow::instanceFlag = false;
MyWindow* MyWindow::instance = NULL;

MyWindow* MyWindow::getInstance(void) {
    if(!instanceFlag) {
        instance = new MyWindow();
        instanceFlag = true;
    }
    return instance;
}

MyWindow::MyWindow(void) {
    input = new MyInput();
    camera = new Camera();
}


MyWindow::~MyWindow(void) {
    delete input;
    delete camera;
}

void MyWindow::init(void) {
    std::cout << "init" << std::endl;

    uniformColorProgram = new ShaderProgram("PosOnlyWorldTransformUBO.vert", "ColorUniform.frag");
    objectColorProgram = new ShaderProgram("PosColorWorldTransformUBO.vert", "ColorPassthrough.frag");
    uniformColorTintProgram = new ShaderProgram("PosColorWorldTransformUBO.vert", "ColorMultUniform.frag");

    glGenBuffers(1, &globalMatricesUBO);
	glBindBuffer(GL_UNIFORM_BUFFER, globalMatricesUBO);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::mat4) * 2, NULL, GL_STREAM_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);

	glBindBufferRange(GL_UNIFORM_BUFFER, ShaderProgram::getGlobalMatricesBindingIndex(), globalMatricesUBO,
		0, sizeof(glm::mat4) * 2);

    glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);
	glEnable(GL_DEPTH_CLAMP);

    try {
        world = new World();
	}
	catch(std::exception &except) {
		printf("%s\n", except.what());
		throw;
	}
}
void MyWindow::display(void) {
    std::cout << "display" << std::endl;

    // "Hintergrundfarbe" und Tiefentest
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(world != NULL) {
        // camera
        glutil::MatrixStack camMatrix;
        camMatrix.SetMatrix(camera->getLookAtMatrix());

        glBindBuffer(GL_UNIFORM_BUFFER, getGlobalMatricesUBO());
		glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(camMatrix.Top()));
		glBindBuffer(GL_UNIFORM_BUFFER, 0);

        world->render();
    }

    // Aenderungen anzeigen
    glutSwapBuffers();
}
void MyWindow::reshape(int width, int height) {
    std::cout << "reshape" << std::endl;

    float g_fzNear = 1.0f;
    float g_fzFar = 1000.0f;

    glutil::MatrixStack persMatrix;
    persMatrix.Perspective(45.0f, (width / (float)height), g_fzNear, g_fzFar);

	//glBindBuffer(GL_UNIFORM_BUFFER, g_GlobalMatricesUBO);
    glBindBuffer(GL_UNIFORM_BUFFER, MyWindow::getInstance()->getGlobalMatricesUBO());

	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(persMatrix.Top()));
	glBindBuffer(GL_UNIFORM_BUFFER, 0);


    // Viewport definieren und neu zeichnen
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glutPostRedisplay();
}
void MyWindow::keyboard(unsigned char key, int x, int y) {
    input->keyboard(key, x, y);
}