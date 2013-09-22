#include "framework.h"
#include <glload/gl_3_3.h>
#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const std::string& vertexShaderName, const std::string& fragmentShaderName) {
    vertexShader = new Shader(GL_VERTEX_SHADER, vertexShaderName);
    fragmentShader = new Shader(GL_FRAGMENT_SHADER, fragmentShaderName);
    
    shaderList.push_back(vertexShader->getShader());
    shaderList.push_back(fragmentShader->getShader());

    theProgram = Framework::CreateProgram(shaderList);
    modelToWorldMatrixUnif = glGetUniformLocation(theProgram, "modelToWorldMatrix");
    globalUniformBlockIndex = glGetUniformBlockIndex(theProgram, "GlobalMatrices");
    baseColorUnif = glGetUniformLocation(theProgram, "baseColor");

    glUniformBlockBinding(theProgram, globalUniformBlockIndex, globalMatricesBindingIndex);
}


ShaderProgram::~ShaderProgram(void) {
}

GLuint ShaderProgram::getProgram() {
    return theProgram;
}
GLuint ShaderProgram::getGlobalUniformBlockIndex() {
    return globalUniformBlockIndex;
}
GLuint ShaderProgram::getModelToWorldMatrixUnif() {
    return modelToWorldMatrixUnif;
}
GLuint ShaderProgram::getBaseColorUnif() {
    return baseColorUnif;
}

int ShaderProgram::getGlobalMatricesBindingIndex() {
    return globalMatricesBindingIndex;
}