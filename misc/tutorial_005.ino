#include <stdio.h>
int put(char c, FILE *f) {
  Serial.write(c);
  return 0;
}

void fix_printf() {
  fdevopen(&put, 0);
}

#include "TRSensors.h"

constexpr int num_sensors = 5;
unsigned int sensorValues[num_sensors];

TRSensors trs = TRSensors();

void setup() {
  Serial.begin(9600);
  fix_printf();
  
  Serial.println("Calibration started");
  for (int i = 0; i < 500; i++) {
    trs.calibrate();
  }
  Serial.println("Calibration ended");

  Serial.println("Min values:");
  for (int i = 0; i < 5; i++ ) {
    printf("%d ", trs.calibratedMin[i]);
  }
  Serial.println();
  
  Serial.println("Max values:");
  for (int i = 0; i < 5; i++ ) {
    printf("%d ", trs.calibratedMax[i]);
  }
  Serial.println();

}

void loop() {
  int position = trs.readLine(sensorValues);
  printf("Line read: %d\n", position);
  delay(250);
}
