/*
 * interrupt_1.c
 *
 * Created: 2023-07-12 오후 2:03:09
 * Author : USER
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// 인터럽트 서비스 루틴 정의 //
ISR(INT4_vect) // 외부 인터럽트 INT4(PORTD-4) IST 정의
{ 
	PORTD ^= (1<<0); // 반전시켜서 보낼 것이다.
}

ISR(INT5_vect)
{
	PORTD ^= (1<<0);
}



int main(void)
{
	// INT4 가 Falling edge(1 0)일 때, 인터럽트 발생
    EICRB |=  (1<<ISC41) | (0<<ISC40); // button4는 누를 때(1->0) 출력
	
	// INT5 Rising edge(1 1)일 때, 인터럽트 발생
	EICRB |= (1<<ISC51) | (1<<ISC50); // button5는 눌렀다가 뗄 때(1->0) 출력
	
	// INT4, INT5 인터럽트 활성화
	EIMSK |= (1<<INT5) | (1<<INT4);
	
	// 버튼 입력 설정
	DDRE &= ~(1<<DDRE5) | ~(1<<DDRE4); // 0으로 설정해야 입력을 받음 
	
	DDRD = 0xff; // LED 출력 설정
	
	sei(); // SREG I[7](I의 8번째 비트) 를 1로 set
	       // 반대 개념은 cli(); -> 0으로 만들어주는 것
	
    while (1) 
    {
    }
}

