/*
  Debounce.h - a library used for debouncing a button
*/

#ifndef Debounce_btn_h
#define Debounce_btn_h

#include <Arduino.h>
#include "Constants.hpp"

/**
 * @brief State machine class used for debouncing a press action on real-life button
 * @param pin a pin to which the button is connected
 */
class DebounceBtn
{
private:
  int _pin;                 // a pin to which button is connected
  button_states prev_state; // previous state of the button
  int val_button;           // current value on the button
  unsigned long t;          // time since the button was pressed
  unsigned long t_0;        // time when the button was pressed

public:
  button_states state; // holds current state of the button
  DebounceBtn(int pin);
  void check();
};

#endif