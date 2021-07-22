/*
  Screen.h - lib for outputting info to the OLED Screen
*/
#ifndef Screen_h
#define Screen_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Screen
{
public:
  void init();
  void display_env(float t, float h);
  void display_state(String status);

private:
  Adafruit_SSD1306 _display;
  unsigned long t;   // todo
  unsigned long t_0; // todo
};

#endif