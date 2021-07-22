/*
  Hatch.h - main lib that has the most important operations for controlling the hatch
*/

#ifndef Hatch_h
#define Hatch_h

#include <Arduino.h>

#include "Constants.hpp"
#include "Screen.h"
#include "Environment.h"

class Hatch
{
public:
  Hatch(Environment *env, Screen *screen);
  void run();

private:
  // State machine methods
  void closing();
  void opening();
  void rest();
  void closed();
  void opening_error();
  void closing_error();
  void moving();
  void check_error();

  // keeping state
  void update_signals();
  State state;
  State prev_state;
  int hatch_error = LOW;

  // Time for `closed` signal
  unsigned long t = 0;
  unsigned long t_0 = 0;

  // Libraries
  Environment *_env;
  Screen *_screen;
};

#endif