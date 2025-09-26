// This library is a modified version of QTRSensors
// https://github.com/pololu/qtr-sensors-arduino

// Add the library to the project
// Sketch -> Include Library -> Add .ZIP Library...

// Include the library 
#include "TRSensors.h"

// Initialise sensors
TRSensors trs = TRSensors();

// Calibrating the sensors
// This will poll each sensor 10 times
for (int i = 0; i < 10; i++) {
    trs.calibrate();
}

// Check the calibrated ranges 
Serial.print(trs.calibratedMin[sensorId])
Serial.print(trs.calibratedMax[sensorId])

// Get the values from the sensor 
const int num_sensors = 5;
unsigned int sensorValues[num_sensors];

// Stores the read values in sensorValues
trs.readCalibrated(sensorValues);

// Stores the read values in sensorValues AND estimates the position of the line
// Read the TRSensors.h comments for the formula for position
int position = trs.readLine(sensorValues);