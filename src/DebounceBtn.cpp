#include <Arduino.h>
#include <Constants.hpp>
#include <DebounceBtn.h>

DebounceBtn::DebounceBtn(int pin)
{
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void DebounceBtn::check()
{
  switch (state)
  {
  case button_states::reset:
    prev_state = state;
    state = button_states::start;
    break;

  case button_states::start:
    val_button = digitalRead(_pin);
    if (val_button == LOW)
    {
      prev_state = state;
      state = button_states::go;
    }
    break;

  case button_states::go:
    t_0 = millis();
    state = button_states::wait;
    break;

  case button_states::wait:
    val_button = digitalRead(_pin);
    t = millis();
    if (val_button == HIGH)
    {
      state = button_states::reset;
    }
    if (t - t_0 > Time::bounce_delay)
    {
      state = button_states::armed;
    }
    break;

  case button_states::triggered:
    // actual code
    state = button_states::reset;
    break;

  case button_states::armed:
    val_button = digitalRead(_pin);
    if (val_button == HIGH)
    {
      state = button_states::triggered;
    }
    break;
  }
}