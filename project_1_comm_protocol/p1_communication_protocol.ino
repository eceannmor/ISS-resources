#define RIGHT_MOTOR_FWD A0
#define RIGHT_MOTOR_REV A1
#define RIGHT_MOTOR_ENABLE 5

#define LEFT_MOTOR_FWD A3
#define LEFT_MOTOR_REV A2
#define LEFT_MOTOR_ENABLE 6

#define ENCODER_INT_L 3
#define ENCODER_INT_R 2

/***************************************************************************************
* this is just a guide, you are free to change the signatures / add / remove functions
************************************************************************************** */

void process_serial();
void set_speed(bool motor, int speed);
// calculate the distance by measuring the number of interrupts interrupts
// you can hard-code the values
void move_motor(bool motor, double distance);
void drive(double distance);
void rotate(int angle);
// try to approximate the distance traveled by the robot using the encoder values
void print_distance_traveled();



void setup() {
    // open communication
    // set pin modes
    // attach interrupts

    // if using a hard-coded path, put it here
}

void loop() {
    // if not using a hard-coded path, get the input from serial
}