#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "e_epuck_ports.h"
#include "e_init_port.h"
#include "e_motors.h"
#include "e_prox.h"

#include "braitenberg.h"
#include "navigation.h"
#include "utils.h"
#include "zombie_infestation_2.h"
#include "settings.h"

static int turning = 0;
static double targetAngle;
static int human = 1;

int isHuman() {
    return human;
}

void executeHuman() {
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

void executeZombie() {
    switchLED(-1, 1);
    if (turning == 0) {
        if (e_get_prox(0) > HIT_THRESHOLD || e_get_prox(7) > HIT_THRESHOLD) {
            turning = 1;
            //~PI-x degrees + x*2 degrees * randomPercentage
            double angleChangeRange = M_PI / 6; //target angle will be PI +/- a percent of this value
            double randomPercentage = (((double) rand()) / RAND_MAX);
            double angleChange = (M_PI - angleChangeRange) + (2 * angleChangeRange * randomPercentage);
            targetAngle = GetAngleWithinRange(GetCurAngle() + angleChange);
            StartTurning(targetAngle);
        } else {
            executeBrait(AGGRESSION);
        }
    } else if (fabs(targetAngle - GetCurAngle()) < TURNING_THRESHOLD){
        turning = 0;
    }
}

void RunAway() {
    int sensor_5 = e_get_prox(5);
    int sensor_6 = e_get_prox(6) * 2;
    int sensor_7 = e_get_prox(7) * 4;

    int rightMaxSensor = max(max(sensor_5, sensor_6), sensor_7);

    int sensor_2 = e_get_prox(2);
    int sensor_1 = e_get_prox(1) * 2;
    int sensor_0 = e_get_prox(0) * 4;

    int leftMaxSensor = max(max(sensor_2, sensor_1), sensor_0);

    if (rightMaxSensor > (int) ZOMBIE_WALL_DIST){
        e_set_speed_left(TURNING_SPEED);
        e_set_speed_right(-TURNING_SPEED);
    } else if (leftMaxSensor > (int) ZOMBIE_WALL_DIST){
        e_set_speed_left(-TURNING_SPEED);
        e_set_speed_right(TURNING_SPEED);
    } else {
        e_set_speed_left(TURNING_SPEED);
        e_set_speed_right(TURNING_SPEED);
    }
}