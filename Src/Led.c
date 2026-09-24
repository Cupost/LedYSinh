#include "Led.h"
#include "Struct.h"
#include <avr/io.h>

LED *Led;

void Led_ChangePower() {
  if (Led->Status == OFF) {
    Led->Status = ON;
    Led->Power_Level = LOW;
    OCR0A = 0x40;
    return;
  } else {
    switch (Led->Power_Level) {
    case 0:
      Led->Power_Level = MEDIUM;
      OCR0A = 0x80;
      break;
    case 1:
      Led->Power_Level = HIGH;
      OCR0A = 0xCD;
      break;
    case 2:
      Led->Power_Level = LOW;
      OCR0A = 0x40;
      break;
    }
  }
};

inline void Led_PowerOff() {
  Led->Status = OFF;
  OCR0A = 0x00;
}
