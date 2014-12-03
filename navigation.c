#include "navigation.h"

#include <math.h>
#include <stdbool.h>
#include "e_epuck_ports.h"
#include "e_motors.h"

#define TURNING_SPEED 800
#define THRESHOLD 0.01
#define M_PI 3.14159265358979323846

static double curPosX;
static double curPosY;
static double curAngle;

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

    curPosX += scaler * cos(curAngle + dAngle);
    curPosY += scaler * sin(curAngle + dAngle);

    curAngle += (dR - dL) / MOTOR_DIST;

    // Now to make sure it is in the range -PI to PI

    curAngle = GetAngleWithinRange(curAngle);
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

void TurnToTarget() {
    //TurnByAngle(GetAngleChange(-10, 10));
    // TurnByAngle(3.141/4);
}

void UpdateNav(double targetAngle) {


    if (targetAngle - GetCurAngle() < THRESHOLD && targetAngle - GetCurAngle() > -THRESHOLD) {
        e_set_speed_left(0);
        e_set_speed_right(0);
    }


    /*  double dist = abs(GetCurAngle() - targetAngle);

      if (dist < THRESHOLD) {
          e_set_speed_left(0);
          e_set_speed_right(0);

      }*/
}