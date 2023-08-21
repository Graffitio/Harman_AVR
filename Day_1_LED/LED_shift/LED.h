/*
 * LED.h
 *
 * Created: 2023-07-10 오후 2:39:45
 *  Author: USER
 */ 


#ifndef LED_H_ // 만약 얘가 선언되어있지 않다면, 
#define LED_H_ // 얘를 선언하겠다.

#include <avr/io.h> // 얘가 왜 LED.h에 필요한가?
#include <stdio.h>

#define LED_PORT	PORTD 
#define LED_DDR		DDRD // DDR : 방향

void ledInit(); // led를 이니셜하는 함수
void GPIO_output(uint8_t data); // 
void ledLeftShift(uint8_t *data); // LED를 좌시프트, 얘는 포인터로 받음
void ledRightShift(uint8_t *data);// LED를 우시프트




#endif /* LED_H_ */ // if로 열었기 때문에 endif로 닫아준다.