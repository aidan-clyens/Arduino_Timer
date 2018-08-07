/***********************************************************/
/*    Timer
/*
/*    This is an Arduino Timer library for uses such as
/*    waiting, or flashing an LED without using the standard
/*    Arduino 'delay' function and disrupting the rest of
/*    the program.
/*
/*    Aidan Clyens
/*    July  18, 2018
/***********************************************************/
#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"

class Timer {
  public:
    Timer();
    ~Timer();

    //  LED flash
    void initiate_pulse(int const &, int const &);
    void update_pulse();
    //  Wait
    bool wait(int const &);
    void clear();

  private:
    int led_state;
    int led_pin;
    int pulse_period;
    unsigned long previous_millis;
    bool initial_wait;
};

/***************************************
*           Constructors
****************************************/
/*
 * Timer Constructor
 */
Timer::Timer() {
  initial_wait = false;
}

/*
 * Timer Destructor
 */
)
Timer::~Timer() {
  //  Empty
}

/***************************************
*           Public Functions
****************************************/
/*
 * initiate_pulse
 * This function is called once when setting up a Timer object.
 * It associates the Timer with a pin number and a time period.
 */
void Timer::initiate_pulse(int const &pin, int const &period) {
  previous_millis = millis();
  led_pin = pin;
  pulse_period = period;
  led_state = HIGH;
  digitalWrite(led_pin, led_state);
}

/*
 * update_pulse
 * This function is called after initiate_pulse whenever you want
 * a pulse on the pin.
 */
void Timer::update_pulse() {
  unsigned long current_millis = millis();

  if (current_millis - previous_millis > pulse_period) {
    led_state = !led_state;
    digitalWrite(led_pin, led_state);

    previous_millis = current_millis;
  }
}

/*
 * wait
 * Called while in a loop, this function returns true when the
 * entered time period has passed.
 */
bool Timer::wait(int const &period) {
  unsigned long current_millis = millis();

  if (!initial_wait) {
    previous_millis = current_millis;
    initial_wait = true;
  }

  if (current_millis - previous_millis > period) {
    initial_wait = false;
    return true;
  }

  return false;
}

/*
 * clear
 * Reset a Timer being used for the wait function.
 */
void Timer::clear() {
  previous_millis = 0;
  initial_wait = false;
}
