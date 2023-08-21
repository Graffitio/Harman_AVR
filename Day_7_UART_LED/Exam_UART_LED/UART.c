/*
 * UART.c
 *
 * Created: 2023-07-26 오후 7:38:18
 *  Author: USER
 */ 

#include "UART.h"


void UART_Init()
{
	UBRR0H = 0x00;
	UBRR0L = 0xcf; // 9600bps, 2배속
	
	UCSR0A = (1<<U2X0); // 2배속 모드 set
	
	UCSR0B |= (1<<RXEN0); // 수신 가능(RX PIN 허용)
	UCSR0B |= (1<<TXEN0); // 송신 가능(TX PIN 허용)
	UCSR0B |= (1<<RXCIE0); // 수신 Interrupt Enable
}


void UART_Transmit(char data)
{
	while(!((UCSR0A) & (1<<UDRE0))); // UDR이 비어있다면, 다음 문장으로 넘어감
	UDR0 = data;
}

unsigned UART_Receive()
{
	while(!((UCSR0A) & (1<<RXC0)));
	return UDR0;
}