
#include "LCD.h"

//int main(void)
//{
	//LCD_Init();
	//
	//LCD_gotoXY(0,0);
	//LCD_WriteString("Hello LCD");
	//LCD_gotoXY(1,0);
	//LCD_WriteString("Good AVR");
   //
    //while (1) 
    //{
    //}
//}



//int main(void)
//{
	//LCD_Init();
	//
//
	//
	//while (1)
	//{
		//LCD_gotoXY(0,0);
		//LCD_WriteString("Hello LCD!");
		//LCD_gotoXY(1,0);
		//LCD_WriteString("Good AVR!");
		//_delay_ms(500);
		//
		//LCD_WriteCommand(COMMAND_DISPLAY_OFF);
		//LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
		//LCD_WriteCommand(COMMAND_DISPLAY_ON);
		//LCD_WriteCommand(COMMAND_ENTRY_MODE);
		//
	//}
//}


int main()
{
	char buff[30];
	LCD_Init();
	sprintf(buff, "Hello AVR"); // stdio.h 헤더파일 추가해줄 것
	LCD_WritestringXY(0, 0, buff);
	int count = 0;
	while (1)
	{
		sprintf(buff, "count : %d", count++);
		LCD_WritestringXY(1, 0, buff);
		_delay_ms(30);
	}
}
