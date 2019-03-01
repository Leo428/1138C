#include "userincludes/subsystems/collector.hpp"

okapi::Motor * Collector::ballCollector = nullptr;

Collector::Collector() {
    ballCollector = new okapi::Motor(RobotStates::INTAKE_PORT);
    ballCollector->setGearing(okapi::AbstractMotor::gearset::green);
}

void Collector::collectBalls() {
    ballCollector->move(127);
}

void Collector::outBall() {
    ballCollector->move(-127);
}

void Collector::stopCollector() {
    ballCollector->move(0);
    // ballCollector->moveVoltage(0);
}
