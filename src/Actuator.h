/*
  Actuator.h - library for controlling the actuator for opening the hatch
*/
#ifndef Actuator_h
#define Actuator_h

#include "Arduino.h"

class Actuator
{
public:
  Actuator();
  Actuator(int open_relay_pin, int close_relay_pin);
  void open();
  void close();
  void stop();

private:
  int _open_pin;
  int _close_pin;
};

#endif