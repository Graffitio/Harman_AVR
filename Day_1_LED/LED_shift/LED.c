/*
 * LED.c
 *
 * Created: 2023-07-10 오후 2:40:12
 *  Author: USER
 */ 

#include "LED.h" // 함수의 원형이 여기 선언되어있으니, LED.h를 include해줘야 한다.

void ledInit() // led를 이니셜하는 함수
{
	LED_DDR = 0xff; // Art+G 누르면 LED_DDR가 선언된 곳으로 이동함.
}

void GPIO_output(uint8_t data) //
{
	LED_PORT = data; // 0x01
}

void ledLeftShift(uint8_t *data) // LED를 좌시프트, 얘는 포인터로 받음
							      // * : 참조연산자
{
	*data = (*data >> 7) | (*data << 1); // 비트마스킹, 어떤 값이 있는지 모르니, msb는 7칸 몰려오고, lsb 1칸 몰려간 것을 or연산
	GPIO_output(*data); // (*data) : 연산자 우선순위때문에 묶음
}

void ledRightShift(uint8_t *data) // LED를 우시프트
{
	*data = (*data << 7) | (*data >> 1);
	GPIO_output(*data);
}