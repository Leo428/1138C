#include "userincludes/robot.hpp"

Collector* Robot::collector = nullptr;
NucLauncher* Robot::nuc = nullptr;
Camera* Robot::cam = nullptr;
Robot* Robot::instance = nullptr;
okapi::Motor * Robot::leftFront_Motor = new okapi::Motor(RobotStates::BASE_LEFT_FRONT);
okapi::Motor * Robot::leftBack_Motor = new okapi::Motor(RobotStates::BASE_LEFT_BACK);
okapi::Motor * Robot::rightFront_Motor = new okapi::Motor(RobotStates::BASE_RIGHT_FRONT);
okapi::Motor * Robot::rightBack_Motor = new okapi::Motor(RobotStates::BASE_RIGHT_BACK);

okapi::AsyncMotionProfileController * Robot::mediumSpeedController = 0;
okapi::AsyncMotionProfileController * Robot::turnController = 0;
okapi::AsyncMotionProfileController * Robot::profileController = 0;

okapi::ChassisControllerIntegrated* Robot::base = nullptr;

Robot::Robot() {
    collector = new Collector();
    nuc = new NucLauncher();
    cam = new Camera();
    
    static std::vector<vision_object_s_t> flagsVector;
    Camera::targetVector = &flagsVector;

    static auto drive = ChassisControllerFactory::create(
		{RobotStates::BASE_LEFT_FRONT,RobotStates::BASE_LEFT_BACK},
		{-RobotStates::BASE_RIGHT_FRONT,-RobotStates::BASE_RIGHT_BACK}, 
		AbstractMotor::gearset::green,
        {4_in, 12.5_in}); //12.5
    
    Robot::base = &drive;

    static auto _turnController = AsyncControllerFactory::motionProfile(
        in2meter(20.0),  // Maximum linear velocity of the Chassis in m/s 20
        in2meter(30.0),  // Maximum linear acceleration of the Chassis in m/s/s 30
        in2meter(300.0), // Maximum linear jerk of the Chassis in m/s/s/s 300
        *base // Chassis Controller
    );

    static auto _profileController = AsyncControllerFactory::motionProfile(
        in2meter(45.0),  // Maximum linear velocity of the Chassis in m/s 40
        in2meter(65.0),  // Maximum linear acceleration of the Chassis in m/s/s 60
        in2meter(500.0), // Maximum linear jerk of the Chassis in m/s/s/s
        *base // Chassis Controller
    );

    static auto _mediumSpeedController = AsyncControllerFactory::motionProfile(
        in2meter(30.0),  // Maximum linear velocity of the Chassis in m/s 40
        in2meter(45.0),  // Maximum linear acceleration of the Chassis in m/s/s 60
        in2meter(450.0), // Maximum linear jerk of the Chassis in m/s/s/s
        *base // Chassis Controller
    );

    turnController = &_turnController;
    profileController = &_profileController;
    mediumSpeedController = &_mediumSpeedController;
}

Robot* Robot::getInstance() {
    if(instance == 0) {// RobotStates::potTarget = 250;
        instance = new Robot();
    }
    return instance;
}

double Robot::in2meter(double in) {
    return (in / 39.37);
}