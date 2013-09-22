#pragma once

#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <vector>
#include <GL/freeglut.h>
#include "Shader.h"

class ShaderProgram {
private:
    Shader* vertexShader;
    Shader* fragmentShader;

    std::vector<GLuint> shaderList;

    GLuint theProgram;
    GLuint globalUniformBlockIndex;
    GLuint modelToWorldMatrixUnif;
    GLuint baseColorUnif;

    static const int globalMatricesBindingIndex = 0;

public:
    ShaderProgram(const std::string& vertexShaderName, const std::string& fragmentShaderName);
    ~ShaderProgram(void);

    GLuint getProgram();
    GLuint getGlobalUniformBlockIndex();
    GLuint getModelToWorldMatrixUnif();
    GLuint getBaseColorUnif();

    static int getGlobalMatricesBindingIndex();
};

#endif