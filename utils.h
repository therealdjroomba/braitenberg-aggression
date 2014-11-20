/* 
 * File:   utils.h
 * Author: Paul Lowrie
 *
 * Created on 20 November 2014, 12:40
 */

#ifndef UTILS_H
#define	UTILS_H

/* Functions */
/*
 * Get the current value of the selector
 */
int getSelector();

void switchLED(int LED, int power);

/*
 * Wait for 100K noops to prevent
 * the poor epuck from exploding...
 */
void wait100K();
void wait(long ticks);

#endif	/* UTILS_H */

