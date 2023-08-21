/*
 * LCD_4bit.h
 *
 * Created: 2023-07-25 오후 12:15:12
 *  Author: USER
 */ 


#ifndef LCD_4BIT_H_
#define LCD_4BIT_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


#define LCD_DATA_DDR	DDRC
#define LCD_DATA_PORT	PORTC // 데이터 포트
#define LCD_DATA_PIN	PINC
#define LCD_RS_DDR		DDRB // 제어 핀 연결
#define LCD_RW_DDR		DDRB
#define LCD_E_DDR		DDRB
#define LCD_RS_PORT		PORTB
#define LCD_RW_PORT		PORTB
#define LCD_E_PORT		PORTB
#define LCD_RS			5
#define LCD_RW			6
#define LCD_E			7


// COMAND
#define COMMAND_DISPLAY_CLEAR	0x01
#define COMMAND_DISPLAY_ON		0x0C // 화면 ON, 커서 OFF, 커서 점멸 OFF
#define COMMAND_DISPLAY_OFF		0x08 // 화면 OFF, 커서 OFF, 커서 점멸 OFF
#define COMMAND_ENTRY_MODE		0x06 // 커서 우측 이동, 화면 이동 없음
#define COMMAND_8_BIT_MODE		0x38 // 8비트, 화면 2행, 5x8 Font
#define COMMAND_4_BIT_MODE		0x28 // 4비트, 화면 1행, 5x11 Font


// 함수 원형 선언
void LCD_Data(uint8_t data);
void LCD_Data4bit(uint8_t data);
void LCD_EnablePin();
void LCD_WritePin();
void LCD_ReadPin();
void LCD_WriteCommand(uint8_t commandData);
void LCD_WriteData(uint8_t charData);
void LCD_gotoXY(uint8_t row, uint8_t col);
void LCD_WriteString(char *string);
void LCD_WritestringXY(uint8_t row, uint8_t col, char *string);
void LCD_Init();
void LCD_Data4bit_Init(uint8_t data);



#endif /* LCD_4BIT_H_ */