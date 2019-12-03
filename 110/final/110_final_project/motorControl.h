#ifndef __MOTOR_CONTROL_H__
#define __MOTOR_CONTROL_H__

#include "globals.h"

#define COUNTS_PER_INCH 40

void stopMotors();
void turnLeft(int speed);
void rightAngle(int leftCount, int speed);
void turnRight(int speed);
void bck(int speed);
void driveStraight(int targetSpeed, int distance);
void driveStraight(int targetSpeed, int distance, int (*cond)());
void driveInches(int speed, int inches);

extern Romi_Motor_Power left_motor;
extern Romi_Motor_Power right_motor;

#endif
