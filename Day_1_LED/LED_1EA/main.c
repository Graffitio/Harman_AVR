/*
 * LED_1EA.c
 *
 * Created: 2023-07-10 오전 11:36:53
 * Author : USER
 */ 
//#define F_CPU 16000000UL // 16MHz 이므로(1초에 1,600만 회의 펄스 발생시킴)
//#include <avr/io.h> // AVR 사용 시, 필수인 헤더파일(ATmege128의 모든 정보가 들어 있다.)
//#include <util/delay.h> // 컴파일할 때 미리 알고 있어야될 사전 지식들이 모인 헤더파일
//#include <stdio.h> // 표준 입출력에 대한 헤더파일
//#include <stdint.h> // 인터럽트
//
//int main(void)
//{
    ////DDRC = 0xff; // DDR 포트들의 bit들을 전부 1로 만들어 줌(0b1111_1111) -> 출력으로 설정
				   //// 포트C 전체를 출력으로 설정
	//DDRC0 = 0x01;  // 이렇게 해야됨
	               //// 우리가 사용하는 포트 레지스터는 C-0, 해당 포트만 출력으로 변경시켜줘도 됨.
				   //// 나머지는 default 또는 initial value로 가져가겠다.(대부분의 initial value는 0)
				   //// DDRC0 = 0x01 == DDRC 0x01
    //while (1) 
    //{
		//PORTC = 0xff; // 포트C를 High로 설정
		//_delay_ms(500); // 0.5sec 대기
		//PORTC = 0x00; // 포트C를 Low로 설정
		//_delay_ms(500); // 0.5sec 대기
    //}
//}
//


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint>

int main()
{
	DDRC = 0x01; // C포트의 0번째 핀을 출력으로 사용하겠다.
	
	while (1)
	{
		PORTC = 0xff; // 포트C를 high로 설정
		_delay_ms(500);
		PORTC = 0x00;
		_delay_ms(500);
	}
}
