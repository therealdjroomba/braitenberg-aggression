#include "braitenberg.h"

void aggression(int leftSensor, int rightSensor)
{
    e_set_speed_left(rightSensor);
    e_set_speed_right(leftSensor);
}

void fear(int leftSensor, int rightSensor)
{
    e_set_speed_left(leftSensor);
    e_set_speed_right(rightSensor);
}

void love(int leftSensor, int rightSensor)
{
    e_set_speed_left(BRAIT_MAX_SPEED - leftSensor);
    e_set_speed_right(BRAIT_MAX_SPEED - rightSensor);
}

void curious(int leftSensor, int rightSensor)
{
    e_set_speed_left(BRAIT_MAX_SPEED - rightSensor);
    e_set_speed_right(BRAIT_MAX_SPEED - leftSensor);
}

void executeBrait(int behaviour)
{
    int prox7, prox0;

    /*
     * Fetch the values from the IR blasters
     */
    prox7 = e_get_prox(7) + e_get_prox(6) * BRAIT_PROX_OFFSET;
    prox0 = e_get_prox(0) + e_get_prox(1) * BRAIT_PROX_OFFSET;

    /*
     * If the IR values are below the
     * threshold, assume it's just noise
     * and sit still
     */
    if (prox0 > BRAIT_PROX_THRESHOLD) {
        prox0 *= 2;

        /*
         * Cap the value to the maximum
         * speed of the epucks motors.
         *
         * The motors have a range of
         * -1000 : 1000
         */
        if (prox0 > BRAIT_MAX_SPEED)
        {
            prox0 = BRAIT_MAX_SPEED;
        }
        else if (prox0 < BRAIT_MIN_SPEED)
        {
            prox0 = BRAIT_MIN_SPEED;
        }
    }
    else
    {
        prox0 = BRAIT_MIN_SPEED;
    }

    if (prox7 > BRAIT_PROX_THRESHOLD) {
        prox7 *= 2;

        if (prox7 > BRAIT_MAX_SPEED)
        {
            prox7 = BRAIT_MAX_SPEED;
        }
        else if (prox7 < BRAIT_MIN_SPEED)
        {
            prox7 = BRAIT_MIN_SPEED;
        }
    }
    else
    {
        prox7 = BRAIT_MIN_SPEED;
    }

    switch (behaviour)
    {
        case AGGRESSION:
            aggression(prox7, prox0);
            break;
        case FEAR:
            fear(prox7, prox0);
            break;
        case LOVE:
            love(prox7, prox0);
            break;
        case CURIOUS:
            curious(prox7, prox0);
            break;
    }
}