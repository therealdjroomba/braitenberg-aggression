#include "e_epuck_ports.h"

#define LIGHT_WAIT 1


int GetSelector() {
	return SELECTOR0 + 2*SELECTOR1 + 4*SELECTOR2 + 8*SELECTOR3;
}

void SwitchLED(int led, int on)
{
    switch (led)
    {
        case 0:
            LED0 = on;
            break;
        case 1:
            LED1 = on;
            break;
        case 2:
            LED2 = on;
            break;
        case 3:
            LED3 = on;
            break;
        case 4:
            LED4 = on;
            break;
        case 5:
            LED5 = on;
            break;
        case 6:
            LED6 = on;
            break;
        case 7:
            LED7 = on;
            break;

        default:
            LED0 = on;
            LED1 = on;
            LED2 = on;
            LED3 = on;
            LED4 = on;
            LED5 = on;
            LED6 = on;
            LED7 = on;
    }
}

int main(void)
{
    long wait;
    e_init_port();

    while(1)
    {
        LED0 = LED0 ^ 1;
        
        for(wait=0; wait<100000; wait++)
        {
                asm("nop");
        }
    }
}
