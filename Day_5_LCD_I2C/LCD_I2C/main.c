/*
 * LCD_I2C.c
 *
 * Created: 2023-07-25 오후 2:04:04
 * Author : USER
 */ 

#include "I2C_LCD.h"


int main(void)
{
    uint16_t count = 0;
	char buff[30];
	
	LCD_Init();
	LCD_WriteStringXY(0,0,"Hello ATmega128");

    while (1) 
    {
		sprintf(buff, "count : %-5d", count++);
		LCD_WriteStringXY(1, 0, buff);
		_delay_ms(500);
    }
}

