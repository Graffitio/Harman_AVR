/*
 * Button_structure.c
 *
 * Created: 2023-07-11 오후 2:50:28
 * Author : USER
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "Button_structure.h"



int main(void)
{
    LED_DDR = 0xff; // 출력 설정
	Button btnOn;
	Button btnOff;
	Button btnTog;
	
	Button_init(&btnOn, &BUTTON_DDR, &BUTTON_PIN, BUTTON_ON); // 주소값 넘겨줌
	Button_init(&btnOff, &BUTTON_DDR, &BUTTON_PIN, BUTTON_OFF);
	Button_init(&btnTog, &BUTTON_DDR, &BUTTON_PIN, BUTTON_TOGGLE);
	
	
    while (1) 
    {
		if (BUTTON_getState(&btnOn) == ACT_RELEASED)
		{
			LED_PORT = 0xff;
		}
		if(BUTTON_getState(&btnOff) == ACT_RELEASED)
		{
			LED_PORT = 0x00;
		}
		if(BUTTON_getState(&btnTog) == ACT_RELEASED)
		{
			LED_PORT ^= 0xff;
		}
    }
}

