/*
 * EXT_2.c
 *
 * Created: 2023-07-12 오후 3:17:16
 * Author : USER
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// 이제까지는 디바운스 코드를 안 썼다.
// while문은 계속 돌아가는 것이지만, 그 외부의 함수는 1번 실행하고 초기화된다.
// 따라서 버튼을 작동시켰을 때 사용되는 디바운스 코드는 while문 안으로 들어가야 한다.

volatile uint8_t ledShift = 0xfe;
uint8_t buttonPressed = 0; // 초기값은 0

ISR(INT4_vect)
{
	buttonPressed = 1; // ISR 함수가 호출되면 buttonPressed 상태만 변화시킴(반전)
}


int main(void)
{
    DDRD = 0xff; // 출력으로 설정
	DDRE &= ~(1<<DDRE4); // 4번 핀 입력 설정
	PORTD = ledShift;  // 전역변수 선언해놨으니 사용 가능 
	
	// 4번 핀을 인터럽트로 사용하기 위한 준비 //
	EICRB |= (1<<ISC41) | (0<<ISC40);
	EIMSK |= (1<<INT4);
	sei();
	
	
	
    while (1) 
    {
		if (buttonPressed) // buttonPressed 눌린 상태라면 = 인터럽트가 발생하였다면?
		{
			_delay_ms(50);
			if (!(PINE & (1<<PINE4))) // 버튼이 계속 눌려져 있는지 확인
			                          // 버튼을 누르는 순간, pin4의 입력이 1->0으로 바뀜 PINE = xxx0xxxx (x = N/A, PIN의 초기값은 N/A)
									  // 1<<PINE4 : 00010000
									  // 둘이 AND연산하면, 00000000 = 0
									  // ∴ 버튼이 눌려있다면? 이라는 의미가 된다.
			{
				ledShift = (ledShift << 1 ) | 0x01;
				if (ledShift == 0xff)
				{
					ledShift = 0xfe;
				}
				PORTD = ledShift;
			}
			buttonPressed = 0;
		}
    }
}

