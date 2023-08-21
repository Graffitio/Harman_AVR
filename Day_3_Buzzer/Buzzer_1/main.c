//#include "Buzzer.h"
//
//
//int main(void)
//{
	//buzzer_init();
	//TCCR0 |= (0<<CS02) | (1<<CS01) | (0<<CS00);
	//TCCR0 |= (1<<WGM01) | (1<<WGM00);
	//TCCR0 |= (1<<COM01) | (0<<COM00);
	//OCR0 = 100;
	//DDRB |= (1<<DDRB4);
//
    //while (1) 
    //{
		//power_buzzer();
		//OCR0 += 10;
		//if(OCR0 >= 250)
		//{
			//OCR0 = 0;
		//}
		//_delay_ms(200);
		//
//
    //}
//}


#include "Buzzer.h"


int main(void)
{
	buzzer_init();
	DDRC = 0xff;
	TCCR0 |= (0<<CS02) | (1<<CS01) | (0<<CS00);
	TCCR0 |= (1<<WGM01) | (1<<WGM00);
	TCCR0 |= (1<<COM01) | (0<<COM00);
	OCR0 = 100;
	DDRB |= (1<<DDRB4);

	
	while (1)
	{
		//power_buzzer();
		PORTC &= ~(1<<PINC5);
		PORTC |= (1<<PINC4);
		
		OCR0 += 10;
		if(OCR0 >= 250)
		{
			OCR0 = 0;
		}
		_delay_ms(200);
	}
}
		