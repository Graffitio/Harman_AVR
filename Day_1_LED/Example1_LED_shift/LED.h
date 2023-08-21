/*
 * IncFile1.h
 *
 * Created: 2023-07-11 오전 9:46:57
 *  Author: USER
 */ 


#include <stdio.h>

#ifndef LED_H_
#define LED_H_

#define LED_COUNT 8

typedef struct{
	volatile uint8_t *port;
	uint8_t pin;
}LED;

void ledInit(LED *led);
void ledOn(LED *led);
void ledOff(LED *led);

#endif