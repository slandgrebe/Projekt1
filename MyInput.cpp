#include "MyInput.h"

MyInput::MyInput() {
    std::cout << "MyInput" << std::endl;
}


MyInput::~MyInput(void) {
}


void MyInput::keyboard(unsigned char key, int x, int y) {
    std::cout << "MyInput::keyboard" << " key[" << key << "] x[" << x << "] y[" << y << "]" << std::endl;
    
    switch(key) {
        case 27:
		    glutLeaveMainLoop();
		    return;
        // camera
        case 'l': MyWindow::getInstance()->getCamera()->moveX(-4.0f); break; // nach rechts drehen
        case 'j': MyWindow::getInstance()->getCamera()->moveX(4.0f); break; // nach links drehen
        case 'i': MyWindow::getInstance()->getCamera()->moveZ(-4.0f); break; // naeher ran
        case 'k': MyWindow::getInstance()->getCamera()->moveZ(4.0f); break; // weiter weg
        case 'u': MyWindow::getInstance()->getCamera()->moveY(4.0f); break; // nach oben drehen
        case 'o': MyWindow::getInstance()->getCamera()->moveY(-4.0f); break; // nach unten drehen
        // camera target
        case 'e': MyWindow::getInstance()->getCamera()->moveTargetZ(4.0f); break; // nach vorne
        case 'd': MyWindow::getInstance()->getCamera()->moveTargetZ(-4.0f); break; // nach hinten
        case 'f': MyWindow::getInstance()->getCamera()->moveTargetX(-4.0f); break; // nach rechts
        case 's': MyWindow::getInstance()->getCamera()->moveTargetX(4.0f); break; // nach links
        case 32: MyWindow::getInstance()->getCamera()->moveTargetY(4.0f); break; // Space - nach oben
        case 'x': MyWindow::getInstance()->getCamera()->moveTargetY(-4.0f); break; // nach unten
        case 'q': MyWindow::getInstance()->getWorld()->getUnitCubeColor()->rotateY(10.0f); break; // würfel drehen
        case 'm': MyWindow::getInstance()->getWorld()->getUnitCubeColor()->scale(glm::vec3(10, 10, 10)); break; // würfel vergrössern
        case 'n': MyWindow::getInstance()->getWorld()->getUnitCubeColor()->scale(glm::vec3(1, 1, 1)); break; // würfel verkleinern
    }

    glutPostRedisplay();
}