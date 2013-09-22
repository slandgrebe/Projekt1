#pragma once

#ifndef MYWINDOW_H
#define MYWINDOW_H

#include "framework.h"
#include "World.h"
#include "Camera.h"
#include "ShaderProgram.h"
#include "MyInput.h"

class MyInput;

class MyWindow {
private:
    static bool instanceFlag;
    static MyWindow* instance;

    World* world;

    Camera* camera;

    MyInput* input;
    ShaderProgram* uniformColorProgram;
    ShaderProgram* objectColorProgram;
    ShaderProgram* uniformColorTintProgram;

    GLuint globalMatricesUBO;

    MyWindow(void);
    MyWindow(MyWindow const&);
    void operator=(MyWindow const&);
    ~MyWindow(void);

public:
    static MyWindow* getInstance(void);

    void init(void);
    void display(void);
    void reshape(int width, int height);
    void keyboard(unsigned char key, int x, int y);

    Camera* getCamera(void) { return camera; }
    World* getWorld(void) { 
        return world; 
    }

    // besser in der World Klasse versorgen?
    ShaderProgram* getUniformColorProgram(void) { return uniformColorProgram; }
    ShaderProgram* getObjectColorProgram(void) { return objectColorProgram; }
    ShaderProgram* getUniformColorTintProgram(void) { return uniformColorTintProgram; }
    GLuint getGlobalMatricesUBO(void) { return globalMatricesUBO; }
};

#endif