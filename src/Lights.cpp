#include <Arduino.h>
#include <Lights.h>
#include <Constants.hpp>

Lights::Lights(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

Lights::Lights()
{
  _pin = Pins::lights;
  pinMode(_pin, OUTPUT);
}

void Lights::off()
{
  digitalWrite(_pin, HIGH);
}

void Lights::on()
{
  digitalWrite(_pin, LOW);
}