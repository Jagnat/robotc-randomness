#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     rightb,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     rightf,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     leftf,         tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     leftb,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     sweeper,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     lift,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    hookl,                tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    hookr,                tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    flap,                 tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    autoarm,              tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    fflap,                tServoStandard)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)

#include "JoystickDriver.c"

/*
	This autonomous program drives off the ramp and
	scores into the low goal with a specialized
	servo arm, then uses the main lifting system to
	score into the medium goal, before towing the
	medium goal into the parking zone.
*/

// Macro function for setting base motor power
void drive(int left, int right)
{
	motor[rightf] = right;
	motor[rightb] = right;
	motor[leftf] = left;
	motor[leftb] = left;
}

// In case we need individual control
void drive4(int lf, int lb, int rf, int rb)
{
	motor[rightf] = rf;
	motor[rightb] = rb;
	motor[leftf] = lf;
	motor[leftb] = lb;
}

// Linear interpolate - used for the power ramping function
float lerp(float a, float b, float x)
{
	return (1 - x) * a + x * b;
}

// ramp - Function that interpolates between starting and ending
// power over time
// Params: leftS - left starting value
// leftE - left ending value
// rightS - right starting value
// rightE - right ending value
// ms - time in milliseconds to interpolate
void ramp(int leftS, int leftE, int rightS, int rightE, int ms)
{
	ClearTimer(T2);
	while (time1[T2] < ms)
	{
		float x = (float)time1[T2] / (float)ms;
		int l = (int)(lerp(leftS, leftE, x) + 0.5);
		int r = (int)(lerp(rightS, rightE, x) + 0.5);
		drive(l, r);
		wait1Msec(1);
	}
}

task main()
{
	servo[hookl] = 255;
	servo[hookr] = 0;
	servo[flap] = 255;
	servo[fflap] = 255;
	servo[autoarm] = 0;

	//waitForStart();

	// Initialize hooks to leave space for box movement
	servo[hookl] = 140;
	servo[hookr] = 100;

	// bFloatDuringInactiveMotorPWM sets whether or not
	// our motors should hold their position at 0,
	// or float.

	// Move to edge of ramp,
	// Then let momentum of robot drag us down the ramp
	bFloatDuringInactiveMotorPWM = true;
	ramp(0, 80, 0, 80, 700);
	drive(0, 0);

	// Wait until we have rolled off the ramp
	wait1Msec(4000);

	// Assign the motors to hold their positions again
	bFloatDuringInactiveMotorPWM = false;

	// Gradually turn, while avoiding the medium goal
	ramp(0, 10, 0, 70, 300);
	drive(10, 70);
	wait1Msec(700);

	// Head diagonally towards the opposing low zone
	drive4(80, 50, 80, 50);
	wait1Msec(1750);

	// Turn so we are facing the low goal
	drive4(80, 70, -10, -10);
	wait1Msec(650);

	// Drive towards the low goal, float so that
	// our back motors can be disabled (no encoders)
	// but can still move
	// bFloatDuringInactiveMotorPWM = false;
	drive4(30, 30, 30, 30);
	wait1Msec(1400);
	// bFloatDuringInactiveMotorPWM = false;

	// Stop
	drive(0, 0);

	// Deposit auto arm ball
	servo[autoarm] = 255;
	wait1Msec(2000);
	servo[autoarm] = 127;
	wait1Msec(400);

	// Back up from the low goal
	drive(-40, -40);
	wait1Msec(1300);

	// Turn so that our back is facing the medium goal
	drive4(-80, -80, 40, 40);
	wait1Msec(1200);

	// Back into the medium goal
	drive(-40, -40);
	wait1Msec(1300);
	drive(0, 0);

	// Deposit our main lifting system
	motor[lift] = 75;
	wait1Msec(3500);
	motor[lift] = 0;

	servo[flap] = 128;
	wait1Msec(1000);

	// Hook onto the rolling goal
	servo[hookl] = 50;
	servo[hookr] = 185;
	wait1Msec(600);

	// turn and drive towards the low zone
	drive(70, -70);
	wait1Msec(1700);

	drive(-70, -70);
	wait1Msec(2500);

	servo[hookl] = 140;
	servo[hookr] = 100;

	wait1Msec(2500);
	drive(0, 0);
}
