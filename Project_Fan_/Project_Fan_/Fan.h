/*
 * Fan.h
 *
 * Created: 2023-08-28 오전 11:26:50
 *  Author: USER
 */ 


#ifndef FAN_H_
#define FAN_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Button_structure.h"
#include "I2C_LCD.h"
#include "UART_2.h"

Button btnStop;
Button btn_1stage;
Button btn_2stage;
Button btn_3stage;
Button btn_spin;

void Fan_Init();
void Fan_Stage();
void Fan_Start_signal();
void Spin_stop();
void Spin_start(uint8_t degree);


#endif /* FAN_H_ */