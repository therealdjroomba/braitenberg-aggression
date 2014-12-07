#include "e_epuck_ports.h"
#include "e_init_port.h"
#include "e_motors.h"
#include "e_prox.h"
#include "math.h"
#include <time.h>
#include <stdlib.h>

#include "braitenberg.h"
#include "utils.h"
#include "navigation.h"
#include "zombie_infestation_2.h"

#define M_PI 3.14159265358979323846

int main(void) {
    srand(time(NULL));
    e_init_port();
    e_init_motors();
    e_init_prox();
    InitNavigation();
    int waitTicks = 0;

    SetTargetInCM(0, 50);
    while (1) {
        if (waitTicks % 100 == 0) {
            UpdateCurrentPos();
        }
        if (waitTicks % 100 == 0) {
            //switchLED(-1, 0);
            //switchLED(getSelector(), 1);
            switch (getSelector()) {
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
                case 6:
                    UpdateNav();
                    break;
                case 7:
                    switchLED(-1, 0);
                    //starts as human
                    if (IsHuman() == 1) {
                        Human();
                    } else {
                        Zombie();
                    }
                    break;
                    /*case 8:
                        //starts as zombie
                        Zombie();
                        break;*/
                default:
                    e_set_speed_left(0);
                    e_set_speed_right(0);
            }
        }
        if (waitTicks == 10000) {
            waitTicks = 0;
        }
        waitTicks++;
        wait(100);
        //wait100K();
    }
}
