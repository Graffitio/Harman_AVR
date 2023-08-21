/*
 * ADC_LCD.c
 *
 * Created: 2023-08-21 오후 3:29:09
 * Author : USER
 */ 

#include "I2C_LCD.h"

void ADC_Init()
{
	ADMUX |= (1<<REFS0); // AVCC 기준 전압 설정
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); // 분주비 : 128
	// ADCSRA |= 0x07; // 이렇게 써줘도 됨
	ADCSRA |= (1<<ADEN); // ADC 활성화
	ADCSRA &= ~(1<<ADFR); // 단일 running mode
}

int read_ADC(uint8_t channel)
{
	ADMUX = ((ADMUX & 0xE0) | channel); // 단일 입력 채널 선택
	ADCSRA |= (1<<ADSC); // 변환 시작
	while (!(ADCSRA & (1<<ADIF))); // 변환 종료 대기
	
	return ADC; // 10 bit값 변환
}


int main(void)
{
	int read;
	char buff[30];
	
	ADC_Init();
	LCD_Init();
	
	while (1)
	{
		read = read_ADC(0);
		sprintf(buff, "CDS : %-5d", read);
		LCD_WriteStringXY(0, 0, buff);
		read = read_ADC(1);
		sprintf(buff, "REG : %-5d", read);
		LCD_WriteStringXY(1, 0, buff);
		_delay_ms(1000);
	}
}

