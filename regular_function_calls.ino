// This is a short example on how to make a function that executes every N seconds without stopping everything else.

void setup() {}

static time_t timer_100ms = millis();
static time_t timer_1s = millis();

void loop() {
    const time_t current_time = millis();

    if (current_time - timer_100ms >= 100) { // timer for 100 ms
        timer_100ms = current_time;
        do_something();
    }

    if (current_time - timer_1s >= 1000) { // timer for 1 second
        timer_1s = current_time;
        do_something_else();
    }

    // this will run constantly, never waiting for timers to fire
    do_something_constantly();
}
// for higher precision use either micros() or std::chrono::steady_clock