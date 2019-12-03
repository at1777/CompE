#ifndef __GLOBALS_KARL_H__
#define __GLOBALS_KARL_H__

#include "Romi_Motor_Power.h"
#include "Robot_Pins_v1.h"
#include "Bump_Switch.h"
#include "QTRSensors.h"
#include "Encoder.h"

// 'Start' button
#define BUTTON_PIN PUSH2

// Available LED pins
#define RED_LED_PIN RED_LED
#define GREEN_LED_PIN GREEN_LED

// Define motor speeds
#define MAX_SPEED 100           // Fastest speed
#define MIN_SPEED 1             // Slowest speed

// Line sensor defines
#define TOTAL_LS_SENSORS 8
#define LS_IR_PIN_EVEN LS_PIN_IR
#define LS_IR_PIN_ODD 45

void wait(int duration);
int getBump();
void readLineSensors();

void getLineWeight(int* found_line);
void followLine();
void driveStaight(int targetSpeed, int distance);

#endif
