#include "Arduino.h"
#include "segment.h"

#define CYCLE_BUTTON_PIN 34

#define COUNTER_MIN 1
#define COUNTER_MAX 9
int counter;

void setup()
{
	pinMode(CYCLE_BUTTON_PIN, INPUT);
	segment::initialize();

	counter = COUNTER_MIN;
	segment::update(counter);
}

void loop()
{
	int cycleButtonState = digitalRead(CYCLE_BUTTON_PIN);

	// TODO: should this be replaced with an interrupt?
	if (cycleButtonState == HIGH)
	{
		counter++;
		delay(300);

		if (counter > COUNTER_MAX)
		{
			counter = COUNTER_MIN;
		}

		segment::clear();
		segment::update(counter);
	}
}
