//#define F_CPU 16000000
//#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/interrupt.h>
//
//
//
//// CTC mode //
//int main(void)
//{
	////DDRB = 0x10;
	////DDRB = 0b00010000; // 세 개 다 같은 의미
    //DDRB = (1<<PINB4); // PORTB의 PIN4 출력 설정
	////TCCR0 = (0<<FOC0);
	//TCCR0 |= (1<<WGM01) | (0<<WGM00); // CTC mode
	//TCCR0 |= (0<<COM01) | (1<<COM00); // Toggle OC0 on compare match
	//TCCR0 |= (1<<CS02) | (0<<CS01) | (0<<CS00); // 64분주
	////TCCR0 = (1<<WGM01) | (1<<COM00) | (1<<CS02);
	////TCCR0 = 0x1C; // 0b0001_1100
	////TCCR0 = 0x1D; // 0b0001_1101
	//OCR0 = 124; // 64분주, 1,000Hz
	////OCR0 = 249; // 128분주, 250Hz
	//
	//
    //while (1) 
    //{
		//while((TIFR & 0x02) == 0);
		//TIFR = 0x02;
		////OCR0 = 124;
		////OCR0 = 0;
    //}
//}





//#define F_CPU 16000000
//#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/interrupt.h>
//
 //// Normal Mode //
//int main()
//{
	//DDRC = 0xff; // Normal mode는 아무 포트에서나 쓸 수 있다.(8개 포트에서 다 반전되는 중)
	//PORTC = 0x00;
	//TCCR0 |= (0<<WGM01) | (0<<WGM00); // Normal mode
	//TCCR0 |= (0<<COM01) | (1<<COM00);
	//TCCR0 |= (1<<CS02) | (0<<CS01) | (1<<CS00);  
	//TCNT0 = 131;
	//
	//while(1)
	//{
		//while((TIFR & 0x01) == 0); // TOV0와 비교해야 하므로, 0x01
		//PORTC = ~PORTC;
		//TCNT0 = 131;
		//TIFR = 0x01; // TOV0 클리어
	//}
//}




//
//#define F_CPU 16000000
//#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/interrupt.h>
//
//// 8bit Fast PWM Mode //
//int main()
//{
	//DDRB = (1<<PINB4);
	//TCCR0 |= (1<<WGM01) | (1<<WGM00); // Fast PWM mode
	//TCCR0 |= (1<<COM01) | (1<<COM00); // 비반전 모드
	//TCCR0 |= (1<<CS02) |(1<<CS01) | (0<<CS00); // 256분주
	//OCR0 = 191; // duty cycle 변경
	//
	//while (1)
	//{
		////while((TIFR & 0x01) == 0);
		////PORTB = ~PORTB;
		////OCR0 = 191;
		////TIFR = 0x01;
		//
		//for (int i=0 ; i < 255 ; i++)
		//{
			//OCR0 = i;
			//_delay_ms(10); 
		//}
	//}	
//}



//
//#define F_CPU 16000000
//#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/interrupt.h>
//
//// 16bit Fast PWM Mode //
//// Timer1 PWM(mode 14) OC1A 100Hz
//int main() // 64분주, 100Hz 만들 것이다.  -> TOP = 2499
//{
	//DDRB = (1<<PINB5); // OC1A PIN
	//TCCR1A |= (1<<WGM11) | (0<<WGM10); // Fast PWM(mode 14) 세팅
	//TCCR1B |= (1<<WGM13) | (1<<WGM12);
	//TCCR1A |= (1<<COM1A1) | (0<<COM1A0); // 비반전모드 & OCRnA 쓸 것이므로
	////TCCR1A |= (1<<COM1B1) | (0<<COM1B0); // OCRnB
	////TCCR1A |= (1<<COM1C1) | (0<<COM1C0); // OCRnC
	//TCCR1B |= (0<<CS12) | (1<<CS11) | (1<<CS10);
	//TCCR1C = 0x00; // default가 0이라 안 써줘도 됨
	//
	//ICR1 = 2499; // 0~2499까지 카운팅하는 것 반복한다는 의미
	//
	//while (1)
	//{
		//for (uint16_t i = 0; i < 2500 ; i++) // int는 4byte, uint16_t도 4byte
		//{
			//OCR1A = i;
			//_delay_ms(5);
		//}
	//}
//}







#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void servo_stop();
void servo_run(uint8_t degree);

// 16bit Fast PWM Mode //
int main() // 64분주, 50Hz
{
	DDRB = (1<<PINB5);
	TCCR1A |= (1<<WGM11) | (0<<WGM10); // Fast PWM(mode 14) 세팅
	TCCR1B |= (1<<WGM13) | (1<<WGM12);
	TCCR1A |= (1<<COM1A1) | (0<<COM1A0);
	TCCR1B |= (0<<CS12) | (1<<CS11) | (1<<CS10);
	TCCR1C = 0x00; // default가 0이라 안 써줘도 됨

	ICR1 = 4999; // 0~2499까지 카운팅하는 것 반복한다는 의미
	
	while (1)
	{
		//OCR1A = 125; // 1ms (0')
		//_delay_ms(500);
		//
		//OCR1A = 375; // 1.5ms (90')
		//_delay_ms(500);
		//
		//OCR1A = 625; // 2ms (180')
		//_delay_ms(500);
		
		//servo_run(0);
		//_delay_ms(1500);
		//servo_run(45);
		//_delay_ms(1500);
		//servo_run(90);
		//_delay_ms(1500);
		//servo_run(180);
		//_delay_ms(1500);
		
		for (int i = 0; i<180 ; i++)
		{
			servo_run(i);
			_delay_ms(15);
		}
		for (int i = 180 ; i>0 ; i--)
		{
			servo_run(i);
			_delay_ms(10);
		}
	}
}




void servo_stop()
{
	TCCR1A &= ~((1<<COM1A1) | (1<<COM1A0)); // PWM 출력 안 되도록
}

void servo_run(uint8_t degree)
{
	// 0도 : 125 / 180도 : 625
	uint16_t degree_value;	
	TCCR1A |= (1<<COM1A1); // PWM 다시 출력되도록
	if (degree_value < 0)
	{
		degree = 0;
	}
	else if(degree > 180)
	{
		degree = 180;
	}
	degree_value = (uint16_t)((degree/180.0)*500 + 125); // 우리가 흔히 쓰는 각도로 표현하기 위한 식
	OCR1A = degree_value;	
}