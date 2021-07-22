#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Screen.h"
#include "Constants.hpp"

void Screen::init()
{
  Serial.println("Initialising screen");
  _display = Adafruit_SSD1306(Screen_params::width, Screen_params::height, &Wire, Screen_params::oled_reset);
  if (!_display.begin(SSD1306_SWITCHCAPVCC, Screen_params::screen_address))
  {
    Serial.println(F("SSD1306 allocation failed"));
  }
  _display.clearDisplay();
  _display.setCursor(0, 20);
  _display.setTextSize(3);
  _display.setTextColor(WHITE);
  delay(2000);
  Serial.println("Screen Initialised");
}

void Screen::display_env(float t, float h)
{
  _display.clearDisplay();
  _display.print((int)h);
  _display.print("% ");
  _display.print((int)t);
  _display.println("C");
  _display.display();
}

void Screen::display_state(String state)
{
  Serial.println(state);
  _display.clearDisplay();
  _display.print(state);
  _display.display();
}