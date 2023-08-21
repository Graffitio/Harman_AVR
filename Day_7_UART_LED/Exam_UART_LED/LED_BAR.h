/*
 * IncFile1.h
 *
 * Created: 2023-07-26 오후 7:20:07
 *  Author: USER
 */ 


#ifndef LED_BAR_H_
#define LED_BAR_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

#define LED_BAR_PORT	PORTA
#define LED_BAR_DDR		DDRA
#define LED_COUNT		8

typedef struct _led
{
	volatile uint8_t *port;
	uint8_t pin;
}LED;

extern LED leds[LED_COUNT];

void LED_Init();
void LED_BAR_Init();
void LED_On(LED *led);
void LED_Off(LED *led);
void LED_Left_Shift(LED *leds);
void LED_Right_Shift(LED *leds);
void LED_Blink(uint8_t *LED_Data);
void LED_Single_On();




#endif /* LED_BAR_H_ */