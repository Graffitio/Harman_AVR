/*
 * UART.h
 *
 * Created: 2023-07-26 오후 7:38:26
 *  Author: USER
 */ 


#ifndef UART_H_
#define UART_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>


void UART_Init();
void UART_Transmit(char data);
unsigned UART_Receive();


#endif /* UART_H_ */