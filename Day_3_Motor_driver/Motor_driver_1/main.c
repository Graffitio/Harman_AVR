//
//#define F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
//
//
//int main(void)
//{
    //
	//DDRC = 0xff;
		//
    //while (1) 
    //{
//
		//PORTC &= ~(1<<PINC4) | ~(1<<PINC5);
		//_delay_ms(3000);
		//
//
		//PORTC &= ~(1<<PINC4);
		//PORTC |= (1<<PINC5);
		//_delay_ms(3000);
		//
		//PORTC |= (1<<PINC4) | (1<<PINC5);
		//_delay_ms(3000);
		//
		//PORTC &= ~(1<<PINC5);
		//PORTC |= (1<<PINC4);
		//_delay_ms(3000);
    //}
//}




#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRC = 0xff;
	
	while (1)
	{
		PORTC &= ~(1<<PINC4);
		PORTC |= (1<<PINC5);
		_delay_ms(3000);

		//PORTC &= ~(1<<PINC5);
		//PORTC |= (1<<PINC4);
		//_delay_ms(3000);
	}
}