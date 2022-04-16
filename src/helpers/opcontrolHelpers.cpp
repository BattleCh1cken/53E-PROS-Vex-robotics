#include "main.h"
int J1;
int J2;
int J3;
int J4;
bool L1;
bool L2;
bool R1;
bool R2;
bool X;
bool B;
bool Y;
bool A;
bool UP;
bool DOWN;
bool LEFT;
bool RIGHT;

void updateVars() {
   J2 = controller.get_analog(ANALOG_RIGHT_Y);
   J3 = controller.get_analog(ANALOG_LEFT_Y);
   L1 = controller.get_digital(DIGITAL_L1);
   L2 = controller.get_digital(DIGITAL_L2);
   R1 = controller.get_digital(DIGITAL_R1);
   R2 = controller.get_digital(DIGITAL_R2);
   X = controller.get_digital(DIGITAL_X);
   B = controller.get_digital(DIGITAL_B);
   Y = controller.get_digital(DIGITAL_Y);
   A = controller.get_digital(DIGITAL_A);
   UP = controller.get_digital(DIGITAL_UP);
   DOWN = controller.get_digital(DIGITAL_DOWN);
   LEFT = controller.get_digital(DIGITAL_LEFT);
   RIGHT = controller.get_digital(DIGITAL_RIGHT);
}

void printData() {
   while(true){
      //Update Controller screen
      //Update Brain Screen
      //Update Terminal
      std::cout << clamp.get_position(); 
      std::cout << std::endl;
      delay(500);
   }
}

void moveDrive() {
   leftFront.move(J3);
   leftBack.move(J3);
   rightFront.move(J2);
   rightBack.move(J2);
}

void moveFrontLift() {
   if (R2) {
      frontLift.move_velocity(100);
   }else if (R1) {
      frontLift.move_velocity(-100);
   }else {frontLift.move_velocity(0);
   }
}
void moveClamp() {
   if (L1) {
      clamp.move_velocity(100);
   }else if (L2) {
      clamp.move_velocity(-100);
   }else {clamp.move_velocity(0);
   }
}
