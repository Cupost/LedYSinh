#include "Wave.h"
#include <avr/io.h>

WAVE *Wave;

void Wave_ChangePower() {
  if (Wave->Status == OFF) {
    Wave->Status = ON;
    Wave->Power_Level = LOW;
    OCR0B = 0x40;
    return;
  } else {
    switch (Wave->Power_Level) {
    case 0:
      Wave->Power_Level = MEDIUM;
      OCR0B = 0x80;
      break;
    case 1:
      Wave->Power_Level = HIGH;
      OCR0B = 0xCD;
      break;
    case 2:
      Wave->Power_Level = LOW;
      OCR0B = 0x40;
      break;
    }
  }
};

inline void Wave_PowerOff() {
  Wave->Status = OFF;
  OCR0B = 0x00;
}
