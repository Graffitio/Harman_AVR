/*
 * LED.h
 *
 * Created: 2023-07-10 오후 3:36:24
 *  Author: USER
 */ 
//#include <stdio.h>
//
//#ifndef LED_H_
//#define LED_H_
//
//#define LED_COUNT	8 
//
//typedef struct _led{
	//volatile uint8_t *port; // LED가 연결된 포트,
						    //// volatile : 레지스터 변수가 손을 대는 것을은 다 이걸 적어줘야 됨.
						    //// 컴파일러가 지 멋대로 최적화시켜버리면, 예상치못한 일이 벌어질 '수도' 있다.
							//// 너 맘대로 최적화하지 마! 라는 의미
							//// 따라서 레지스터 변수에는 반드시 volatile을 붙여줄 것.
	//uint8_t pin; // LED가 연결된 핀 번호
	//}LED;
//
//void ledInit(LED *led);
//void ledOn(LED *led); // LED에 대한 주소를 받음
//void ledOff(LED *led); // 인자를 다 주소값으로 받음
//
//
//
//#endif /* LED_H_ */

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