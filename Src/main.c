#include <avr/io.h>
#include <util/delay.h>
#include "Led.h"
#include "Wave.h"





int main(void){
    Led->Status = OFF;
    Wave->Power_Level = LOW;
    while(1){
        PORTB = 0xFF;
        _delay_ms(1000);
        PORTB = 0x0;
        _delay_ms(1000);
    }
}