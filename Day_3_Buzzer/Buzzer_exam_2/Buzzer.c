/*
 * Buzzer.c
 *
 * Created: 2023-07-19 오전 11:39:39
 *  Author: USER
 */ 

#include "Buzzer.h"

void buzzer_init()
{
	DDRB |= (1<<DDRB5); // OC1A, OC1B 쓸 거임
	TCCR1B |= (0<<CS12) | (1<<CS11) | (0<<CS10); // 8분주
	TCCR1B |= (0<<WGM13) | (1<<WGM12); // Wave genetation : CTC mode
	TCCR1A |= (0<<WGM11) | (0<<WGM10);
}

void no_buzzer()
{
	TCCR1A &= ~((1<<COM1A1) | (1<<COM1A0)); // 출력x
}

void play_buzzer()
{
	TCCR1A |= (0<<COM1A1) | (1<<COM1A0); // 출력o
}

void set_buzzer(int note)
{
	OCR1A = 1000000 / note;
}

void power_buzzer()
{
	play_buzzer();
	set_buzzer(478); // OCR값을 조금씩 줄여가면서 측정
	_delay_ms(1000);
	set_buzzer(451);
	_delay_ms(1000);
	set_buzzer(426);
	_delay_ms(1000);
	set_buzzer(402);
	_delay_ms(1000);
	set_buzzer(379);
	_delay_ms(1000);
	set_buzzer(358);
	_delay_ms(1000);
	no_buzzer();
}
