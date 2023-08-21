/*
 * LED_shift.c
 *
 * Created: 2023-07-10 오후 2:32:19
 * Author : USER
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h> // delay함수써야되니까~
#include "LED.h" // 얘를 빼먹으면 지멋대로 움직임


int main(void)
{
   ledInit();
   
   uint8_t ledData = 0x01;  // unsigned int 8bit 0~255까지
   
    while (1) 
    {
		for(int i = 0 ; i < 7 ; i++)
		{
			ledLeftShift(&ledData); // 주소값으로 던져줘야 함수에서 포인터 변수로 받음
			_delay_ms(200); 
		}
		for (int i = 0 ; i < 7 ; i++)
		{
			ledRightShift(&ledData);
			_delay_ms(200);
		}
    }
}

