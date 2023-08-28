/*
 * IncFile1.h
 *
 * Created: 2023-07-11 오후 3:36:39
 *  Author: USER
 */ 


/*
 * IncFile1.h
 *
 * Created: 2023-07-11 오후 3:36:39
 *  Author: USER
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include <stdint.h>

#define LED_DDR			DDRA // 선언한 얘네들만 바꾸면, 나머지들은 손댈 필요 없음.
#define LED_PORT		PORTA
#define BUTTON_DDR		DDRC
#define BUTTON_PIN		PINC
#define BUTTON_STOP		0	// Stop
#define BUTTON_1stage	1	// 1단 25%
#define BUTTON_2stage	2	// 2단 50%
#define BUTTON_3stage	3	// 3단 100%
#define BUTTON_spin		4	// spin


enum{PUSHED, RELEASED};
enum{NO_ACT, ACT_PUSH, ACT_RELEASED};
// enum은 배열과는 다르게

typedef struct _button{
	volatile uint8_t *ddr; // volatile : 최적화 하지 마라
	volatile uint8_t *pin;
	uint8_t btnPin;
	uint8_t prevState;
}Button;
int spin_cnt;


void Button_init(Button *button, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum);
uint8_t BUTTON_getState(Button *button);
uint8_t BUTTON_spin_getState(Button *button);




#endif /* INCFILE1_H_ */