#include "navigation.h"

#include <math.h>
#include <stdbool.h>
#include "e_epuck_ports.h"
#include "e_motors.h"


#define THRESHOLD 0.0
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
}

double GetAngleChange(double targetX, double targetY) {
    double curX = GetCurPosX();
    double curY = GetCurPosY();

    double dX = targetX - curX;
    double dY = targetY - curY;

    if (dX < 0) dX *= -1;
    if (dY < 0) dY *= -1;

    double angleChange = atan(dX / dY);

    if (targetX > curX) {
        if (targetY < curY) {
            angleChange = 3.141 - angleChange;
        }
    } else {
        if (targetY > curY) {
            angleChange += 3.141;
        } else {
            angleChange = 2 * 3.141 - angleChange;
        }
    }

    return angleChange;
}

void StartTurning(double angle) {


    int turningSpeed = 100;

    //if (angle <= M_PI) {
        e_set_speed_left(-turningSpeed);
        e_set_speed_right(turningSpeed);
    /*} else {
        e_set_speed_left(turningSpeed);
        e_set_speed_right(-turningSpeed);
    }*/

}

void TurnToTarget() {
    //TurnByAngle(GetAngleChange(-10, 10));
    // TurnByAngle(3.141/4);
}

void UpdateNav(double targetAngle) {


    if (targetAngle - GetCurAngle() < THRESHOLD/* && targetAngle - GetCurAngle() > -THRESHOLD*/) {
                e_set_speed_left(0);
                e_set_speed_right(0);
            }


  /*  double dist = abs(GetCurAngle() - targetAngle);

    if (dist < THRESHOLD) {
        e_set_speed_left(0);
        e_set_speed_right(0);

    }*/
}