#include "e_epuck_ports.h"
#include "e_init_port.h"
#include "e_motors.h"
#include "e_prox.h"

#include "braitenberg.h"
#include "navigation.h"
#include "utils.h"

#define M_PI 3.14159265358979323846
#define THRESHOLD 0.5

double targetAngle;
int turning;

void Turning()
{
    if (turning == 1)
                {
                    if (GetCurAngle() < targetAngle + THRESHOLD &&
                            GetCurAngle() > targetAngle - THRESHOLD)
                    {
                        e_set_speed_left(0);
                        e_set_speed_right(0);

                        turning = 0;
                    }
                }
                else if (turning == 0)
                {
                    if (GetCurAngle() >= targetAngle + THRESHOLD ||
                            GetCurAngle() <= targetAngle - THRESHOLD)
                    {
                        e_set_speed_left(-300);
                        e_set_speed_right(300);

                        turning = 1;
                    }
                }
}

int main(void) {

    e_init_port();
    e_init_motors();
    e_init_prox();
    InitNavigation();

    targetAngle = GetCurAngle() + M_PI;

    wait(1000000);
    //turning = 0;

    e_set_speed_left(-300);
    e_set_speed_right(300);

    int waitTicks = 0;

    while (1)
    {
        if (waitTicks % 100 == 0)
        {
            UpdateCurrentPos();
        }
        if (waitTicks > 10000)
        {
            double angle = GetCurAngle();

            switchLED(-1, 0);

            if (angle > 2 * M_PI)
            {
                switchLED(-1, 1);

                e_set_speed_left(0);
                e_set_speed_right(0);
            }
            
            waitTicks = 0;
        }
        else
        {
            waitTicks++;
        }
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
            default:
                e_set_speed_left(0);
                e_set_speed_right(0);
        }
*/
        //wait100K();
    }
}
