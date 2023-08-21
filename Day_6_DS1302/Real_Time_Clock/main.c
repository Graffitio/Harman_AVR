/*
 * Real_Time_Clock.c
 *
 * Created: 2023-07-26 오전 11:45:33
 * Author : USER
 */ 
#define F_CPU 16000000UL
#include "DS1302.h"
#include "UART_2.h"
#include "I2C_LCD.h"


// 출력 스트림 설정 <stdio.h>에 있는 표준 입출력
// 일종의 버퍼
FILE OUTPUT = FDEV_SETUP_STREAM(UART0_Transmit, NULL, _FDEV_SETUP_WRITE);




int main(void)
{
	stdout = &OUTPUT; // 출력 스트림 지정
	UART0_Init();
	DS1302_Init();
	LCD_Init();
	
    // RTC 시계 칩에 날짜와 시간을 설정
	DS1302 myTime;
	myTime.year = 23;
	myTime.month = 7;
	myTime.date = 26;
	myTime.dayOfweek = 4; // 일(1) 월(2) 화(3) 수(7) 목(5) 금(6) 토(7)
	myTime.hour = 14;
	myTime.min = 37;
	myTime.sec = 10;
	
	DS1302_SetTimeDate(myTime);
	
	uint8_t buff[30];
	uint8_t buff_t[30];
	
	
    while (1) 
    {
		DS1302_GetDate(&myTime);
		DS1302_GetTime(&myTime);
		
		printf("20%02d.%02d.%02d  %02d:%02d:%02d \n",
				myTime.year, myTime.month, myTime.date,
				myTime.hour, myTime.min, myTime.sec);
		_delay_ms(500);
		
		sprintf(buff, "DATE:%4d-%02d-%02d", 2000+myTime.year, myTime.month, myTime.date);
		LCD_WriteStringXY(0,0,buff);
		sprintf(buff_t, "TIME : %02d:%02d:%02d", myTime.hour, myTime.min, myTime.sec);
		LCD_WriteStringXY(1,0,buff_t);
		_delay_ms(500);
    }
}

