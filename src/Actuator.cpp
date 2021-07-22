#include <Actuator.h>
#include <Arduino.h>
#include <Constants.hpp>

Actuator::Actuator(int open_pin, int close_pin)
{
  _open_pin = open_pin;
  _close_pin = close_pin;
  pinMode(_open_pin, OUTPUT);
  pinMode(_close_pin, OUTPUT);
};

Actuator::Actuator()
{
  _open_pin = Pins::hatch_open_relay;
  _close_pin = Pins::hatch_close_relay;
  pinMode(_open_pin, OUTPUT);
  pinMode(_close_pin, OUTPUT);
}

void Actuator::close()
{
  digitalWrite(_open_pin, LOW);
  digitalWrite(_close_pin, HIGH);
}

void Actuator::open()
{
  digitalWrite(_open_pin, HIGH);
  digitalWrite(_close_pin, LOW);
}

void Actuator::stop()
{
  digitalWrite(_open_pin, HIGH);
  digitalWrite(_close_pin, HIGH);
}
