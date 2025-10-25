// This is a short example on how to make a function that executes every N seconds without stopping everything else.

#include <time.h>

static constexpr int TEN_SECONDS{10};
static constexpr int TWENTY_SECONDS{20};

void setup() {}

static time_t ten_second_timer = time(NULL);
static time_t twenty_second_timer = time(NULL);

void loop() {
    const time_t current_time = time(NULL);

    if (current_time - ten_second_timer >= TEN_SECONDS) {
        ten_second_timer = current_time;
        // this will run every 10 seconds
        do_something_rarely();
    }

    if (current_time - twenty_second_timer >= TWENTY_SECONDS) {
        twenty_second_timer = current_time;
        // this will run every 20 seconds
        do_something_else();
    }

    // this will run constantly, never waiting for the 10 and 20 seconds timers to fire
    do_something_constantly();
}

// Use std::chrono if you prefer, this is just an example