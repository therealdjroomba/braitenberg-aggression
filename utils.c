#include "utils.h"
#include "e_epuck_ports.h"

/*
 * Get the current value of the selector
 */
int getSelector()
{
    return SELECTOR0 + 2*SELECTOR1 + 4*SELECTOR2 + 8*SELECTOR3;
}

/*
 * Turn the selected LED on or off, if the LED number is not between
 * 0-7 all LEDS will be used
 */
void switchLED(int LED, int power)
{
    switch (LED)
    {
        case 0:
            LED0 = power;
            break;
        case 1:
            LED1 = power;
            break;
        case 2:
            LED2 = power;
            break;
        case 3:
            LED3 = power;
            break;
        case 4:
            LED4 = power;
            break;
        case 5:
            LED5 = power;
            break;
        case 6:
            LED6 = power;
            break;
        case 7:
            LED7 = power;
            break;
        case 8:
            FRONT_LED = power;
        default:
            LED0 = power;
            LED1 = power;
            LED2 = power;
            LED3 = power;
            LED4 = power;
            LED5 = power;
            LED6 = power;
            LED7 = power;
            FRONT_LED = power;
    }
}

void LEDError()
{
    switchLED(-1, 1);
}

/*
 * Wait for 100K noops to prevent
 * the poor epuck from exploding...
 */
void wait100K()
{
    wait(100000);
}
/*
 * Wait for a number of CPU ticks
 */
void wait(long ticks)
{
    long i;
    for (i = 0; i < ticks; i++) {
        asm("nop");
    }
}