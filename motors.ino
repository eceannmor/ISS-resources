// https://www.waveshare.com/wiki/AlphaBot
#define RIGHT_MOTOR_IN1 A0
#define RIGHT_MOTOR_IN2 A1
#define RIGHT_MOTOR_ENABLE 5 // HIGH to enable the motor. Alternatively, 
// the speed control pin

#define MOTOR_SWITCH_DELAY 20

void set_motor_direction(bool forward);
void set_motor_speed(int speed);

void setup() {
    pinMode(RIGHT_MOTOR_IN1, OUTPUT);
    pinMode(RIGHT_MOTOR_IN2, OUTPUT);
    pinMode(RIGHT_MOTOR_ENABLE, OUTPUT);
}

void set_motor_direction(bool forward) {
    // check the robot docs to see the exact pinout
    if (forward) {
        // setting first LOW, then HIGH + short delay when switching directions 
        // to avoid dynamic braking
        // See the driver datasheet in ./misc/L298.pdf
        digitalWrite(RIGHT_MOTOR_IN2, LOW);
        delay(MOTOR_SWITCH_DELAY);
        digitalWrite(RIGHT_MOTOR_IN1, HIGH);
    } else {
        digitalWrite(RIGHT_MOTOR_IN1, LOW);
        delay(MOTOR_SWITCH_DELAY);
        digitalWrite(RIGHT_MOTOR_IN2, HIGH);
    }
}

// you can output the PWM signal to either IN or ENABLE pins
// this implementation demonstrates the latter
void set_motor_speed(int speed) {
    speed = constrain(speed, 0, 255);
    analogWrite(RIGHT_MOTOR_ENABLE, speed);
}

void loop() {
    // forward for 3 seconds
    set_motor_speed(200);
    set_motor_direction(true);
    delay(3000);
    // backwards for 3 seconds
    set_motor_direction(false);
    delay(3000);
    // stop for 3 seconds
    set_motor_speed(0);
    delay(3000);
}
