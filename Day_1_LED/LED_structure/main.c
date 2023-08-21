/*
 * LED_structure.c
 *
 * Created: 2023-07-10 오후 3:35:50
 * Author : USER
 */ 
#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "LED.h"


// LED 한 개 구조체로 표현 //
//int main(void)
//{
	//LED led; // 데이터형, 변수 선언 // LED라는 데이터타입의 led
	//led.port = &PORTD;
	//led.pin = 0;
	//ledInit(&led);
	 //
    //while (1) 
    //{
		//ledOn(&led);
		//_delay_ms(200);
		//ledOff(&led);
		//_delay_ms(200);
    //}
//}

// LED 8개 컨트롤 //
int main()
{
	LED leds[LED_COUNT] = {
		{&PORTD, 0}, // (주소값, 핀번호)
		{&PORTD, 1},
		{&PORTD, 2},
		{&PORTD, 3},
		{&PORTD, 4},
		{&PORTD, 5},
		{&PORTD, 6},
		{&PORTD, 7},
	};
	// 초기화
	for (int i = 0 ; i < LED_COUNT ; i++)
	{
		ledInit(&leds[i]); // i번째 배열의 주소값을 넘겨 줌
	}
	
	while (1)
	{
		for (int i=0 ; i < 6 ; i++)
		{
			ledOn(&leds[i]);
			ledOn(&leds[7-i]);
			_delay_ms(100);
			//ledOff(&leds[i]);
			//ledOff(&leds[7-i]);
			//_delay_ms(100);
		}
		for (int i=7 ; i>=0 ; i--)
		{
			//ledOn(&leds[i]);
			//ledOn(&leds[7-i]);
			//_delay_ms(100);
			ledOff(&leds[i]);
			ledOff(&leds[7-i]);
			_delay_ms(100);
		}
		for (int i=0 ; i < 5 ; i++)
		{
			ledOn(&leds[3-i]);
			ledOn(&leds[4+i]);
			_delay_ms(100);
			//ledOff(&leds[3-i]);
			//ledOff(&leds[3+i]);
			//_delay_ms(100);
		}
		for (int i= 0; i < 5 ; i++)
		{
			//ledon(&leds[i]);
			//ledon(&leds[7-i]);
			//_delay_ms(100);
			ledOff(&leds[3-i]);
			ledOff(&leds[4+i]);
			_delay_ms(100);
		}
	}
}
//0123 4567

//0000 0000
//1000 0001
//0100 0010
//0010 0100
//0001 1000
//0000 0000
//0001 1000
//0010 0100
//0100 0010
//1000 0001
//0000 0000
