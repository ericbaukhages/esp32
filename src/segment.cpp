#include "Arduino.h"
#include "segment.h"

#define LED_SEGMENT_A 4
#define LED_SEGMENT_B 5
#define LED_SEGMENT_C 12
#define LED_SEGMENT_D 13
#define LED_SEGMENT_E 14
#define LED_SEGMENT_F 18
#define LED_SEGMENT_G 19
#define LED_SEGMENT_DP 21

int segments [8] = {
  LED_SEGMENT_A,
  LED_SEGMENT_B,
  LED_SEGMENT_C,
  LED_SEGMENT_D,
  LED_SEGMENT_E,
  LED_SEGMENT_F,
  LED_SEGMENT_G,
  LED_SEGMENT_DP,
};

int numbers [16][7] = {
  /*   A     B     C     D     E     F     G */
  { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH,  LOW }, /* 0 */
  {  LOW, HIGH, HIGH,  LOW,  LOW,  LOW,  LOW }, /* 1 */
  { HIGH, HIGH,  LOW, HIGH, HIGH,  LOW, HIGH }, /* 2 */
  { HIGH, HIGH, HIGH, HIGH,  LOW,  LOW, HIGH }, /* 3 */
  {  LOW, HIGH, HIGH,  LOW,  LOW, HIGH, HIGH }, /* 4 */
  { HIGH,  LOW, HIGH, HIGH,  LOW, HIGH, HIGH }, /* 5 */
  { HIGH,  LOW, HIGH, HIGH, HIGH, HIGH, HIGH }, /* 6 */
  { HIGH, HIGH, HIGH,  LOW,  LOW,  LOW,  LOW }, /* 7 */
  { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH }, /* 8 */
  { HIGH, HIGH, HIGH,  LOW,  LOW, HIGH, HIGH }, /* 9 */
  { HIGH, HIGH, HIGH,  LOW, HIGH, HIGH, HIGH }, /* A */
  {  LOW,  LOW, HIGH, HIGH, HIGH, HIGH, HIGH }, /* B */
  { HIGH,  LOW,  LOW, HIGH, HIGH, HIGH,  LOW }, /* C */
  {  LOW, HIGH, HIGH, HIGH, HIGH,  LOW, HIGH }, /* D */
  { HIGH,  LOW,  LOW, HIGH, HIGH, HIGH, HIGH }, /* E */
  { HIGH,  LOW,  LOW,  LOW, HIGH, HIGH, HIGH }, /* F */
};

void writeNumberToSegment(int index)
{
  for (int i = 0; i < 7; i++) {
    digitalWrite(segments[i], numbers[index][i]);
  }
}

void clearSegment()
{
  for (int i = 0; i < 7; i++) {
    digitalWrite(segments[i], LOW);
  }
}

void initializeSegments()
{
  for (int i = 0; i < 8; i++) {
    pinMode(segments[i], OUTPUT);
  }
}
