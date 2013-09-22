#include "Camera.h"


Camera::Camera(void) {
    std::cout << "Camera" << std::endl;

    sphereCamRelPos.x = 67.5f;
    sphereCamRelPos.y = 2.0f;
    sphereCamRelPos.z = 4.0f;

    target.x = 0.0f;
    target.y = 0.4f;
    target.z = 0.0f;

    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;

    resolvePosition();
}


Camera::~Camera(void) {
}

glm::vec3 Camera::resolvePosition() {
    std::cout << "Camera::resolvePositon()" << std::endl;

    glutil::MatrixStack tempMat;

	float phi = Framework::DegToRad(sphereCamRelPos.x);
    float theta = Framework::DegToRad(sphereCamRelPos.y + 90.0f);

	float fSinTheta = sinf(theta);
	float fCosTheta = cosf(theta);
	float fCosPhi = cosf(phi);
	float fSinPhi = sinf(phi);

	glm::vec3 dirToCamera(fSinTheta * fCosPhi, fCosTheta, fSinTheta * fSinPhi);
	
    return (dirToCamera * sphereCamRelPos.z) + target;
}

void Camera::calcLookAtMatrix() {
    std::cout << "Camera::calcLookAtMatrix()" << std::endl;

    glm::vec3 position = resolvePosition();

    glm::vec3 lookDir = glm::normalize(this->target - position);
	glm::vec3 upDir = glm::normalize(this->up);

	glm::vec3 rightDir = glm::normalize(glm::cross(lookDir, upDir));
	glm::vec3 perpUpDir = glm::cross(rightDir, lookDir);

	glm::mat4 rotMat(1.0f);
	rotMat[0] = glm::vec4(rightDir, 0.0f);
	rotMat[1] = glm::vec4(perpUpDir, 0.0f);
	rotMat[2] = glm::vec4(-lookDir, 0.0f);

	rotMat = glm::transpose(rotMat);

	glm::mat4 transMat(1.0f);
    transMat[3] = glm::vec4(-position, 1.0f);

    this->lookAtMatrix =  rotMat * transMat;
}

void Camera::moveZ(float z) { 

    std::cout << std::endl << "moveZ(" << z << ")" << std::endl;
    logPosition(); 

    sphereCamRelPos.z += z; 

    logPosition();
}