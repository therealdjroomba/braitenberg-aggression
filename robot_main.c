#include "e_epuck_ports.h"
#include "e_init_port.h"
#include "e_motors.h"
#include "e_prox.h"

#define PROX_THRESHOLD 100

/*
 * Wait for 100K noops to prevent
 * the poor epuck from exploding...
 */
void wait() {
    long i;
    for (i = 0; i < 100000; i++) {
        asm("nop");
    }
}

int main(void) {
    int prox7, prox0;

    e_init_port();
    e_init_motors();
    e_init_prox();

    while (1) {
        /*
         * Fetch the values from the IR blasters
         */
        prox7 = e_get_prox(7);
        prox0 = e_get_prox(0);

        /*
         * If the IR values are below the
         * threshold, assume it's just noise
         * and sit still
         */
        if (prox0 > PROX_THRESHOLD || prox7 > PROX_THRESHOLD) {
            prox0 *= 10;
            prox7 *= 10;

            /*
             * Cap the value to the maximum
             * speed of the epucks motors.
             *
             * The motors have a range of
             * -1000 : 1000
             */
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
        wait();
    }
}
