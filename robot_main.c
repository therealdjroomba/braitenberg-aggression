#include "e_epuck_ports.h"
#include "e_init_port.h"
#include "e_motors.h"
#include "e_prox.h"

#include "braitenberg.h"
#include "utils.h"

int main(void) {

    e_init_port();
    e_init_motors();
    e_init_prox();

    while (1) {
        // Debug show selector in LEDs
        switchLED(-1, 0);
        switchLED(getSelector(), 1);

        switch (getSelector())
        {
            case 1: 
                executeBrait(AGGRESSION);
                break;
            case 2:
                executeBrait(FEAR);
                break;
            case 3:
                executeBrait(LOVE);
                break;
            case 4:
                executeBrait(CURIOUS);
                break;
            default:
                e_set_speed_left(0);
                e_set_speed_right(0);
        }

        wait100K();
    }
}
