/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include "Arduino.h"
#include "segment.h"

void setup()
{
  initializeSegments();
}

void loop()
{
  for (int i = 0; i < 16; i++) {
    writeNumberToSegment(i);
    delay(1000);
    clearSegment();
  }
}
