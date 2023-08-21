/*
 * LED_BAR.c
 *
 * Created: 2023-07-26 오후 7:20:26
 *  Author: USER
 */ 

#include "LED_BAR.h"

LED leds[LED_COUNT] = { 
	{&PORTA, 0}, // (주소값, 핀번호)
	{&PORTA, 1},
	{&PORTA, 2},
	{&PORTA, 3},
	{&PORTA, 4},
	{&PORTA, 5},
	{&PORTA, 6},
	{&PORTA, 7},
};


void LED_Init(LED *led)
{
	*(led->port - 1) |= (1<< led->pin);
}


void LED_BAR_Init()
{
	LED_BAR_DDR = 0xff;
	LED_BAR_PORT = 0x00; // 꺼진 상태로 출발
	
	for (int i = 0 ; i < LED_COUNT ; i++)
	{
		LED_Init(&leds[i]);
	}
}


void LED_On(LED *led)
{
	*(led->port) |= (1<<led->pin);
}

void LED_Off(LED *led)
{
	*(led->port) &= ~(1<<led->pin);
}


void LED_Left_Shift(LED *leds)
{
	for (int i = 0 ; i < LED_COUNT ; i++)
	{
		LED_On(&leds[i]);
		_delay_ms(200);
	}
	for (int i = 0 ; i < LED_COUNT ; i++)
	{
		LED_Off(&leds[i]);
		_delay_ms(200);
	}
}

void LED_Right_Shift(LED *leds)
{
	for (int i = 7 ; i >= 0 ; i--)
	{
		LED_On(&leds[i]);
		_delay_ms(200);
	}
	for (int i = 7 ; i >= 0 ; i--)
	{
		LED_Off(&leds[i]);
		_delay_ms(200);
	}
}


void LED_Blink(uint8_t *LED_Data)
{
	LED_BAR_PORT = 0xaa;
	for (int i = 0 ; i < 15 ; i++)
	{
		LED_BAR_PORT = ~LED_BAR_PORT;
		_delay_ms(300);
		i++;
	}
	LED_BAR_PORT = 0x00;
}

void LED_Single_On()
{
	PORTD |= (1<<PIND2);
	_delay_ms(1000);
	PORTD &= ~(1<<PIND2);
}
