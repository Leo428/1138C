#include "userincludes/subsystems/nuclauncher.hpp"

//make sure to initialize all the static members

okapi::Motor * NucLauncher::puncher_1_Motor = nullptr;
okapi::Motor * NucLauncher::puncher_2_Motor = nullptr;

NucLauncher::NucLauncher(){
    initMotors();
}

void NucLauncher::initMotors() {
    puncher_1_Motor = new okapi::Motor(RobotStates::PUNCHER_1_PORT);
    puncher_2_Motor = new okapi::Motor(RobotStates::PUNCHER_2_PORT);
    puncher_1_Motor->setGearing(AbstractMotor::gearset::red);
    puncher_2_Motor->setGearing(AbstractMotor::gearset::red);

    puncher_1_Motor->setReversed(true);
}

void NucLauncher::punchIT() {
    puncher_1_Motor->move(-127);
    puncher_2_Motor->move(-127);
}

void NucLauncher::stopPunchers() {
    puncher_1_Motor->move(0);
    puncher_2_Motor->move(0);
}
