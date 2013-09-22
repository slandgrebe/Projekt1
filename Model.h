#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"

class Model {
private:
    Framework::Mesh* mesh;
    

    GLuint shaderProgram;
    GLuint modelToWorldMatrixUniform;
    GLuint baseColorUniform;
    glm::vec4 baseColor;

    glm::vec3 position;
    // scale
    glm::vec3 myScale;
    // rotation
    float rotationX;
    float rotationY;
    float rotationZ;

public:
    Model(const std::string &strFilename);
    ~Model(void);

    void setShaderProgram(GLuint shaderProgram);
    void setModelToWorldMatrixUniform(GLuint modelToWorldMatrixUniform);
    void setBaseColorUniform(GLuint baseColorUniform, float r, float g, float b, float a);

    void render(glutil::MatrixStack modelMatrix);

    void setPosition(float x, float y, float z);
    void translate(glm::vec3 movementVector);
    void scale(glm::vec3 scale);
    void rotateX(float degrees);
    void rotateY(float degrees);
    void rotateZ(float degrees);
};

#endif