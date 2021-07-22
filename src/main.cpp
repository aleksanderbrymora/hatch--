#include <Arduino.h>

#include "Hatch/Hatch.h"
#include "Environment/Environment.h"
#include "Screen/Screen.h"

Screen screen;
Environment environment;
Hatch hatch;

void setup()
{
  Serial.begin(9600);
  screen.init();
  environment.init(&screen);
  hatch.init(&environment, &screen);
};

void loop()
{
  environment.update();
  hatch.run();
};