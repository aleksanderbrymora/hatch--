#include <Arduino.h>
#include <DHT.h>

#include "Environment.h"
#include "Constants.hpp"
#include "Screen.h"

Environment::Environment(Screen *screen)
{
  DHT _dht(Pins::dht, DHT11);
  temperature = 0;
  humidity = 0;
  t_0 = millis();
  t = t_0;
  _dht.begin(); // starting humidity sensor
  _screen = screen;
}

/**
 * @brief Reads the humidity and temperature with the DHT sensor
 * and updates the OLED screen with the data
 */
void Environment::update()
{
  if (t - t_0 >= Time::env_check_frequency)
  {
    float h = _dht.readHumidity();
    float t = _dht.readTemperature();

    if (!isnan(h))
    {
      humidity = h;
    }

    if (!isnan(t))
    {
      temperature = t;
    }

    _screen->display_env(t, h);
    t_0 = millis();
    t = t_0;
  }
  else
  {
    t = millis();
  }
}

void Environment::zero_time()
{
  t_0 = millis();
  t = t_0;
}