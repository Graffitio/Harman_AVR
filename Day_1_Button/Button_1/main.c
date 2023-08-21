/*
 * Button_1.c
 *
 * Created: 2023-07-11 오전 11:12:25
 * Author : USER
 */ 
//#define F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdio.h>
//
//// 버튼으로 LED 1EA on/off // 
//int main(void)
//{
	//DDRD = 0xff; // LED 연결된 포트 출력
	//DDRC &= ~(1<<0); // Button 연결된 0번 핀 입력으로 설정
	//// PORTC |= (1<<0); // PORTC의 0번 핀에 내부 풀업 활정
    //while (1) 
    //{
		//if(PINC & (1 << 0)) // 버튼이 안 눌리면
		//{
			//PORTD &= ~(1 << 0);
		//}
		//else
		//{
			//PORTD |= (1 << 0);
		//}
    //}
//}





//#define F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdio.h>
//
//char shiftLeft(char pattern)
//{
	//char newPattern = ((pattern << 1) | (pattern >> 7));
	//return newPattern;
//}
//
//int main()
//{
	//DDRD = 0xff;
	//DDRC &= ~(1 << PINC0);
	//char pattern = 0x01;
	//PORTD = pattern;
	//
	//while (1)
	//{
		//if((~PINC & (1<<PINC0)))
		//{
			//pattern = shiftLeft(pattern);
			//PORTD = pattern;
			//_delay_ms(200);
		//}
	//}
//}





//#define F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdio.h>
//
//// 버튼 누르면 시프트(1), 반대로 돌고(2), 플래그 세우고(3), 꺼지게끔(4) //
//
//int main() 
//{
	//DDRD = 0xff;
	//DDRC &= ~(1<<PINC0);	
	//
	//uint8_t ledData = 0x01;
	//uint8_t buttonData;
	//int flag = 0;
	//PORTD = 0x00; // 꺼진 상태로 출발
		//
	//while(1)
	//{
		//buttonData = PINC;
		//if((buttonData & (1<<0)) == 0) // 0번 버튼
		//{
			//PORTD = ledData;
			//ledData = (ledData >> 7) | (ledData << 1);
			//_delay_ms(200);
		//}
		//if ((buttonData & (1<<1)) == 0) // 1번 버튼
		//{
			//PORTD = ledData;
			//ledData = (ledData >> 1) | (ledData << 7);
			//_delay_ms(200);
		//}
		//if ((buttonData & (1<<2)) == 0)
		//{
			//flag = 1;
		//}
		//if((buttonData & (1<<3)) == 0)
		//{
			//PORTD = 0xff;
			//_delay_ms(200);
			//PORTD = 0x00;
			//_delay_ms(200);
			//if ((buttonData & (1<<3)) == 0)
			//{
				//flag = 0;
			//}
		//}
	//}
//}






//#define F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdio.h>
//
//// 버튼 누르면 시프트(1), 반대로 돌고(2), 플래그 세우고(3), 꺼지게끔(4) //
//
//int main()
//{
	//DDRD = 0xff;
	//DDRC &= ~(1<<PINC0);
	//
	//uint8_t ledData = 0x01;
	//uint8_t buttonData;
	//int flag = 0;
	//PORTD = 0x00; // 꺼진 상태로 출발
	//
	//while(1)
	//{
		//buttonData = PINC;
		//if((buttonData & (1<<0)) == 0) // 0번 버튼
		//{
			//PORTD = ledData;
			//_delay_ms(50); // 소프트웨어적으로 만든 간단한 debouncing, Debounce code 
			//ledData = (ledData >> 7) | (ledData << 1);
			//_delay_ms(100); // 100ms로 바꾸면, 1번 눌렀는데 2칸씩 가버린다.(bouncing 발생)
		////}
		//if ((buttonData & (1<<1)) == 0) // 1번 버튼
		//{
			//PORTD = ledData;
			////_delay_ms(50);
			//ledData = (ledData >> 1) | (ledData << 7);
			//_delay_ms(100);
		//}
		//if ((buttonData & (1<<2)) == 0)
		//{
			//flag = 1;
		//}
		//if((buttonData & (1<<3)) == 0)
		//{
			//PORTD = 0xff;
			//_delay_ms(200);
			//PORTD = 0x00;
			//_delay_ms(200);
			//if ((buttonData & (1<<3)) == 0)
			//{
				//flag = 0;
			//}
		//}
	//}
//}


//#define F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdio.h>
//
//// 버튼 누르면 시프트(1), 반대로 돌고(2), 플래그 세우고(3), 꺼지게끔(4) //
//
//int main()
//{
	//DDRD = 0xff;
	//DDRC &= ~(1<<PINC0);
	//
	//uint8_t ledData = 0x01;
	//uint8_t buttonData;
	//int flag = 0;
	//PORTD = 0x00; // 꺼진 상태로 출발
	//
	//while(1)
	//{
		//buttonData = PINC;
		//if((buttonData & (1<<0)) == 0) // if문을 하나 더 써서, 눌렀냐?(60ms) 진짜 눌렀어? -> 출력 // 이렇게 디바운싱하면 더 잘 잡힌다.
		//{
			//_delay_ms(60);
			//if((buttonData & (1<<0)) == 0) // 0번 버튼
			//{
				//PORTD = ledData;
				//ledData = (ledData >> 7) | (ledData << 1);
				//_delay_ms(100); // 100ms로 바꾸면, 1번 눌렀는데 2칸씩 가버린다.(bouncing 발생)
			//}
		//}
		//if ((buttonData & (1<<1)) == 0)
		//{
			//_delay_ms(60);
			//if ((buttonData & (1<<1)) == 0) // 1번 버튼
			//{
				//PORTD = ledData;
				//ledData = (ledData >> 1) | (ledData << 7);
				//_delay_ms(100);
			//}
		//}
		//if ((buttonData & (1<<2)) == 0)
		//{
			//flag = 1;
		//}
		//if((buttonData & (1<<3)) == 0)
		//{
			//PORTD = 0xff;
			//_delay_ms(200);
			//PORTD = 0x00;
			//_delay_ms(200);
			//if ((buttonData & (1<<3)) == 0)
			//{
				//flag = 0;
			//}
		//}
	//}
//}