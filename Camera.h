#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "framework.h"
#include <iostream>

class Camera {
private:
    glm::vec3 target;
    glm::vec3 up;

    //In spherical coordinates.
    glm::vec3 sphereCamRelPos;

    glm::mat4 lookAtMatrix;

    glm::vec3 resolvePosition();
    void calcLookAtMatrix();

public:
    Camera(void);
    ~Camera(void);

    glm::mat4 getLookAtMatrix() { calcLookAtMatrix(); return lookAtMatrix; }
    
    void logPosition() { std::cout << "Camera Position: x[" << sphereCamRelPos.x << "] y[" << sphereCamRelPos.y << "] z[" << sphereCamRelPos.z << "]" << std::endl; }
    glm::vec3 getTarget() { return target; }

    void moveTargetX(float x) { target.x += x; }
    void moveTargetY(float y) { target.y += y; }
    void moveTargetZ(float z) { target.z += z; }

    void moveX(float x) { sphereCamRelPos.x += x; logPosition(); calcLookAtMatrix(); logPosition(); }
    void moveY(float y) { sphereCamRelPos.y += y; logPosition(); }
    void moveZ(float z);
};

#endif