#include <avr/io.h>
#include <util/delay.h>

typedef struct
{
    enum Status {
        ON,
        OFF
    }Status;
    enum Power_Lever {
        LOW,
        MEDIUM,
        HIGH,
    }Power_Lever;
}Device;

Device *LED,*WAVE;




int main(void){
    LED->Status = OFF;
    WAVE->Status = OFF;

    while(1){
        PORTB = 0xFF;
        _delay_ms(1000);
        PORTB = 0x0;
        _delay_ms(1000);
    }
}