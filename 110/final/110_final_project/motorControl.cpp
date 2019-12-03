#include "motorControl.h"

extern Romi_Motor_Power left_motor;
extern Romi_Motor_Power right_motor;

extern QTRSensorsRC qtrc;
extern unsigned int lineSensorValues[TOTAL_LS_SENSORS];

// Function:    stopMotors
// Description: stops the wheel motors
// Inputs:      none
// Returns:     none
void stopMotors()
{
  left_motor.setSpeed(0);
  right_motor.setSpeed(0);

  Serial.println("stopped");
}

void driveStraight(int targetSpeed, int distance) {
  driveStraight(targetSpeed, distance, NULL);
}

void driveStraight(int targetSpeed, int distance, int (*cond)()) {
  // Reset the encoders and get starting counts for left and right
  resetRightEncoderCnt();
  int start_angle_left = getEncoderLeftCnt();
  int start_angle_right = getEncoderRightCnt();

  int leftSpeed = targetSpeed;
  int rightSpeed = targetSpeed;

  if (distance != -1) {
    // disable both motors
    left_motor.disableMotor();
    right_motor.disableMotor();
  }

  // set both motors to forward
  left_motor.directionForward();
  right_motor.directionForward();
  
  // set speed for both motors
  left_motor.setSpeed(leftSpeed);
  right_motor.setSpeed(rightSpeed);

  // enable both motors
  left_motor.enableMotor();
  right_motor.enableMotor();
  
  // These angles must be kept equal as the robot drives forward
  int angle_left = getEncoderLeftCnt() - start_angle_left;
  int angle_right = getEncoderRightCnt() - start_angle_right;
  
  // -1 distance indicates that the robot should drive until cond() is not met
  while (angle_left < distance || distance == -1) {
    wait(10);
    angle_left = getEncoderLeftCnt() - start_angle_left;
    angle_right = getEncoderRightCnt() - start_angle_right;
    

    if (angle_left > angle_right) {
      // Let the right wheel catch up to the left wheel
      leftSpeed = targetSpeed - 1;
      rightSpeed = targetSpeed + 1;
    }
    else {
      // Let the left wheel catch up to the right wheel
      leftSpeed = targetSpeed + 1;
      rightSpeed = targetSpeed - 1;
      ;
    }
    
    // set speed for both motors
    left_motor.setSpeed(leftSpeed);
    right_motor.setSpeed(rightSpeed);

    /* Break if the condition is not met */
    if (cond) {
      if (!cond())
        break;
    }
  }

  if (distance != -1)
    stopMotors();
}

void driveInches(int speed, int inches) {
  driveStraight(speed, inches * COUNTS_PER_INCH);
}


// Function:    turnLeft
// Description: set motor speed so robot turns to the left
// Inputs:      speed - the speed the robot will turn, 1=slow, 255=fast
// Returns:     none
void turnLeft(int speed)
{
  // validate the speed value
  if (speed < MIN_SPEED) speed = MIN_SPEED;
  if (speed > MAX_SPEED) speed = MAX_SPEED;

  // display the function we are in and its values
  // disable both motors
  left_motor.disableMotor();
  right_motor.disableMotor();

  // set left motor backward and right motor forward
  left_motor.directionBackward();
  right_motor.directionForward();
  
  // set speed for both motors
  left_motor.setSpeed(speed);
  right_motor.setSpeed(speed);

  // enable both motors
  left_motor.enableMotor();
  right_motor.enableMotor();
  
}

int absdiff(int i, int j) {
  if (i < 0)
    i = -1 * i;
  if (j < 0)
    j = -1 * j;
  
  if (i < j)
    return j - i;
  return i - j;
}

void rightAngle(int leftCount, int speed)
{
  if (speed < 0)
    turnRight(speed * -1);
  else
    turnLeft(speed);
  int startRight = getEncoderRightCnt();
  int currentRight = startRight;

  int diff = absdiff(currentRight, startRight);
  
  while (absdiff(currentRight, startRight) < leftCount)
  {
    currentRight = getEncoderRightCnt();
  }
  stopMotors();
}

// Function:    turnRight
// Description: set motor speed so robot turns to the right
// Inputs:      speed - the speed the robot will turn, 1=slow, 255=fast
// Returns:     none
void turnRight(int speed)
{
  // validate the speed value
  if (speed < MIN_SPEED) speed = MIN_SPEED;
  if (speed > MAX_SPEED) speed = MAX_SPEED;

  // disable both motors
  left_motor.disableMotor();
  right_motor.disableMotor();

  // set left motor forward and right motor backward
  left_motor.directionForward();
  right_motor.directionBackward();
  
  // set speed for both motors
  left_motor.setSpeed(speed);
  right_motor.setSpeed(speed);

  // enable both motors
  left_motor.enableMotor();
  right_motor.enableMotor();
}

void bck(int speed) {
   // validate the speed value
  if (speed < MIN_SPEED) speed = MIN_SPEED;
  if (speed > MAX_SPEED) speed = MAX_SPEED;

  // disable both motors
  left_motor.disableMotor();
  right_motor.disableMotor();

  // set left motor forward and right motor backward
  left_motor.directionBackward();
  right_motor.directionBackward();
  
  // set speed for both motors
  left_motor.setSpeed(speed);
  right_motor.setSpeed(speed);

  // enable both motors
  left_motor.enableMotor();
  right_motor.enableMotor();
}
