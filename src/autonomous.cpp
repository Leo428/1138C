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
    
}

void autonomous() {
    switch(RobotStates::autoChoice){
		case (RobotStates::AutoChoice::BACK_TILE_ONE_FLAG):
			back_autoForState();
			break;
        
		default:
			break;
	}
}
