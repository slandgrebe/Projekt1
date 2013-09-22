#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include "framework.h"

class Shader {
private:
    GLuint theShader;

public:
    Shader(GLenum shaderType, const std::string& shaderFileName);
    ~Shader(void);

    GLuint getShader();
};

#endif