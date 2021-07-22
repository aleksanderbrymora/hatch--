/*
  Environment.h - A library that uses DHT11 sensor to read the temperature
  and the humidity of the environment
*/

#ifndef Environment_h
#define Environment_h

#include <Arduino.h>
#include <DHT.h>
#include <Constants.hpp>
#include <Screen.h>

class Environment
{
public:
  Environment(Screen *screen);
  void update();
  void zero_time();

private:
  float temperature;
  float humidity;
  unsigned long t;
  unsigned long t_0;
  DHT _dht = DHT(Pins::dht, DHT11);
  Screen *_screen;
};

#endif