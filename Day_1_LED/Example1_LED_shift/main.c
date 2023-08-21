/*
 * Example1_LED_shift.c
 *
 * Created: 2023-07-11 오전 9:44:20
 * Author : USER
 */ 
//#define  F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdio.h>
//#include "LED.h"
//
//#define LED_DDR  DDRD
//#define LED_PORT PORTD
//
//
//int main(void)
//{
	//LED_DDR = 0xff;
//
    //while (1) 
    //{
		//for(uint8_t i = 0 ; i < 4 ; i++)
		//{
			//LED_PORT = ((0x01 << i) | (0x80 >> i));
			//_delay_ms(200);
		//}
		//for(uint8_t i = 0 ; i < 4 ; i++)
		//{
			//LED_PORT = ((0x08 >> i) | (0x20 << i));
			//_delay_ms(200);
		//}
    //}
//}




//#define  F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdio.h>
////#include "LED.h"
//
//int main()
//{
	//DDRD = 0xff;
	//unsigned char L = 0x01; // 0000 0001
	//unsigned char R = 0x80; // 0000 1000
	//
	//while(1)
	//{
		//PORTD = L | R;
		//L <<= 1;
		//if(L==0)
		//{
			//L=0x01;
		//}
		//R >>= 1;
		//if(R==0)
		//{
			//R = 0x80;
		//}
		//_delay_ms(300);		
	//}
//}



//#define  F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdio.h>
////#include "LED.h"
//
//#define LED_DDR  DDRD
//#define LED_PORT PORTD
//
//void GPIO_Output(uint8_t *data)
//{
	//LED_PORT = data;
//}
//
//void ledInit()
//{
	//LED_DDR = 0xff;
//}
//
//void ledDirShift(uint8_t i, uint8_t *data)
//{
	//*data = (1 << i) | (1 << (7-i));
//}
//
//int main()
//{
	//ledInit();
	//uint8_t ledData = 0x81; // 1000 0001
 	//
	 //while(1)
	 //{
		 //for(int i = 0 ; i < 8 ; i++)
		 //{
			 //ledDirShift(i, &ledData);
			 //GPIO_Output(ledData);
			 //_delay_ms(300);
		 //}
	 //}
//}




//#define  F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdio.h>
//
//uint8_t ledArr[]={
	//0x81, // 1000 0001
	//0x42, // 0100 0010
	//0x24, // 0010 0100
	//0x18, // 0001 1000
	//0x24, // 0010 0100
	//0x42,
	//0x81
	//};
	//
//int main()
//{
	//DDRD = 0xff;
	//
	//while(1)
	//{
		//for(int i = 0 ; i < 8 ; i++)
		//{
			//PORTD = ledArr[i];
			//_delay_ms(200);
		//}
	//}
//}





// 1000 0000
// 1100 0000
// 1110 0000
// 1111 0000
// 1111 1000
// ......
// 0000 0011
// 0000 0001

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
	

int main()
{
	DDRD = 0xff;
	PORTD = 0x00; // 꺼진 상태로 출발
	uint8_t led_data = 0x01;
	
	while (1)
	{
		for (int i = 0 ; i < 8 ; i++)
		{
			PORTD = led_data;
			led_data |= (1 << i);
			_delay_ms(300);
		}
		for(int i = 0 ; i < 8 ; i++)
		{
			PORTD = led_data;
			led_data &= ~(1 << i);
			_delay_ms(300); 			
		}
			
	}
}