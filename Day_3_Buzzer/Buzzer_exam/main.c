#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// 6옥타브 음계 //
#define C  0 // 도
#define CC 1
#define D  2 // 레
#define DD 3
#define E  4 // 미
#define F  5 // 파
#define FF 6
#define G  7 // 솔
#define GG 8
#define A  9 // 라
#define AA 10
#define B  11 // 시

#define END -1
#define ON 0
#define OFF 1

volatile uint16_t state;
volatile uint16_t tone;
int table[] = {956, 902, 851, 804, 758, 716, 676, 638, 602, 568, 536, 506};


ISR(TIMER0_OVF_vect)
{
	if(state == OFF)
	{
		PORTB |= (1<<PINB4);
		state = ON;
	}
	else
	{
		PORTB &= ~(1<<PINB4);
		state = OFF;
	}
	TCNT0 = table[tone];
}


int main(void)
{
	DDRB |= (1<<DDRB4);
	TCCR0 = (0<<CS02) | (1<<CS01) | (1<<CS00); // 8분주
	TIMSK = (1<<TOIE0); // 인터럽트 허용
	sei();

	for (int i = 0 ; i < 12 ; i++)
	{
		tone = table[i];
		_delay_ms(500);
	}
	cli();

	while (1)
	{

	}
}