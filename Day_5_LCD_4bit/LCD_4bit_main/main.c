/*
 * LCD_4bit_main.c
 *
 * Created: 2023-07-25 오후 12:14:47
 * Author : USER
 */ 

#include "LCD_4bit.h"

// LCD 4bit //
// 4bit는 직렬 방식으로 2번 보낸다. // 
int main(void)
{
    char buff[30];
	LCD_Init();
	
	sprintf(buff, "Hello AVR");
	LCD_WritestringXY(0,0,buff);
	int count = 0;
	
	
    while (1) 
    {
		sprintf(buff, "count : %d", count++);
		LCD_WritestringXY(1,0,buff);
		_delay_ms(300);
    }
}

