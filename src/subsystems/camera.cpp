#include "userincludes/subsystems/camera.hpp"
#include <cmath>

Vision * Camera::buttomCam = nullptr;
std::vector<vision_object_s_t> * Camera::targetVector = nullptr;

Camera::Camera() {
    // buttomCam = new Vision(RobotStates::CAMERA_STATIC, E_VISION_ZERO_TOPLEFT);
    // buttomCam->clear_led();
    // buttomCam->set_exposure(70); 
}

double Camera::controllerGet() {
    // updateSensor();
    // printf("function called: %f \n", this->targetY);
    return RobotStates::targetFlag_Y;
}

bool Camera::compareHeight(vision_object_s_t i, vision_object_s_t j) {
    return (i.y_middle_coord < j.y_middle_coord);
}

bool Camera::compareCenter(vision_object_s_t i, vision_object_s_t j) {
    return ((fabs(i.x_middle_coord * 1.0 - (VISION_FOV_WIDTH * 1.0)/2) < fabs(j.x_middle_coord * 1.0 - (VISION_FOV_WIDTH * 1.0)/2)));
}