/*
  Lights.h - Lib for turning lights off and on
*/
#ifndef Lights_h
#define Lights_h

#include "Arduino.h"

class Lights
{
public:
  Lights();
  Lights(int pin);
  void on();
  void off();

private:
  int _pin;
};

#endif