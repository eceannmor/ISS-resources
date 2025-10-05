// this defines "ENCODER_PIN_R/L" as a preprocessor macro the preprocessor runs
// before the compiler and replaces all occurrences of "ENCODER_PIN_R/L"
// with 2/3
#define ENCODER_PIN_R 2
// for anyone wanting to write "proper c++", replace the directive with a
// static constexpr variable
static constexpr int ENCODER_PIN_L = 3;

// this can be dedclared both out of scope of any function (can be read from
// anywhere), or in the scope of the main loop (only available to the loop)
char readByte;

// https://en.cppreference.com/w/cpp/types/integer.html
uint16_t counter_r; // arduino supports C standard library types
uint16_t counter_l;

void inc_r() {
    counter_r++;
}

void inc_l() {
    counter_l++;
}

void setup() {
    // Start serial communication at a rate of 9600 baud
    Serial.begin(9600);

    // attachInterrupt() requires a ""void(*func)()"" ?
    // This is a pointer to a "void ..()" function, like inc_r above
    // How to read complicated types:
    // https://cseweb.ucsd.edu/~ricko/rt_lt.rule.html
    attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_R), inc_r, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_L), inc_l, RISING);
}

void printCounters() {
    // because we declared the counters at the global score, we can access the 
    // values from anywhere
    Serial.print("Counter values: Left=");
    Serial.print(counter_l);
    Serial.print(" Right=");
    Serial.print(counter_l);
    Serial.println();
}

void loop() {
    if (Serial.available() > 0) {
        // first byte (character) of the command
        readByte = Serial.read();

        if ('m' == readByte) {
            // skip one byte (space character)
            Serial.read();
            int value = Serial.parseInt();
            // execute Move command here
        } else if ('s' == readByte) {
            /*  no need to read any more data
                code to stop all motors goes here */
        } /*else if (... all other commands ...) {
            ... 
        }*/
    }
}