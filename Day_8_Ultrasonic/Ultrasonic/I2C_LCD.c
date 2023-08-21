/*
 * I2C_LCD.c
 *
 * Created: 2023-07-25 오후 3:06:06
 *  Author: USER
 */ 

#include "I2C_LCD.h"

uint8_t I2C_LCD_Data;

void LCD_Data4bit(uint8_t data)
{
	I2C_LCD_Data = (I2C_LCD_Data & 0x0f) | (data & 0xf0); // 상위 4bit 출력
	// 이전 상위 비트는 다 날라감 | data의 상위 비트는 살림 
	LCD_EnablePin();
	I2C_LCD_Data = (I2C_LCD_Data & 0x0f) | ((data & 0x0f)<<4); // 하위 4bit
	LCD_EnablePin();
	// 상위 4bit 받고 -> Enable해서 출력하고 -> 하위 4bit 받고 상위로 시프트하고 -> Enabla해서 출력하고
	// [7:4] 핀만 사용해서 반반 나눠서 출력하면, 총 8bit를 출력할 수 있다.
}

void LCD_EnablePin()
{
	I2C_LCD_Data &= ~(1<<LCD_E); // E low 설정
	I2C_TxByte(LCD_DEV_ADDR, I2C_LCD_Data);
	
	I2C_LCD_Data |= (1<<LCD_E); // High 설정
	I2C_TxByte(LCD_DEV_ADDR, I2C_LCD_Data);
	
	I2C_LCD_Data &= ~(1<<LCD_E); // E low 설정
	I2C_TxByte(LCD_DEV_ADDR, I2C_LCD_Data);
	
	// 0->1 일때, data 출력 -> 다음 출력을 위해 0으로 다시 설정
	
	_delay_us(1600);
}

void LCD_WriteCommand(uint8_t commandData)
{
	I2C_LCD_Data &= ~(1<<LCD_RS); // Command일 때는 control register(TWCR)을 쓰고
	I2C_LCD_Data &= ~(1<<LCD_RW); // Write 모드
	LCD_Data4bit(commandData);
}

void LCD_WriteData(uint8_t charData)
{
	I2C_LCD_Data |= (1<<LCD_RS); // Data받을 때는 Data Register(TWDR) 쓰고
	I2C_LCD_Data &= ~(1<<LCD_RW); // Write 모드
	LCD_Data4bit(charData);
}


void LCD_BackLight()
{
	I2C_LCD_Data |= (1<<LCD_BACKLIGHT);
	I2C_TxByte(LCD_DEV_ADDR, I2C_LCD_Data);
}

void LCD_gotoXY(uint8_t row, uint8_t col) // LCD 화면의 커서를 지정된 행(row)과 열(col) 위치로 이동시키는 함수
{
	col %= 16; // 0~15 사이의 값 지정 가능
	row %= 2; // 0~1 사이의 값 지정 가능
	uint8_t address = (0x40 * row) + col; // 주어진 row와 col 값을 이용하여 LCD 화면의 주소(address, 커서 위치)룰 계산한다.
	// 첫 번째 행(row 0)의 주소 범위는 0x00 ~ 0x0f(0~15)
	// 두 번째 행(row 1)의 주소 범위는 0x40 ~ 0x4f(64~79)
	// 예시 : row 1, col 3 -> address = 0x43
	uint8_t command = 0x80 + address; // 계산된 주소를 이용하여 이동시키는 명령어 command 생성
	// 0x80을 사용하는 이유는 특정 주소값이 아닌, 첫 번째 행의 시작을 나타내는 상징적인 값으로 사용된다,
	// 이렇게 함으로써 코드의 가독성을 높이고, 행과 열 값을 쉽게 결합하여 원하는 주소 값을 계산할 수 있다.
	LCD_WriteCommand(command);
}

void LCD_WriteString(char *string)
{
	for (uint8_t i = 0 ; string[i] ; i++) // 받은 문자열의 포인터가 보는 곳을 한 비트씩 분해해서 LCD_WriteData 함수에 하나씩 뿌려줌
	{
		LCD_WriteData(string[i]);
	}
}

void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
{
	LCD_gotoXY(row,col); // 행과 열의 위치를 받음. -> 어디서부터 쓸 것인지를 좌표를 받음
	LCD_WriteString(string); // 문자열 입력을 받음
}

void LCD_Init()
{
	I2C_Init();
	
	_delay_ms(20);
	LCD_WriteCommand(0x03);
	_delay_ms(10);
	LCD_WriteCommand(0x03);
	_delay_ms(1);
	LCD_WriteCommand(0x03);
	
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(COMMAND_4_BIT_MODE);
	LCD_WriteCommand(COMMAND_DISPLAY_OFF);
	LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
	LCD_WriteCommand(COMMAND_ENTRY_MODE);
	LCD_WriteCommand(COMMAND_DISPLAY_ON);
	LCD_BackLight();
}














