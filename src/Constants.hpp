#ifndef Constants_h
#define Constants_h

namespace Pins
{
  // Pins out
  int const lights = 4;            // Relay controlling the leds
  int const hatch_open_relay = 5;  // Relay controlling hatch in opening direction
  int const hatch_close_relay = 6; // Relay controlling hatch in closing direction

  // Pins in
  int const open_button = 10;      // a button that opens/closes the hatch
  int const overcurrent = 11;      // a input from overcurrent protection board that indicates an error
  int const emergency_button = 12; // a button inside the cellar that will open the hatch
  int const dht = 8;               // humidity + temperature sensor
}

namespace Time
{
  unsigned long const time_to_close = 90000; // 90s - how much time does the hatch take to close
  int const bounce_delay = 10;               // tells how long should the button hold the HIGH value till its triggered (debounce time)
  int const env_check_frequency = 10000;     // how often should the environment be checked
}

namespace Screen_params
{
  int const width = 128;
  int const height = 64;
  int const oled_reset = 4;
  int const screen_address = 0x3C;
}

// Button states for state machine
enum button_states
{
  reset,     // one time, catch all condition
  start,     // checks value of button, if pressed moves on to `go`
  go,        // records the time of the press and moves on to wait
  wait,      // wait for the button to settle (debouncing)
  armed,     // makes sure trigger only happens once the button is released
  triggered, // one time pulse of button
};

enum State
{
  closing,       // one time setter for closing the hatch
  closed,        // rest state for the hatch
  opening,       // one time setter for opening the hatch; its the default value
  moving,        // used after the closing and opening state
  closing_error, // one time trigger for overcurrent protection, transitions to opening
  opening_error, // one time trigger for overcurrent protection, transitions to closing
  rest,          // after closed waiting for a button press
};

#endif