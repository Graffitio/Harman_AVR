/*
 * UART_2.c
 *
 * Created: 2023-07-26 오전 10:32:22
 * Author : USER
 */ 

#define F_CPU 16000000UL
#include "UART_2.h"

// 출력 스트림 설정 <stdio.h>에 있는 표준 입출력
// 일종의 버퍼
FILE OUTPUT = FDEV_SETUP_STREAM(UART0_Transmit, NULL, _FDEV_SETUP_WRITE);

char rxBuff[100] = {0,}; // 수신 버퍼
uint8_t rxFlag = 0; // 수신 완료 플래그 설정

ISR(USART0_RX_vect) // 수신 interrupt 핸들러
{
	static uint8_t rxHead = 0; // 수신 데이터 인덱스
	uint8_t rxData = UDR0; // 인터럽트 발생하면 수신된 데이터를 rxData에 넣어라.
	
	if (rxData == '\n' || rxData == '\r') // 수신 데이터기 개행이나 리턴이면
	{
		rxBuff[rxHead] = '\0'; // 수신된 문자열 만지막에 NULL 문자 추가
		rxHead = 0; // 인덱스 초기화
		rxFlag = 1; // 문자열 수신 완료되었다고 플래그 세움
	}
	else // 개행이나 리턴이 아니면
	{
		rxBuff[rxHead] = rxData; // 그렇지 않으면, 버퍼에 데이터 계속 추가
		rxHead++; // 인덱스 증가
	}
}


int main(void)
{
	UART0_Init();
	uint8_t rxData; // 수신 데이터
	stdout = &OUTPUT; // 출력 스트림 지정
	// stdout : 출력 스트림을 지정해주는 포인터
	sei(); // 인터럽트 쓸 거니까 전역 인터럽트 레지스터 허용
    
    while (1) 
    {
		if (rxFlag == 1) // 문자열 수신이 완료되면,
		{
			rxFlag = 0;
			printf(rxBuff); // rxBuff를 출력해라
		}
    }
}

