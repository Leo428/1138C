#include "userincludes/robotstates.hpp"

RobotStates* RobotStates::instance = nullptr;

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