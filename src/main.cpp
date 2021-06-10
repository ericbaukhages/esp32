/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include "Arduino.h"
#include "segment.h"

#define CYCLE_BUTTON 34

int counter;

void setup()
{
	pinMode(CYCLE_BUTTON, INPUT);
	segment::initialize();

	counter = 0;
}

void loop()
{
	int cycleButtonState = digitalRead(CYCLE_BUTTON);

	if (cycleButtonState == HIGH)
	{
		counter++;
		delay(150);
	}

	if (counter >= 16)
	{
		counter = 0;
	}

	segment::clear();
	segment::update(counter);
}
