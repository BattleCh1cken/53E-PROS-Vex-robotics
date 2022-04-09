#include "main.h"
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "eeeeeeeeeeeeeeeeeeee");

	pros::lcd::register_btn1_cb(on_center_button);
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
void competition_initialize() {}

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
void autonomous() {}

/**
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
	
	Controller master (E_CONTROLLER_MASTER);

	//Drive Train Motors
	Motor left_front (5, E_MOTOR_GEARSET_18, true);
	Motor left_back (6, E_MOTOR_GEARSET_18, true);

	Motor right_front (19, E_MOTOR_GEARSET_18, false);
	Motor right_back (20, E_MOTOR_GEARSET_18, false);

	//Lift Motors
		
	master.clear();
		int count = 0;
		bool isforward = true;
		bool is_back_lift_up = false;
		bool backGoingUp = false;
		bool frontGoingUp = true;
		bool clampGoingUp = false;
		int J1;
		int J2 = master.get_analog(ANALOG_RIGHT_Y);
		int J3 = master.get_analog(ANALOG_LEFT_Y);
		int J4;
		bool L1 = master.get_digital(DIGITAL_L1);
		bool L2 = master.get_digital(DIGITAL_L2);
		bool R1 = master.get_digital(DIGITAL_R1);
		bool R2 = master.get_digital(DIGITAL_R2);
		bool X = master.get_digital(DIGITAL_X);
		bool B = master.get_digital(DIGITAL_B);
		bool Y = master.get_digital(DIGITAL_Y);
		bool A = master.get_digital(DIGITAL_A);
		bool UP = master.get_digital(DIGITAL_UP);
		bool DOWN = master.get_digital(DIGITAL_DOWN);
		bool LEFT = master.get_digital(DIGITAL_LEFT);
		bool RIGHT = master.get_digital(DIGITAL_RIGHT);

	while (true) {
		J2 = master.get_analog(ANALOG_RIGHT_Y);
		J3 = master.get_analog(ANALOG_LEFT_Y);
		L1 = master.get_digital(DIGITAL_L1);
		L2 = master.get_digital(DIGITAL_L2);
		R1 = master.get_digital(DIGITAL_R1);
		R2 = master.get_digital(DIGITAL_R2);
		X = master.get_digital(DIGITAL_X);
		B = master.get_digital(DIGITAL_B);
		Y = master.get_digital(DIGITAL_Y);
		A = master.get_digital(DIGITAL_A);
		UP = master.get_digital(DIGITAL_UP);
		DOWN = master.get_digital(DIGITAL_DOWN);
		LEFT = master.get_digital(DIGITAL_LEFT);
		RIGHT = master.get_digital(DIGITAL_RIGHT);

	// 	if (R1)      front_lift.move_velocity(100);
	// 	else if (R2) front_lift.move_velocity(-100);
	// 	else         front_lift.move_velocity(0);
	//
	// 
	//
	// 	if (L1)      front_clamp.move_velocity(100);
	// 	else if (L2) front_clamp.move_velocity(-100);
	// 	else         front_clamp.move_velocity(0);
	//
	//

		
		// if (UP)      back_lift.move_velocity(50);
		// else if (DOWN) back_lift.move_velocity(-50);
		// else         back_lift.move_velocity(0);

	//
	// 	
	// 	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)){
	// 		frontGoingUp = !frontGoingUp;
	// 		front_lift.move_absolute(backGoingUp? 600 : 0,100);
	//
	// 	}
	// 
	// 	
	// 	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_A)){
	// 		backGoingUp = !backGoingUp;
	// 		back_lift.move_absolute(backGoingUp? 600 : 0,100);
	//
	// 	}
	// 	
		// 
		// 		//torque limiters
		// if (back_lift.get_torque() > 2) {
		// 	back_lift.move_velocity(0);
		// 	backGoingUp = !backGoingUp;
		// }
		// if (front_lift.get_torque() > 2) {
		// 	front_lift.move_velocity(0);
		// 	frontGoingUp = !frontGoingUp;
		// }
		//


		//move those motors
		left_front.move(J3);
		left_back.move(J3);
		right_front.move(J2);
		right_back.move(J2);



		delay(20);
		//print things within the brain's limits
		count++;
		if (!(count % 25)) {
		master.print(1,1,"%.3f",potato);
		}
	}
}
