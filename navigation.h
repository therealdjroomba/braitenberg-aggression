/* 
 * File:   navigation.h
 * Author: Paul Lowrie
 *
 * Navigation functions used by E-Puck to know where it is and where it is
 * going.
 *
 * \warning Uses Timer 2
 * 
 * Created on 20 November 2014, 14:23
 */

#ifndef NAVIGATION_H
#define	NAVIGATION_H

#define	MOTOR_DIST 420.00

/*
 * Initalises variables and Timer 2 ready for navigation
 */
void InitNavigation();


/*
 * Get the position data
 */
double GetCurPosX();
double GetCurPosY();
double GetCurAngle();

/*
 * Updates current position
 */
void UpdateCurrentPos();

double GetAngleChange(double x, double y);
double GetAngleWithinRange(double angle);

void StartTurning(double angle);
void UpdateNav();
void TurnToTarget();
void MoveForwardsToTarget();

void SetTarget(double x, double y);
void SetTargetInCM(double x, double y);

#endif	/* NAVIGATION_H */

