/*
 * Timer_1.c
 *
 * Created: 2023-07-12 오전 10:56:14
 * Author : USER
 */ 
//#define F_CPU 160000000UL
//#include <avr/io.h>
//#include <avr/interrupt.h> // 인터럽트 사용을 위한 헤더파일
//#include <stdio.h>
//
//int cnt; // 카운트 값을 저장할 변수 선언
//
//ISR(TIMER0_OVF_vect){ // 타이머/카운터 0번, 오버플로우 인터럽트 서비스 루틴
	//cnt++;
	//TCNT0 = 131; // 약 2ms를 만들기 위한 초기값
	//
	//if(cnt == 500) // 500번째 인터럽트 발생 시 LED 출력을 변경함. 약 1초
	//{
		//PORTD = ~PORTD; // 출력 반전
		//cnt = 0;
	//}	
//}
//
//
//int main(void)
//{
    //DDRD = 0xff;
	//PORTD = 0x00; // 다 꺼진 것을 시작
	//
	////256 분주 //
	//TCCR0 = (1<<CS02) | (1<<CS01) | (0<<CS00); // 분주를 해야 하니까 CS01 02 00 에  값을 대입
	//
	//// Overflow interrupt enable //
	//TIMSK = (1<<TOIE0);
	//
	//sei(); // 인터럽트를 사용하기 위해, 글로벌 인터럽트를 활성화시켜줘야 한다.
	//
	//
    //while (1) 
    //{
    //}
//}




#define F_CPU 160000000UL
#include <avr/io.h>
#include <avr/interrupt.h> // 인터럽트 사용을 위한 헤더파일
#include <stdio.h>

int cnt; // 카운트 값을 저장할 변수 선언

ISR(TIMER0_OVF_vect){ // 타이머/카운터 0번, 오버플로우 인터럽트 서비스 루틴
	cnt++;
	TCNT0 = 131; // 약 2ms를 만들기 위한 초기값
	
	if(cnt == 500) // 500번째 인터럽트 발생 시 LED 출력을 변경함. 약 1초
	{
		PORTD = ~PORTD; // 출력 반전
		cnt = 0;
	}
}


int main(void)
{
	DDRD = 0xff;
	//PORTD = 0x00; // 다 꺼진 것을 시작
	PORTD = 0xaa; // 모양을 좀 더 이쁘게
	
	//256 분주 //
	TCCR0 = (1<<CS02) | (1<<CS01) | (0<<CS00); // 분주를 해야 하니까 CS01 02 00 에  값을 대입
	
	// Overflow interrupt enable //
	TIMSK = (1<<TOIE0);
	
	sei(); // 인터럽트를 사용하기 위해, 글로벌 인터럽트를 활성화시켜줘야 한다.
	
	
	while (1)
	{
	}
}

