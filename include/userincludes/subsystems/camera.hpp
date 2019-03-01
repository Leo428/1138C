#ifndef CAMERA
#define CAMERA

#include "main.h"
#include "userincludes/robotstates.hpp"

class Camera : public ControllerInput<double> {
    public:
        Camera();

        double controllerGet() override;
        static Vision * buttomCam;

        static std::vector<vision_object_s_t> * targetVector;

    private:
        //methods
        static bool compareHeight(vision_object_s_t i, vision_object_s_t j);
        static bool compareCenter(vision_object_s_t i, vision_object_s_t j);

        //objects (flags)
        vision_object_s_t hoodFlags[6]; 
        vision_object_s_t allFlags[6];
        vision_object_s_t targetFlags[3];
};

#endif