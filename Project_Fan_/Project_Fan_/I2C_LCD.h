﻿/*
 * I2C.h
 *
 * Created: 2023-07-25 오후 3:06:22
 *  Author: USER
 */ 


#ifndef I2C_LCD_H_
#define I2C_LCD_H_

//#define F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
#include "I2C.h"

#define LCD_RS	0 // Register Select
// 제어 레지스터 : 0 , 데이터 레지스터 : 1  
#define LCD_RW	1 // Read/Write 설정하는 레지스터 bit / Read : 1, Write : 0
#define LCD_E	2 // 여기서 2는 LCD board상 2번 핀(E핀)을 뜻한다.
#define LCD_BACKLIGHT	3

#define LCD_DEV_ADDR	(0x27<<1) // I2C LCD 주소 0x27, <<1 : Write 모드 유지

#define COMMAND_DISPLAY_CLEAR	0x01
#define COMMAND_DISPLAY_ON		0x0c
#define COMMAND_DISPLAY_OFF		0x08
#define COMMAND_4_BIT_MODE		0x28
#define COMMAND_ENTRY_MODE		0x06

// 함수 원형 선언 //
void LCD_Data4bit(uint8_t data);
void LCD_EnablePin();
void LCD_WriteCommand(uint8_t commandData);
void LCD_WriteData(uint8_t charData);
void LCD_BackLight();
void LCD_gotoXY(uint8_t row, uint8_t col);
void LCD_WriteString(char *string);
void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string);
void LCD_Init();



#endif /* I2C.LCD_H_ */