#include "main.h"
#include "userincludes/subsystems/bigscreentv.hpp"
#include "userincludes/robot.hpp"
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {
    RobotStates * robotStates = RobotStates::getInstance();
    Robot * robot = Robot::getInstance();
    printf("initializing! \n");

    printf("Written by Zheyuan Hu from 448X Echo. This is my gift to 1138C! \n");

    BigScreenTV* bigTV = new BigScreenTV();
    bigTV->createUIComponents();
    pros::Task refresh(bigTV->updateScreen);
    delay(200);
    
    //each controller can only have 3 paths at a time so sad
    Robot::profileController->generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3.75_ft, 0_ft, 0_deg}}, "A");
    // 4 to 0.65
    Robot::profileController->generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.6_ft, 0_ft, 0_deg}}, "back2plat");
    //0.8181 
    Robot::turnController->generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.8181_ft, 0_ft, 0_deg}}, "90deg");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
    
}