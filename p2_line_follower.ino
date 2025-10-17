#define RIGHT_MOTOR_IN1 A0
#define RIGHT_MOTOR_IN2 A1
#define RIGHT_MOTOR_ENABLE 5

#define LEFT_MOTOR_IN1 A2
#define LEFT_MOTOR_IN2 A3
#define LEFT_MOTOR_ENABLE 6

/***************************************************************************************
* this is just a guide, you are free to change the signatures / add / remove functions
************************************************************************************** */

void process_serial();  // process serial input
void PID();             // process PID control

class Motor {
    int pinFwd;
    int pinRev;
    int pinPow;
    
    public:
        init(); // <--- initialise the motor. Set pins to output
        set_speed(int speed);
        set_direction(bool forward);
        stop();

        Motor(int pinFwd, int pinRev, int pinPow); // <--- pay attention. this is a constructor
};

// implement the constructor and methods here


// initialise the motors with the correct pins
Motor left;
Motor right;

setup() {
    Serial.begin(9600);

    left.init();
    right.init();

    // calibrate sensors (see TRSensorsExample.ino)
}

loop() {
    // process serial input
    // read the sensors and adjust the motor speeds (see TRSensorsExample.ino)
    // this loop should run around 10 times per second, make sure that no function stalls
}