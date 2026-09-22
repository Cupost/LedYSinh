#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
int main(void){
    while(1){
        PORTB = 0xFF;
        _delay_ms(1000);
        PORTB = 0x0;
        _delay_ms(1000);
    }
}