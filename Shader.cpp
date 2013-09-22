#include "Shader.h"


Shader::Shader(GLenum shaderType, const std::string& shaderFileName) {
    theShader = Framework::LoadShader(shaderType, shaderFileName);
}


Shader::~Shader(void) {
}

GLuint Shader::getShader() {
    return theShader;
}