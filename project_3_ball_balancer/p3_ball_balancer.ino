/***************************************************************************************
* this is just a guide, you are free to change the signatures / add functions
************************************************************************************** */

#define MOTOR_PIN 9
#define SENSOR_PIN A0

// https://docs.arduino.cc/learn/electronics/servo-motors/
#include <Servo.h>

// Process serial input. 
// When sending an integer position (e.g. "10"), the balancer should adjust the ball position
void process_serial();

// Process PID control.
// Same rules for dt and regular timings as Project 2
void PID(); 

setup() {
    Serial.begin(9600);
}

loop() {
    // 1. Process serial input, alter balancing position if neccesary
    // 2. At regular intervals, update PID
}