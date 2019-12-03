// ===========================================================
//
// Lab9_Sensor.ino  
// Description: Robot sensor tester
// Name: <team member names here>
// Date: <today's date here>
// Class: CMPE-110
// Section: <Lab: section, day, and time here>
//
// ===========================================================
//
#include "motorControl.h"
#include <stdarg.h>
#include <stdio.h>

// Define the motors
Romi_Motor_Power left_motor;
Romi_Motor_Power right_motor;

// Define the bump switches
Bump_Switch      bump_sw[6];

QTRSensorsRC qtrc;
unsigned int lineSensorValues[TOTAL_LS_SENSORS];

void setup() 
{ 
  // setup serial output
  Serial.begin(19200);
  Serial.println("Welcome to my sensor tester!");

  // setup start button
  pinMode(BUTTON_PIN, INPUT_PULLUP); // setup 'start' button so it is LOW when pressed
  
  // setup LED pins to be used as outputs
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  // setup left and right motors
  left_motor.begin(MOTOR_L_SLP_PIN, MOTOR_L_DIR_PIN, MOTOR_L_PWM_PIN);
  right_motor.begin(MOTOR_R_SLP_PIN, MOTOR_R_DIR_PIN, MOTOR_R_PWM_PIN);

  // setup encoder pins
  setupEncoder(ENCODER_ELB_PIN, ENCODER_ELA_PIN, ENCODER_ERB_PIN, ENCODER_ERA_PIN);

  // setup the bump switches
  bump_sw[0].begin(BSW_PIN_1);
  bump_sw[1].begin(BSW_PIN_2);
  bump_sw[2].begin(BSW_PIN_3);
  bump_sw[3].begin(BSW_PIN_4);
  bump_sw[4].begin(BSW_PIN_5);
  bump_sw[5].begin(BSW_PIN_6);

  // setup line sensors
  unsigned char pins[] = {LS_PIN_1, LS_PIN_2, LS_PIN_3, LS_PIN_4, LS_PIN_5, LS_PIN_6, LS_PIN_7, LS_PIN_8};
  qtrc.init(pins, TOTAL_LS_SENSORS);

  // set the line sensor IR pins to HIGH
  pinMode(LS_IR_PIN_ODD, OUTPUT);
  pinMode(LS_IR_PIN_EVEN, OUTPUT);
  digitalWrite(LS_IR_PIN_EVEN, HIGH);
  digitalWrite(LS_IR_PIN_ODD, HIGH);

  // reset the encoder counts
  clearEncoders();
}

#define SPEED 20

/* Wait for the robot to reach a line */
int waitForLine() {
  return !getLineWeight();
}

void loop()
{
  pressToStart();
  
  /* Move forward 31 inches to the first corner */
  driveInches(SPEED, 31);
  wait(128);

  /* Turn right 90deg */
  rightAngle(161, -SPEED);
  wait(128);
  
  /* Move forward 31 inches to the first corner */
  driveInches(SPEED, 18);
  wait(128);
  
  /* Turn left 90deg */
  rightAngle(161, SPEED);
  wait(128);
  
  driveStraight(SPEED, -1, waitForLine);
  
  driveInches(SPEED, 2);
  wait(128);
  
  /* Turn left 120 degree to align to white line */
  rightAngle(214, SPEED);
  wait(128);

  followLine();
  wait(128);
  
  /* Turn left 90deg */
  rightAngle(161, SPEED);
  wait(128);

  /* Move off the line */
  driveInches(SPEED, 2);

  /* Wait for finish line */
  driveStraight(SPEED, -1, waitForLine);

  /* Move the robot across the finish line */
  driveInches(SPEED, 9);
  stopMotors();
}

// Function:    pressToStart
// Description: wait for the 'Start' button to be pressed
// Inputs:      none
// Returns:     none
// 
void pressToStart()
{
  unsigned long startTime;
  bool pressed = false;

  Serial.println(""); // print blank line
  Serial.println("Waiting for 'Start' button to be pressed...");

  // keep blinking LED until button is pressed
  while (!pressed)
  {
    // keep LED off for 1 sec, or until button is pressed
    digitalWrite(RED_LED_PIN, LOW);  // turn LED off
    startTime = millis();        // get current time NOTE: the micros() counter will overflow after ~50 days
    while (!pressed && ((millis() - startTime) < 500))
    {
      // see if button is pressed (i.e. LOW)
      if (digitalRead(BUTTON_PIN) == LOW)
      {
        pressed = true;
      }
    }

    // keep LED on for 1 sec, or until button is pressed
    digitalWrite(RED_LED_PIN, HIGH); // turn LED on
    startTime = millis();        // get current time NOTE: the millis() counter will overflow after ~50 days
    while (!pressed && ((millis() - startTime) < 500))
    {
      // see if button is pressed (i.e. LOW)
      if (digitalRead(BUTTON_PIN) == LOW)
      {
        pressed = true;
      }
    }
  }

  // make sure LED is off
  digitalWrite(RED_LED_PIN, LOW);

  // give user a chance to remove their finger
  wait(1000);

  Serial.println(""); // print blank line
}

int getBump() {
  for (int i = 0; i < 6; i++) { /* Check every bump sensor until one is on */
    if (bump_sw[i].read() == 0)
      return 1;
  }

  return 0;
}

// Function:    wait
// Description: wait for the desired length of time, before this function returns
// Inputs:      duration - number of milliseconds before this function returns
// Returns:     none
void wait(int duration)
{
  Serial.println("ms");

  // wait for the desired time
  delay(duration);
}

// Function:    clearEncoders
// Description: clears encoder counts (this stops the motors)
// Inputs:      none
// Returns:     none
void clearEncoders()
{
  // clear the encoder counts
  resetLeftEncoderCnt();
  resetRightEncoderCnt();
}
