#include <math.h>

#include "e_epuck_ports.h"
#include "e_init_port.h"
#include "e_motors.h"
#include "e_prox.h"

#include "braitenberg.h"
#include "navigation.h"
#include "utils.h"
#include "zombie_infestation_2.h"

#define HIT_THRESHOLD 2000

static int turning = 0;
static double storedAngle;
static double angleChange = 3.0;
static int human = 1;

int IsHuman() {
    return human;
}

void Human() {
    switchLED(0, 1);
    int sensor;
    for (sensor = 0; sensor < 8; sensor++) {
        if (e_get_prox(sensor) > HIT_THRESHOLD) {
            human = 0;
            return;
        }
    }
    RunAway();
}

void Zombie() {
    switchLED(-1, 1);
    if (turning == 0) {
        if (e_get_prox(0) > HIT_THRESHOLD || e_get_prox(7) > HIT_THRESHOLD) {
            turning = 1;
            storedAngle = GetCurAngle();
        } else {
            executeBrait(AGGRESSION);
        }
    } else {
        if (fabs(storedAngle - GetCurAngle()) < angleChange) {
            e_set_speed_left(-500);
            e_set_speed_right(500);
        } else {
            turning = 0;
        }
    }
}
