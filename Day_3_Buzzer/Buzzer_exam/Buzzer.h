///*
 //* Buzzer.h
 //*
 //* Created: 2023-07-19 오전 11:39:31
 //*  Author: USER
 //*/ 
//
//
//#ifndef BUZZER_H_
//#define BUZZER_H_
//
//#define F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/interrupt.h>
//
//// 6옥타브 음계 //
//#define C  0 // 도
//#define CC 1
//#define D  2 // 레
//#define DD 3
//#define E  4 // 미
//#define F  5 // 파
//#define FF 6
//#define G  7 // 솔
//#define GG 8
//#define A  9 // 라
//#define AA 10
//#define B  11 // 시
//
//#define END -1
//#define ON 0
//#define OFF 1
//
//volatile uint16_t state;
//volatile uint16_t tone;
//char table[] = {17, 31, 43, 55, 66, 77, 87, 97, 106, 114, 122, 129};
//
//
//void buzzer_init();
//void no_buzzer();
//void play_buzzer();
//void set_buzzer(int note);
//void power_buzzer();
//ISR(TIMER0_OVF_vect);
//
//
//
//#endif /* BUZZER_H_ */