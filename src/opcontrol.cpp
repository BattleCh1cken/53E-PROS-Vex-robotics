#include "main.h"
/*
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
         	controller.clear();
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

	while (true) {
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

		//move those motors
		leftFront.move(J3);
		leftBack.move(J3);
		rightFront.move(J2);
		rightBack.move(J2);
		}
	}
