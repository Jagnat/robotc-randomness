#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTServo)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  mtr_S1_C1_1,     frontR,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     frontL,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     backR,         tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     backL,         tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Servo,  srvo_S1_C3_1,    hookbR,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    hookbL,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_1,    hookfR,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    hookfL,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    autoarm,              tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo12,              tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "hitechnic-gyro.h"

/*
This program makes the robot drive off the ramp,
hook onto both the low and medium goals,
and make a gyro-monitored turn towards the low
zone, and deposit both of the goals into the low zone.
*/

void drive(int l, int r)
{
	motor[frontL] = l;
	motor[backL] = l;
	motor[frontR] = r;
	motor[backR] = r;
}

void drive4(int lf, int lb, int rf, int rb)
{
	motor[frontR] = rf;
	motor[backR] = rb;
	motor[frontL] = lf;
	motor[backL] = lb;
}

// Linear interpolate - used for the power ramping function
float lerp(float a, float b, float x)
{
	return (1 - x) * a + x * b;
}

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

void mFloat(bool b)
{
	bFloatDuringInactiveMotorPWM = b;
}

task main()
{
	/*
	Hook servo values
	BACK UP
	right - 40
	left - 210
	DOWN
	r - 210
	l - 40

	FRONT UP
	r - 205
	l - 60
	DOWN
	r - 60
	l - 205
	*/
	// initialize servos
	servo[hookbR] = 40;
	servo[hookbL] = 210;
	servo[hookfR] =205;
	servo[hookfL] = 60;
	servo[autoarm] = 255;

	waitForStart();

	mFloat(true);
	ramp(0, 80, 0, 80, 500);
	drive(0, 0);
	wait1Msec(3500);

	mFloat(false);

	ramp(0, -20, 0, 80, 300);
	wait1Msec(600);

	drive(0, 0);
	wait1Msec(200);

	drive(50, 50);
	wait1Msec(1000);

	drive(0, 0);
	wait1Msec(200);

	drive(70, -20);
	wait1Msec(700);

	drive(50, 50);
	wait1Msec(1800);

	drive(0, 0);

	servo[autoarm] = 0;
	wait1Msec(700);
	servo[autoarm] = 130;
	wait1Msec(300);

	// hook onto 30cm
	drive(-10, -10);
	wait1Msec(200);
	servo[hookfR] = 60;
	servo[hookfL] = 205;
	wait1Msec(600);

	// Drive backward and turn towards medium goal
	drive(-35, -35);
	wait1Msec(1100);
	drive(-70, 70);
	wait1Msec(800);
	drive(-50, -50);
	wait1Msec(1500);

	// Hook onto medium goal
	drive(0, 0);
	wait1Msec(200);
	drive(10, 10);
	wait1Msec(200);
	servo[hookbR] = 210;
	servo[hookbL] = 40;
	wait1Msec(500);

	// Drive forward and turn
	drive(70, 70);
	wait1Msec(400);

	// Integrate gyroscope data - primitive, but it works
	HTGYROstartCal(gyro);
	float sum = 0;
	ClearTimer(T2);
	drive(-70, 70);
	while (time1[T2] < 1500 && abs(sum) <= 80)
	{
		float current = HTGYROreadRot(gyro);
		current /= 100.0;
		sum += current;
		wait1Msec(10);
	}

	// Drive towards low zone and stop
	drive(70, 70);
	wait1Msec(2500)
	drive(70, -70);
	wait1Msec(600);
	drive(70, 70);
	wait1Msec(1500);
	drive(0, 0);

	servo[hookfR] = 205;
	servo[hookfL] = 60;
	wait1Msec(500);

	drive(-35, -35);
	wait1Msec(600);
	drive(-70, 70);
	wait1Msec(1600);
	drive(-50, -50);
	wait1Msec(1200);
}
