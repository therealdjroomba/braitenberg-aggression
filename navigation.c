#include "navigation.h"

#include <math.h>
#include <stdbool.h>
#include "e_epuck_ports.h"
#include "e_motors.h"

#define MAX_SENSOR_OVER_VALUE 3750.0

#define MAX_TURNING_SPEED 800
#define MIN_TURNING_SPEED 0
#define TURNING_SPEED 300
#define TURNING_THRESHOLD 0.01
#define MOVING_THRESHOLD 30.0
#define M_PI 3.14159265358979323846

#define SENSOR_WALL_DIST 1200.0

#define STEPS_PER_CM 77.6

static double curPosX;
static double curPosY;
static double curAngle;

static double targetX;
static double targetY;

static int lastStepsL;
static int lastStepsR;

/* Internal functions */
void __attribute__((interrupt, auto_psv))
_T2Interrupt(void) {
    // Update current pos every timer interrupt
    UpdateCurrentPos();
}

/* Functions */

double GetCurPosX() {
    return curPosX;
}

double GetCurPosY() {
    return curPosY;
}

double GetCurAngle() {
    return curAngle;
}

void InitNavigation() {
    curPosX = curPosY = curAngle = 0;
    lastStepsL = lastStepsR = 0;

    // Set up timer 2
    /*T2CONbits.TON = 0;            // stop Timer2

    T2CON = 0;                    //
    T2CONbits.TCKPS=3;            // prescsaler = 256
    TMR2 = 0;                     // clear Timer2
    PR2 = (FCY/256)/abs(10);      // interrupt every 10ms with 256 prescaler
    IFS0bits.T2IF = 0;            // clear interrupt flag
    IEC0bits.T2IE = 1;            // set interrupt enable bit
    T2CONbits.TON = 1;            */// Start Timer2
}

void UpdateCurrentPos() {
    int curLSteps = e_get_steps_left();
    int curRSteps = e_get_steps_right();

    // Get change in motor counters
    int dL = curLSteps - lastStepsL;
    int dR = curRSteps - lastStepsR;

    lastStepsL = curLSteps;
    lastStepsR = curRSteps;

    double scaler = (double) (dR + dL) / 2.0;

    double dAngle = (dR - dL) / (2 * MOTOR_DIST);

    curPosX += scaler * -sin(curAngle + dAngle);
    curPosY += scaler * cos(curAngle + dAngle);

    curAngle += (dR - dL) / MOTOR_DIST;

    // Now to make sure it is in the range -PI to PI

    curAngle = GetAngleWithinRange(curAngle);
}

void FollowLeftWall()
{
    switchLED(-1, 0);
    if (e_get_prox(0) > SENSOR_WALL_DIST / 2.0 ||
            e_get_prox(7) > SENSOR_WALL_DIST / 2.0)
    {
        e_set_speed_left(TURNING_SPEED);
        e_set_speed_right(-TURNING_SPEED);
        return;
    }

    int sensor_5 = e_get_prox(5);
    int sensor_6 = e_get_prox(6);

    int sensorSpeed_5 = TURNING_SPEED * (sensor_5 - SENSOR_WALL_DIST);
    int sensorSpeed_6 = TURNING_SPEED * (sensor_6 * 2 - SENSOR_WALL_DIST);

    int averageWeightedSensorValue = (sensorSpeed_5 + sensorSpeed_6) / 2.0;

    int lSpeed = averageWeightedSensorValue;

    if (lSpeed > MAX_TURNING_SPEED)
    {
        lSpeed = MAX_TURNING_SPEED;
    }
    else if (lSpeed < MIN_TURNING_SPEED)
    {
        lSpeed = MIN_TURNING_SPEED;
    }

    if (lSpeed <= MIN_TURNING_SPEED)
    {
        switchLED(6, 1);
    }
    else
    {
        switchLED(2, 1);
    }

    e_set_speed_left(lSpeed);

    double overDesiredSensorValue = (double)averageWeightedSensorValue - SENSOR_WALL_DIST;

    if (overDesiredSensorValue > 0)
    {
        double percentOfMaxSensor = overDesiredSensorValue / MAX_SENSOR_OVER_VALUE;
        int rSpeed = TURNING_SPEED * (1.0 - percentOfMaxSensor);

        if (rSpeed < 0)
        {
            rSpeed = 0;
        }

        e_set_speed_right(rSpeed);
    }
    else
    {
        e_set_speed_right(TURNING_SPEED);
    }
}

/*
 * \brief Gets the equivalent angle in the range -PI < angle <= PI
 *
 * \param angle The input angle in radians
 *
 * \return An equivalent angle in the range -PI < angle <= PI
 *
 */
double GetAngleWithinRange(double angle) {

    // If the angle is indeed out of range, add/subtract a full revolution
    if (angle > M_PI) {
        angle -= (2 * M_PI);
    } else if (angle <= -M_PI) {
        angle += (2 * M_PI);
    }

    // This will keep adding/subtracting 2 * PI until the angle is within range
    if (angle <= M_PI && angle > -M_PI) {
        return angle;
    } else {
        return GetAngleWithinRange(angle);
    }
}

/*
 * \brief Calculates the change in angle required to face the given target
 *
 * \param targetX Target X-Coordinate
 * \param targetY Target Y-Coordinate
 *
 * \return Angle within the range -PI < angle <= PI representing the change
 *          needed to face the given target
 *
 */
double GetAngleChange(double targetX, double targetY) {
    double curX = GetCurPosX();
    double curY = GetCurPosY();

    double dX = fabs(targetX - curX);
    double dY = fabs(targetY - curY);

    double angle;

    // Calculate angles for left quadrants
    if (targetY > curY) {
        // Q1
        angle = atan(dX / dY);
    } else {
        // Q2
        angle = atan(dY / dX) + (M_PI / 2);
    }

    // If the target is in the right quadrants, we need to make it negative
    if (targetX >= curX) {
        angle = -angle;
    }

    return angle;
}

/*
 * Angle must be between -PI and PI
 */
void StartTurning(double angle) {

    if (angle < -M_PI || angle > M_PI) {
        LEDError();
        e_set_speed_left(0);
        e_set_speed_right(0);
        return;
    }

    if (angle > 0) {
        // TURN LEFT
        e_set_speed_left(-TURNING_SPEED);
        e_set_speed_right(TURNING_SPEED);
    } else {
        //TURN RIGHT
        e_set_speed_left(TURNING_SPEED);
        e_set_speed_right(-TURNING_SPEED);
    }

}



void SetTarget(double x, double y) {
    targetX = x;
    targetY = y;
}

void SetTargetInCM(double x, double y) {
    targetX = x * STEPS_PER_CM;
    targetY = y * STEPS_PER_CM;
}

void UpdateNav() {
    /*double targetAngle = GetAngleChange(targetX, targetY);

    if (targetAngle - GetCurAngle() < THRESHOLD && targetAngle - GetCurAngle() > -THRESHOLD) {
        if (GetCurPosX() > targetX && GetCurPosY() > targetY) {
            e_set_speed_left(0);
            e_set_speed_right(0);
        } else {
            e_set_speed_left(TURNING_SPEED);
            e_set_speed_right(TURNING_SPEED);
        }
        
    } else {
        StartTurning(targetAngle);
    }*/

    TurnToTarget();
}

void TurnToTarget() {
    double targetAngle = GetAngleChange(targetX, targetY);

    if (fabs(targetAngle - GetCurAngle()) < TURNING_THRESHOLD) {
        e_set_speed_left(0);
        e_set_speed_right(0);
        MoveForwardsToTarget();
        return;
    } else {
        StartTurning(targetAngle);
    }
}

void MoveForwardsToTarget(){
    if (fabs(GetCurPosX() - targetX) < MOVING_THRESHOLD &&
            fabs(GetCurPosY() - targetY) < MOVING_THRESHOLD) {
        e_set_speed_left(0);
        e_set_speed_right(0);
    } else {
        e_set_speed_left(TURNING_SPEED);
        e_set_speed_right(TURNING_SPEED);
    }
}