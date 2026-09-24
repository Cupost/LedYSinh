#include "Led.h"
#include "Struct.h"
#include "Wave.h"
#include <avr/io.h>
#include <util/delay.h>

void TimerPWM_Init();
void ProgramInit(void);

int main(void) {
  ProgramInit();
  TimerPWM_Init();

  while (1) {
    PORTB = 0xFF;
    _delay_ms(1000);
    PORTB = 0x0;
    _delay_ms(1000);
  }
}

void ProgramInit() {
  // Setup Status for device
  Led->Status = OFF;
  OCR0A = 0x00;
  Wave->Status = OFF;
  OCR0B = 0x00;
};
void TimerPWM_Init() {
  /* WGM02:WGM00 = 0 1 1 => Fast PWM mode
   * CS02:CS01 = 0 1 0 => Timer Prescale = 8
   * Timer turn on affer prescale
   * */
  TCCR0A = 0xA3;
  TCCR0B = 0x02;
};
