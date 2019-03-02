#include "main.h"
#include "userincludes/robot.hpp"
#include <cmath>

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

void prepareToTurn() {
    Robot::rightFront_Motor->setReversed(false);
    Robot::rightBack_Motor->setReversed(false);
}

void prepareToDrive() {
    Robot::rightFront_Motor->setReversed(true);
    Robot::rightBack_Motor->setReversed(true);
}

void back_autoForState() {
	delay(6500);
	Robot::nuc->punchIT();
	delay(1000);
	Robot::nuc->stopPunchers();

	Robot::turnController->generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.475_ft, 0_ft, 0_deg}}, "45deg");
	prepareToTurn();
	if(RobotStates::fieldColor == RobotStates::FieldColor::BLUE) {
		Robot::turnController->setTarget("45deg", true);
	} else {
		Robot::turnController->setTarget("45deg");
	}
	Robot::turnController->waitUntilSettled();
	Robot::turnController->removePath("45deg");
	prepareToDrive();

	Robot::base->forward(-50);
	delay(300);
	Robot::base->stop();
	delay(100);

    Robot::profileController->setTarget("A");
	Robot::collector->collectBalls();
	Robot::profileController->waitUntilSettled();
	Robot::profileController->removePath("A");

	Robot::profileController->setTarget("back2plat", true);
	Robot::profileController->waitUntilSettled();

	prepareToTurn();
	if(RobotStates::fieldColor == RobotStates::FieldColor::BLUE) {
		Robot::turnController->setTarget("90deg", true);
	} else {
		Robot::turnController->setTarget("90deg");
	}

	Robot::turnController->waitUntilSettled();
	Robot::turnController->removePath("90deg");

	prepareToDrive();

	Robot::base->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	Robot::base->forward(-200);
	delay(1550);
	Robot::base->stop();
	Robot::collector->stopCollector();
	Robot::base->setBrakeMode(okapi::AbstractMotor::brakeMode::coast);	
}

void autonomous() {
	// RobotStates::autoChoice = RobotStates::AutoChoice::BACK_TILE_ONE_FLAG;
	// RobotStates::fieldColor = RobotStates::FieldColor::BLUE;

    switch(RobotStates::autoChoice){
		case (RobotStates::AutoChoice::BACK_TILE_ONE_FLAG):
			back_autoForState();
			break;
        
		default:
			break;
	}
}
