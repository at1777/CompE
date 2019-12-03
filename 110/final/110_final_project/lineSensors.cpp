#include "lineSensors.h"
#include "motorControl.h"
#include "globals.h"

extern QTRSensorsRC qtrc;
extern unsigned int lineSensorValues[TOTAL_LS_SENSORS];

int getLineWeight() {
  qtrc.read(lineSensorValues);
  int found_line = 0;
  for (int i = 0; i < TOTAL_LS_SENSORS; i++) {
    if (lineSensorValues[i] < WHITE_THRESHOLD) {
      lineSensorValues[i] = 1;
      found_line = 1;
    }
    else
      lineSensorValues[i] = 0;
  }

  return found_line;
}

void followLine() {
  int speed = 20;

  int found_line = getLineWeight();

  // enable both motors
  left_motor.enableMotor();
  right_motor.enableMotor();
  left_motor.setSpeed(speed);
  right_motor.setSpeed(speed);
  left_motor.directionForward();
  right_motor.directionForward();

  int leftSpeed = speed;
  int rightSpeed = speed;
  
  while (found_line) {
    // Check if all are on
    int all_on = 1;
    for (int i = 0; i < TOTAL_LS_SENSORS; i++) {
      if (!lineSensorValues[i]) {
        all_on = 0;
        break;
      }
    }
    if (all_on) {
      /* Turn right */
      rightSpeed = 0;
      leftSpeed = speed + 10;
    }
    else if (lineSensorValues[7]) {
      /* Turn left */
      leftSpeed = 0;
      rightSpeed = speed + 5;
    }
    else if (lineSensorValues[0]) {
      /* Turn right */
      rightSpeed = 0;
      leftSpeed = speed + 5;
    }
    else {
      rightSpeed = speed;
      leftSpeed = speed;
    }

    
    if (getBump()) {
      stopMotors();
      while (getBump());
      wait(500); 
      left_motor.enableMotor();
      right_motor.enableMotor();
    }
    
    left_motor.setSpeed(leftSpeed);
    right_motor.setSpeed(rightSpeed);

    found_line = getLineWeight();
    wait(10);
  }

  stopMotors();
}
