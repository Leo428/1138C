#ifndef ROBOT
#define ROBOT

#include "userincludes/robotstates.hpp"
#include "userincludes/subsystems/collector.hpp"
#include "userincludes/subsystems/nuclauncher.hpp"
#include "userincludes/subsystems/camera.hpp"

class Robot {
    public:
        Robot();
        static okapi::ChassisControllerIntegrated* base;
        static Collector* collector;
        static NucLauncher* nuc;
        static Camera* cam;
        static Robot* getInstance();

        static okapi::Motor * leftFront_Motor;
        static okapi::Motor * leftBack_Motor;
        static okapi::Motor * rightFront_Motor;
        static okapi::Motor * rightBack_Motor;

        static okapi::AsyncMotionProfileController * turnController;
        static okapi::AsyncMotionProfileController * profileController;
        static okapi::AsyncMotionProfileController * mediumSpeedController;
        
        static double in2meter(double in);
        
    private:
        static Robot* instance;
};


#endif