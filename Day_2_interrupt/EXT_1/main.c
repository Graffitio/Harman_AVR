/*
 * EXT_1.c
 *
 * Created: 2023-07-12 오후 2:42:08
 * Author : USER
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t ledShift = 0xfe; // 1111 1110 으로 시작

ISR(INT4_vect)
{
	ledShift = ledShift << 1; // 함수 호출 시, led 한 칸 좌시프트
	ledShift = ledShift | 0x01; // 한 칸 시프트하면, 0bit가 0으로 채워지므로 0x01과 OR 연산
	
	if (ledShift == 0xff)
	{
		ledShift = 0xfe;
	}
	PORTD = ledShift;
}



int main(void)
{
	DDRD = 0xff;
	DDRE &= ~(1<<DDRE4);
	
	EICRB |= (1<<ISC41) | (0<<ISC40); // falling edge일 때 동작
	EIMSK |= (1<<INT4);
	
	sei();
	
    while (1) 
    {
    }
}

