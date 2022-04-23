#include "main.h"

Drive::Drive(int portLeftFront, int portLeftBack, int portRightFront,
             int portRightBack) {
  Motor leftFront(portLeftFront);
  Motor leftBack(portLeftBack);
  Motor rightFront(portRightFront);
  Motor rightBack(portRightBack);
};
void Drive::moveDrive() {}

void Drive::moveClamp() {}

void Drive::moveFrontLift() {}

void Drive::moveBackLift() {}
