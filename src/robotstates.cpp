#include "userincludes/robotstates.hpp"

RobotStates* RobotStates::instance = nullptr;
const double RobotStates::ROBOT_WIDTH_in = 0;
const double RobotStates::ROBOT_LENGTH_in = 0;
const double RobotStates::ROBOT_MAX_VELOCITY_in = 0;
const double RobotStates::ROBOT_MAX_ACCEL_in = 0;
const double RobotStates::ROBOT_MAX_JERK_in = 0;

RobotStates::FieldColor RobotStates::fieldColor; //initialize the static stuff!
RobotStates::AutoChoice RobotStates::autoChoice;

double RobotStates::targetY = 0.0;
double RobotStates::targetFlag_Y = 0.0;
double RobotStates::targetFlag_X = 0.0;
double RobotStates::hortizontal_correction = 0.0;
double RobotStates::vertical_correction = 0.0;

RobotStates::RobotStates() {
    
}

RobotStates* RobotStates::getInstance() {
    if(instance == 0) {
        instance = new RobotStates();
    }
    return instance;
}