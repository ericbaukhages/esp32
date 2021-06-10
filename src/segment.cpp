#include "Arduino.h"
#include "segment.h"

#define LATCH_PIN 12
#define CLOCK_PIN 13
#define DATA_PIN 14

byte numberToSegments[] = {
	0b11111100, /* 0 */
	0b01100000, /* 1 */
	0b11011010, /* 2 */
	0b11110010, /* 3 */
	0b01100110, /* 4 */
	0b10110110, /* 5 */
	0b10111110, /* 6 */
	0b11100000, /* 7 */
	0b11111110, /* 8 */
	0b11100110, /* 9 */
	0b11101110, /* A */
	0b00111110, /* B */
	0b10011100, /* C */
	0b01111010, /* D */
	0b10011110, /* E */
	0b10001110, /* F */
};

void segment::initialize()
{
	pinMode(LATCH_PIN, OUTPUT);
	pinMode(DATA_PIN, OUTPUT);
	pinMode(CLOCK_PIN, OUTPUT);
}

void segment::update(byte number)
{
	// TODO: number needs to be 0 - 15 only for this segment display
	digitalWrite(LATCH_PIN, LOW);
	shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, numberToSegments[number]);
	digitalWrite(LATCH_PIN, HIGH);
}

void segment::clear()
{
	segment::update(0b00000000);
}
