/*
 * DS1302.h
 *
 * Created: 2023-07-26 오전 11:46:43
 *  Author: USER
 */ 

#ifndef DS1302_H_
#define DS1302_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

#define DS1302_CLK_DDR		DDRG
#define DS1302_CLK_PORT		PORTG
#define DS1302_DATA_DDR		DDRG
#define DS1302_DATA_PORT	PORTG
#define DS1302_DATA_PIN		PING
#define DS1302_RST_DDR		DDRG  // 칩 셀렉트 핀을 reset 핀이라고도 한다.
#define DS1302_RST_PORT		PORTG
#define DS1302_CLK			2
#define DS1302_DATA			3
#define DS1302_RST			4

// Data sheet 상 address //
#define ADDR_SEC			0x80
#define ADDR_MIN			0x82
#define ADDR_HOUR			0x84
#define ADDR_DATE			0x86
#define ADDR_MONTH			0x88
#define ADDR_DAYOFWEEK		0x8A // 월요일~일요일
#define ADDR_YEAR			0x8C


typedef struct _ds1302
{
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	uint8_t date;
	uint8_t month;
	uint8_t dayOfweek;
	uint8_t year;	
}DS1302;



void DS1302_Init(); // 초기화
void DS1302_Selected(); // CE = high
void DS1302_Deselected(); // CE = Low
void DS1302_Clock(); // Clock
void DS1302_DataBitSet(); // Bit 설정(Data PIN High)
void DS13602_DataBitReset(); // Bit 설정(Data PIN Low)
void DS1302_Change_ReadMode(); // 읽기 모드로 설정
void DS1302_change_WriteMode(); // 쓰기 모드로 설정
uint8_t Decimal_to_BCD(uint8_t decimal);
uint8_t BCD_to_Decimal(uint8_t bcd);
void DS1302_TxData(uint8_t txData); // RTC에 data send
void DS1302_WriteData(uint8_t address, uint8_t data); // 특정 주소에 data write
void DS1302_SetTimeDate(DS1302 timeDate); // Date, Time 직접 설정
uint8_t DS1302_RxData(); // data receive
uint8_t DS1302_ReadData(uint8_t address); // 특정 주소에서 data read
void DS1302_GetTime(DS1302 *timeDate); // RTC의 시간 get
void DS1302_GetDate(DS1302 *timeDate); // RTC의 날짜 get



#endif /* DS1302_H_ */