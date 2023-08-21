/*
 * Exam_UART_LED.c
 *
 * Created: 2023-07-26 오후 7:10:29
 * Author : USER
 */ 

//#include "LED_BAR.h"
//#include "UART.h"
//
//FILE OUTPUT = FDEV_SETUP_STREAM(UART_Transmit, NULL, _FDEV_SETUP_WRITE);
//
//char rxBuff[30] = {0,};
//uint8_t rxFlag = 0;
//
//
//ISR(USART0_RX_vect)
//{
	//static uint8_t rxHead = 0;
	//uint8_t rxData = UDR0;
	//
	//if (rxData == '\n' || rxData == '\r')
	//{
		//rxBuff[rxHead] = '\0';
		//rxHead = 0;
		//rxFlag = 1;
	//}
	//else
	//{
		//rxBuff[rxHead] = rxData;
		//rxHead++;
	//}
//}
//
//int main(void)
//{
	//uint8_t LED_Data = 0x01;
	//UART_Init();
	//LED_Init();
	//uint8_t rxData;
	//stdout = &OUTPUT;
	//sei();
    //
    //while (1)
    //{
		//if (rxFlag == 1)
		//{
			//if(rxBuff == 'R')
			//{
				//rxFlag = 0;
				//printf(rxBuff);
				//LED_Right_Shift(&LED_Data);				
			//}
			//else if(rxBuff == 'L')
			//{
				//rxFlag = 0;
				//printf(rxBuff);
				//LED_Left_Shift(&LED_Data);				
			//}			
			//else if(rxBuff == 'B')
			//{
				//rxFlag = 0;
				//printf(rxBuff);
				//LED_Blink(&LED_Data);				
			//}
			//else
			//{ 
				//rxFlag = 0;
				//printf("ERROR");
			//}
			//
			////switch(rxBuff)
			////{
				////case 'R' :
				////LED_Right_Shift(&LED_Data);
				////break;
				////
				////case 'L' :
				////LED_Left_Shift(&LED_Data);
				////break;
			////
				////case 'B' :
				////LED_Blink(&LED_Data);
				////break;
			////
				////default:
				////printf("ERROR");
				////break;
			////}
		//}
    //}	
//}



//ISR 또는 Falling(while문 안에서 돌려) 사용해서

// UART로 L면 LED Bar <-

// R면 ->

// B면 점멸

// Else는 아무 것도 안 하는 것 : 포트 출력을 다 0으로 바꾸면 될 듯


#include "LED_BAR.h"
#include "UART.h"

FILE OUTPUT = FDEV_SETUP_STREAM(UART_Transmit, NULL, _FDEV_SETUP_WRITE);

char rxBuff;
uint8_t rxFlag = 0;


ISR(USART0_RX_vect)
{
	rxBuff = UDR0;
	rxFlag = 1;
}

int main(void)
{
	
	UART_Init();
	LED_BAR_Init();
	stdout = &OUTPUT;
	sei();
	
	while (1)
	{
		if (rxFlag == 1)
		{
			rxFlag = 0;
				
			switch(rxBuff)
			{
				case 'R' : // 문자도 하나의 정수값
				printf("%c", rxBuff);
				LED_Right_Shift(&leds);
				break;
				
				case 'L' :
				printf("%c", rxBuff);
				LED_Left_Shift(&leds);
				break;
				
				case 'B' :
				printf("%c", rxBuff);
				LED_Blink(&leds);
				break;
				
				default:
				printf("Finish");
				LED_Single_On();
				break;
			}
		}
	}
	return 0;
}