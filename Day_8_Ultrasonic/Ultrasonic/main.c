/*
 * UltraSonic_LCD
 *
 * Created: 2023-08-21 오전 9:20:26
 * Author : USER
 */ 

// 클럭 주파수 설정(16MHz)
#define F_CPU 16000000UL
#include "UART_2.h"

// 출력 스트림 설정(stdio.h에 있는 표준 입출력)
// 이 스트림은 출력용 버퍼 역할을 한다.
FILE OUTPUT = FDEV_SETUP_STREAM(UART0_Transmit, NULL, _FDEV_SETUP_WRITE);

#define PRESCALER	1024 // 타이머 분주비 설정

// 16 bit Timer1 초기화 함수
void Timer_init()
{
	// Timer1의 분주비 설정(1024)
	TCCR1B |= (1<<CS12) | (1<<CS10);
}

// 거리 측정 함수
uint8_t measure_distance()
{
	// 트리거 핀으로 펄스 출력(10us TTL)
	PORTB &= ~(1<<PORTB1); // Low 시작
	_delay_us(1);
	PORTB |= (1<<PORTB1); // High 출력
	_delay_us(10);
	PORTB &= ~(1<<PORTB1); // Low 출력
	
	// Echo pin이 High가 될 때까지 대기
	TCNT1 = 0;
	while (!(PINB & (1<<PINB0))) // 0번 핀 
	if (TCNT1 > 65000) return 0; // 장애물이 없는 경우(얘가 잴 수 있는 건 2~400cm)
	
	// Echo pin이 Low가 될 때까지 시간 측정
	TCNT1 = 0;
	while(PINB & 1<<PINB0)
	{
		if (TCNT1 > 65000)
		{
			TCNT1 = 0;
			break;
		}
	}
	
	// Echo Pin의 펄스폭을 마이크로초로 계산
	double pulse_width = 1000000.0 * TCNT1 * PRESCALER / F_CPU;
	
	// 계산된 펄스의 폭을 cm로 변환한 뒤 반환
	return pulse_width / 58;
}


int main(void)
{
    uint8_t distance;
	char buff[30];
	
	// 표준 출력을 UART로 설정
	stdout = &OUTPUT;
	UART0_Init();
	
	DDRB |= (1<<PORTB1); // 트리거 핀을 출력으로 설정 (PORTB1)
	DDRB &= ~(1<<PORTB0); // 에코 핀을 입력으로 설정 (PORTB0)
	
	Timer_init();
	LCD_Init();
	LCD_WriteStringXY(0, 0, "UltraSonic Test");
	
    while (1) 
    {
		distance = measure_distance(); // 거리 측정
		// 측정된 거리를 문자열로 변환하여 버퍼에 저장
		sprintf(buff, "Distance : %-3dcm\r\n", distance);
		// LCD에 버퍼 내용 출력
		LCD_WriteStringXY(1, 0, buff);
		_delay_ms(1000);
    }
}



//uint8_t measure_distance()
//{
	//// 트리거 핀으로 펄스 출력(10us TTL)
	//PORTB &= ~(1<<PORTB1); // Low 시작
	//_delay_us(1);
	//PORTB |= (1<<PORTB1); // High 출력
	//_delay_us(10);
	//PORTB &= ~(1<<PORTB1); // Low 출력
	//
	//// Echo pin이 High가 될 때까지 대기
	//TCNT1 = 0;
	//while (!(PINB & 0x01)) // 0번 핀
	//if (TCNT1 > 65000) return 0; // 장애물이 없는 경우(얘가 잴 수 있는 건 2~400cm)
	//
	//// Echo pin이 Low가 될 때까지 시간 측정
	//TCNT1 = 0;
	//while(PINB & 0x01)
	//{
		//if (TCNT1 > 65000)
		//{
			//TCNT1 = 0;
			//break;
		//}
	//}
	//
	//// Echo Pin의 펄스폭을 마이크로초로 계산
	//double pulse_width = 1000000.0 * TCNT1 * PRESCALER / F_CPU;
	//
	//// 계산된 펄스의 폭을 cm로 변환한 뒤 반환
	//return pulse_width / 58;
//}
//
//
//int main(void)
//{
	//uint8_t distance;
	//char buff[30];
	//
	//stdout = &OUTPUT;
	//UART0_Init();
	//
	//DDRB |= 0x02; // 트리거핀 출력 설정()
	//DDRB &= 0xFE; // 에코 핀 입력 설정(PORTD PIN0)
	//
	////DDRD |= (1<<PIND5); // 트리거핀 출력 설정()
	////DDRD &= ~(1<<PIND4); // 에코 핀 입력 설정(PORTD PIN0)
	//
	//Timer_init();
	//LCD_Init();
	//LCD_WriteStringXY(0, 0, "UltraSonic Test");
	//
	//while (1)
	//{
		//distance = measure_distance(); // 거리 측정
		//sprintf(buff, "Distance : %-3dcm\r\n", distance);
		//LCD_WriteStringXY(1, 0, buff);
		////printf("Distance : %d cm\r\n", distance);
		//_delay_ms(1000);
	//}
//}