#include "api.h"

class Drive {
public:
  Drive(int portLeftFront, int portLeftBack, int portRightFront,
        int portRightBack);
  void moveDrive();
  void moveFrontLift();
  void moveBackLift();
  void moveClamp();

private:
};
