#include "e_epuck_ports.h"
#include "e_init_port.h"
#include "e_motors.h"
#include "e_prox.h"

#include "braitenberg.h"
#include "navigation.h"
#include "utils.h"
#include "navigation.h"

#define M_PI 3.14159265358979323846

int main(void) {

    e_init_port();
    e_init_motors();
    e_init_prox();
    InitNavigation();

    double targetAngle = 2 * M_PI;

    wait(1000000);

    int waitTicks = 0;

    StartTurning(targetAngle);
    while (1)
    {
        if (waitTicks % 100 == 0)
        {
            UpdateCurrentPos();
        }
        if (waitTicks % 10000 == 0)
        {
            //UpdateNav(targetAngle);
            if (GetCurAngle() > targetAngle) {
                e_set_speed_left(0);
                e_set_speed_right(0);
            }

            LED0 = LED0^1;
        }
        if (waitTicks == 10000) {
            waitTicks = 0;
        }
        waitTicks++;
        wait(100);
        //Turning();

        /*
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
            case 5:
                TurnToTarget();
                wait(1000000);
                break;
            default:
                e_set_speed_left(0);
                e_set_speed_right(0);
        }
*/
        //wait100K();
    }
}
