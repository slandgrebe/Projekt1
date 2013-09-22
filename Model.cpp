#include "Model.h"

Model::Model(const std::string &strFilename) {
    mesh = new Framework::Mesh(strFilename);

    shaderProgram = -1;
    modelToWorldMatrixUniform = -1;
    baseColorUniform = -1;
    baseColor = glm::vec4(0.8f, 0.8f, 0.8f, 1.0f);

    position = glm::vec3(0.0f, 0.0f, 0.0f);
    // scale
    myScale = glm::vec3(1.0f, 1.0f, 1.0f);
    // rotation
    rotationX = 0.0f;
    rotationY = 0.0f;
    rotationZ = 0.0f;
}


Model::~Model(void) {
    delete mesh;
    mesh = NULL;
}

void Model::setShaderProgram(GLuint shaderProgram) {
    this->shaderProgram = shaderProgram;
}
void Model::setModelToWorldMatrixUniform(GLuint modelToWorldMatrixUniform) {
    this->modelToWorldMatrixUniform = modelToWorldMatrixUniform;
}
void Model::setBaseColorUniform(GLuint baseColorUniform, float r, float g, float b, float a) {
    this->baseColorUniform = baseColorUniform;
    this->baseColor = glm::vec4(r, g, b, a);
}

void Model::render(glutil::MatrixStack modelMatrix) {
    if(shaderProgram != -1) {
	    glutil::PushStack push(modelMatrix);
        
	    modelMatrix.Translate(position);
	    modelMatrix.Scale(myScale);
        modelMatrix.RotateX(rotationX);
        modelMatrix.RotateY(rotationY);
        modelMatrix.RotateZ(rotationZ);

        glUseProgram(shaderProgram);

        if(modelToWorldMatrixUniform != -1) {
            glUniformMatrix4fv(modelToWorldMatrixUniform, 1, GL_FALSE, glm::value_ptr(modelMatrix.Top()));
        }

        if(baseColorUniform != -1) {
            glUniform4f(baseColorUniform, baseColor.r, baseColor.g, baseColor.b, baseColor.a);
        }

        mesh->Render();

	    glUseProgram(0);
    }
}

void Model::setPosition(float x, float y, float z) {
    position = glm::vec3(x, y, z);
}
void Model::translate(glm::vec3 movementVector) {
    position += movementVector;
}

void Model::scale(glm::vec3 scale) {
    myScale = scale;
}

void Model::rotateX(float degrees) {
    rotationX += degrees;
    //rotationX = fmod(rotationX, 360.0f);
}
void Model::rotateY(float degrees) {
    rotationY += degrees;
    //rotationY = fmod(rotationY, 360.0f);
}
void Model::rotateZ(float degrees) {
    rotationZ += degrees;
    rotationZ = fmod(rotationZ, 360.0f);
}