#include "main.h"

#include "userincludes/robotstates.hpp"
#include "userincludes/robot.hpp"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.will
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 * 
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

okapi::Controller master;

void opcontrol() {
	while (true) {
		Robot::base->arcade(master.getAnalog(okapi::ControllerAnalog::leftY), master.getAnalog(okapi::ControllerAnalog::leftX), 0.1);
		// Robot::base->tank(master.getAnalog(okapi::ControllerAnalog::leftY), master.getAnalog(okapi::ControllerAnalog::rightY), 0.2);

		//1 is top button, 2 is bottom button 
		if(master.getDigital(okapi::ControllerDigital::L1)) {
			Robot::collector->outBall();
		} else if (master.getDigital(okapi::ControllerDigital::L2)){
			Robot::collector->collectBalls();
		} else {
			Robot::collector->stopCollector();
		}

		if(master.getDigital(okapi::ControllerDigital::L1)) {
			Robot::nuc->punchIT();
		} else {
			Robot::nuc->stopPunchers();
		}
		
		pros::delay(10);
	}
}
