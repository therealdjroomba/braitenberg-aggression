/* 
 * File:   braitenberg.h
 * Author: Paul Lowrie
 *
 * Implementation of Braitenberg behaviours
 *
 * Created on 20 November 2014, 14:05
 */

#ifndef BRAITENBERG_H
#define	BRAITENBERG_H

#define	AGGRESSION 1
#define	FEAR 2
#define	LOVE 3
#define	CURIOUS 4

#define BRAIT_PROX_THRESHOLD 200
#define BRAIT_PROX_OFFSET 0.75

#define BRAIT_MAX_SPEED 900
#define BRAIT_MIN_SPEED 300

/* Functions */
// Turn towards objects
void aggression(int leftSensor, int rightSensor);
// Turn away from objects
void fear(int leftSensor, int rightSensor);
// Turn towards objects but stop before hitting them
void love(int leftSensor, int rightSensor);
// Turn away objects but stop before hitting them
void curious(int leftSensor, int rightSensor);

// Execute the choosen behaviour
void executeBrait(int behaviour);

#endif	/* BRAITENBERG_H */

