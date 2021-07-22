#include <Arduino.h>

// My libs
#include "Hatch.h"
#include "Lights.h"
#include "Actuator.h"
#include "Constants.hpp"
#include "DebounceBtn.h"
#include "Environment.h"
#include "Screen.h"

// Initialising my libs
Lights lights;                                // Lights control
Actuator actuator;                            // Actuator control
DebounceBtn open_btn(Pins::open_button);      // Open Button control
DebounceBtn emergency_btn(Pins::open_button); // Emergency button control

Hatch::Hatch(Environment *env, Screen *screen)
{
  _screen = screen;
  _env = env;
}

void Hatch::closing()
{
  prev_state = state;
  t_0 = millis();
  t = t_0;
  actuator.close();
  lights.on();
  state = State::moving;
  _screen->display_state("Closing");
}

void Hatch::opening()
{
  prev_state = state;
  actuator.open();
  lights.on();
  state = State::moving;
  _screen->display_state("Opening");
}

void Hatch::closed()
{
  prev_state = state;
  actuator.stop();
  lights.off();
  state = State::rest;
  _screen->display_state("Closed");
}

void Hatch::rest()
{
  if (open_btn.state == button_states::triggered || emergency_btn.state == button_states::triggered)
  {
    state = State::opening;
  };
}

void Hatch::opening_error()
{
  prev_state = state;
  state = State::closing;
  _screen->display_state("Error opening");
}

void Hatch::closing_error()
{
  prev_state = state;
  state = State::opening;
  _screen->display_state("Error closing");
}

void Hatch::moving()
{
  if (prev_state == State::closing)
  {
    t = millis();
  }

  if (prev_state == State::closing && t - t_0 >= Time::time_to_close)
  {
    Serial.println("hatch closed signal");
    state = State::closed;
  }
  else if (hatch_error == HIGH)
  {
    if (state == State::closing)
    {
      state = State::closing_error;
    }
    else if (state == State::opening)
    {
      state = State::opening_error;
    }
  }
  else if (open_btn.state == button_states::triggered || emergency_btn.state == button_states::triggered)
  {
    if (prev_state == State::closing)
    {
      state = State::opening;
    }
    else if (prev_state == State::opening)
    {
      state = State::closing;
    }
  };
}

void Hatch::update_signals()
{
  Hatch::check_error();
  open_btn.check();
  emergency_btn.check();
}

void Hatch::check_error()
{
  hatch_error = !digitalRead(Pins::overcurrent);
}

void Hatch::run()
{
  Hatch::update_signals();

  switch (state)
  {
  case State::closing:
    Hatch::closing();
    break;
  case State::closed:
    Hatch::closed();
    break;
  case State::opening:
    Hatch::opening();
    break;
  case State::moving:
    Hatch::moving();
    break;
  case State::closing_error:
    Hatch::closing_error();
    break;
  case State::opening_error:
    Hatch::opening_error();
    break;
  case State::rest:
    Hatch::rest();
    break;
  }
}