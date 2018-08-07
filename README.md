# Timer

## Getting Started
1. Move the **Timer** folder to your Arduino Libraries folder (e.g. **Documents/Arduino/libraries**).
2. Use `#include <Timer.h>` at the top of your sketch or click **Sketch -> Include Library -> Timer**.

## Functionality
Constructor:
- Default Constructor

LED Pulse Functions:
- void initiate_pulse
- void update_pulse

Wait Functions:
- bool wait
- void clear

## Examples
### Pulse LED
```cpp
//  Declare Timer object as a global variable
Timer led_timer;

void setup() {
    //  Set the LED pin to 13 and the period to 1 second (1000 ms)
    led = 13;
    period = 1000;
    Call initiate_pulse once with the LED pin and period in milliseconds as arguments    
    led_timer.initiate_pulse(led, timer)
}

void loop() {
    //  Call update_pulse in a loop to flash the LED with the given period
    led_timer.update_pulse();
}
```

### Wait
```cpp
Timer delay_timer;

void setup() {
    //  Empty
}

void loop() {
    //  Set the period to 10 seconds (10000 ms)
    period = 10000;
    //  Use this Timer to wait until a given time period has passed to do something
    if (delay_timer.wait(period)) {
        //  Do stuff
    }
}
```

## Author
Copyright 2018 Aidan Clyens
