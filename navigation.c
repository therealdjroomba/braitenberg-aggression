#include "navigation.h"

#include "math.h"
#include "e_epuck_ports.h"
#include "e_motors.h"

static double curPosX;
static double curPosY;
static double curAngle;

static int lastStepsL;
static int lastStepsR;

/* Internal functions */
void __attribute__((interrupt, auto_psv))
_T2Interrupt(void)
{
    // Update current pos every timer interrupt
    UpdateCurrentPos();
}

/* Functions */

double GetCurPosX()
{
    return curPosX;
}

double GetCurPosY()
{
    return curPosY;
}
double GetCurAngle()
{
    return curAngle;
}

void InitNavigation()
{
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

void UpdateCurrentPos()
{
    int curLSteps = e_get_steps_left();
    int curRSteps = e_get_steps_right();

    // Get change in motor counters
    int dL = curLSteps - lastStepsL;
    int dR = curRSteps - lastStepsR;

    lastStepsL = curLSteps;
    lastStepsR = curRSteps;

    double scaler = (double)(dR + dL)/2.0;

    double dAngle = (dR - dL) / (2*MOTOR_DIST);

    curPosX += scaler * cos(curAngle + dAngle);
    curPosY += scaler * sin(curAngle + dAngle);

    curAngle += (dR - dL) / MOTOR_DIST;
}