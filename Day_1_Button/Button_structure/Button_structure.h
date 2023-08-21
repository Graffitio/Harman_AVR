/*
 * IncFile1.h
 *
 * Created: 2023-07-11 오후 3:36:39
 *  Author: USER
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include <stdint.h>

#define LED_DDR			DDRD // 선언한 얘네들만 바꾸면, 나머지들은 손댈 필요 없음.
#define LED_PORT		PORTD
#define BUTTON_DDR		DDRC
#define BUTTON_PIN		PINC
#define BUTTON_ON		0
#define BUTTON_OFF		1
#define BUTTON_TOGGLE	2


enum{PUSHED, RELEASED};
enum{NO_ACT, ACT_PUSH, ACT_RELEASED};
// enum은 배열과는 다르게


typedef struct _button{
	volatile uint8_t *ddr; // volatile : 최적화 하지 마라
	volatile uint8_t *pin;
	uint8_t btnPin;
	uint8_t prevState;
}Button;



void Button_init(Button *button, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum);
uint8_t BUTTON_getState(Button *button);




#endif /* INCFILE1_H_ */