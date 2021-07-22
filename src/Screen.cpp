#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Screen.h>
#include <Constants.hpp>
#include <Environment.h>

Screen::Screen()
{
  Adafruit_SSD1306 _display(Screen_params::width, Screen_params::height, &Wire, Screen_params::oled_reset);
  if (!_display.begin(SSD1306_SWITCHCAPVCC, Screen_params::screen_address))
  {
    Serial.println(F("SSD1306 allocation failed"));
  }
  _display.clearDisplay();
  _display.setCursor(0, 20);
  _display.setTextSize(3);
  _display.setTextColor(WHITE);
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
  _display.clearDisplay();
  _display.print(state);
  _display.display();
}

// todo add a 10s delay for the env check
// void signal_state(String state_name)
// {
//   // making sure the state is shown for the 10 ish seconds
//   t_0_env_check = millis();
//   t_env_check = t_0_env_check;
//   display.clearDisplay();
//   display.print(state_name);
//   display.display();
// }