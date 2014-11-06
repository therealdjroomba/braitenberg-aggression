#include "e_epuck_ports.h"
#include "e_motors.h"
#include "e_prox.h"

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
	int prox7, prox0;
	long i;

    e_init_port();
	e_init_motors();
	e_init_prox();

	//e_set_speed_left(500); //go forward on half speed
 	//e_set_speed_right(-500); //go backward on half speed
    
	while(1)
    {
        prox7 = e_get_prox(7);
		prox0 = e_get_prox(0);

		if(prox0 > 100 || prox7 > 100) {
			prox0 *= 10;
			prox7 *= 10;

			if (prox0 > 1000)
				prox0 = 1000;

			if (prox7 > 1000)
				prox7 = 1000;

			e_set_speed_left(prox0);
			e_set_speed_right(prox7);
		} else {
			e_set_speed_left(0);
			e_set_speed_right(0);
		}
		for(i=0; i<100000; i++) { asm("nop"); }
    }
}
