// External Libs
#include <Arduino.h>
#include <Hatch.h>
#include <Environment.h>

Screen screen;
Environment environment(&screen);
Hatch hatch(&environment, &screen);

void setup()
{
  Serial.begin(9600);
};

void loop()
{
  environment.update();
  hatch.run();
};