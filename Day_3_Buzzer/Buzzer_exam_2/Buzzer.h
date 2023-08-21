/*
 * Buzzer.h
 *
 * Created: 2023-07-19 오전 11:39:31
 *  Author: USER
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


void buzzer_init();
void no_buzzer();
void play_buzzer();
void set_buzzer(int note);
void power_buzzer();



#endif /* BUZZER_H_ */