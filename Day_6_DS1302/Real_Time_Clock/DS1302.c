/*
 * DS1302.c
 *
 * Created: 2023-07-26 오전 11:46:35
 *  Author: USER
 */ 
#include "DS1302.h"


void DS1302_Init()
{
	/*
	 * DS1302 초기화 함수
	 * 클럭 핀, 데이터 핀 출력 설정
	 * RST 핀 LOW로 설정
	 * 
	*/
	DS1302_CLK_DDR |= (1<<DS1302_CLK); // 2번 CLK 라인에 해당하는 PIN을 출력으로 설정
	DS1302_DATA_DDR |= (1<<DS1302_DATA); // 3번
	DS1302_RST_DDR |= (1<<DS1302_RST); // 4번
	
	DS1302_CLK_PORT &= ~(1<<DS1302_CLK); // 초기값은 Low
	DS1302_DATA_PORT |= (1<<DS1302_DATA); // 초기값 high
	DS1302_RST_PORT &= ~(1<<DS1302_RST); // 셀렉트 핀 초기값 Low 
}


void DS1302_Selected()
{
	DS1302_RST_PORT |= (1<<DS1302_RST); // CE 핀을 High
}


void DS1302_Deselected()
{
	DS1302_RST_PORT &= ~(1<<DS1302_RST); // CE 핀을 Low
}


void DS1302_Clock() // 오실레이터에 달려 있는 클록 기준으로 clk 펄스 발생
{
	DS1302_CLK_PORT |= (1<<DS1302_CLK); // Clock High
	DS1302_CLK_PORT &= ~(1<<DS1302_CLK); // Clock Low
	
}


void DS1302_DataBitSet()
{
	DS1302_DATA_PORT |= (1<<DS1302_DATA); // Data 핀 High
}


void DS13602_DataBitReset()
{
	DS1302_DATA_PORT &= ~(1<<DS1302_DATA); // Data 핀 Low
	
}


void DS1302_Change_ReadMode()
{
	DS1302_DATA_DDR &= ~(1<<DS1302_DATA); // 읽기 모드에서 데이터 핀 출력 설정 변경
}


void DS1302_change_WriteMode()
{
	DS1302_DATA_DDR |= (1<<DS1302_DATA); // 쓰기모드에서 데이터 핀 출력 설정 변경
}


// 읽어와도 BCD값으로 읽어올 것이니까~
//DEC -> BCD, BCD->DEC로 바꿔주는 함수 필요
uint8_t Decimal_to_BCD(uint8_t decimal)
{
	return (((decimal/10) << 4) | (decimal%10));
	// 10진값을 2진값으로 변환
	// 4bit씩 묶어서 1의 자리와 10의 자리로 각각 변환
	// ex) 59 = (50/10)<<9 | 9%10 = 0101 1001
}


uint8_t BCD_to_Decimal(uint8_t bcd)
{
	return (((bcd >> 4) * 10) + (bcd & 0x0f));
	// bcd 값을 4bit씩 묶어서 10의 자리와 1의자리로 각각 변환한 후 더함.
	// 0101 1001 = (0000 0101 * 10) + (0000 1001) = 5*10 + 9 = 59
}


void DS1302_TxData(uint8_t txData)
{
	// 데이터 하위비트부터 상위비트 순으로 보내고 (Lsb부터 날라간다.)
	// 클럭 신호를 발생시켜 데이터를 전송한다.
	DS1302_change_WriteMode(); // 쓰기 모드로 변경
	
	for (int i = 0 ; i < 8 ; i++)
	{
		// 하위 비트 -> 상위 비트로
		// 1비트 출력하고 클럭 올렸다 내리고
		if (txData & (1<<i)) // 0번 bit부터 밀면서 7번까지 사용
		DS1302_DataBitSet(); // 1이면, Data Pin High
		else
		DS13602_DataBitReset(); // 0 또는 그렇지 않으면, Data Pin Low
		
		DS1302_Clock(); // 클럭 한 번 반복
	}
}

void DS1302_WriteData(uint8_t address, uint8_t data)
{
	// 주소와 데이터를 전송하고
	// 다 끝났으면, RST 핀을 Low로 설정
	DS1302_Selected(); // RST 핀 High(CE = high)
	DS1302_TxData(address); // address send
	DS1302_TxData(Decimal_to_BCD(data)); // data를 BCD로 바꿔서 보냄 
	DS1302_Deselected(); // CE = Low
}


void DS1302_SetTimeDate(DS1302 timeDate) // 매개변수는 DS1302 구조체type의 timeDate
{
	DS1302_WriteData(ADDR_SEC, timeDate.sec);
	DS1302_WriteData(ADDR_MIN, timeDate.min);
	DS1302_WriteData(ADDR_HOUR, timeDate.hour);
	DS1302_WriteData(ADDR_DATE, timeDate.date);
	DS1302_WriteData(ADDR_MONTH, timeDate.month);
	DS1302_WriteData(ADDR_DAYOFWEEK, timeDate.dayOfweek);
	DS1302_WriteData(ADDR_YEAR, timeDate.year);
}


uint8_t DS1302_RxData()
{
	// 데이터를 하위비트부터 상위비트 순으로 읽고
	// 클럭 신호를 발생시켜 데이터를 읽음
	uint8_t rxData = 0;
	DS1302_Change_ReadMode(); // Read mode로 바꾸고
	
	for (int i = 0 ; i < 8 ; i++)
	{
		rxData |= (DS1302_DATA_PIN & (1<<DS1302_DATA)) ? (1<<i) : 0;
		if(i != 7) // (0~7까지 총 8번 rising edge)
		DS1302_Clock();
	}
	return rxData;
}


uint8_t DS1302_ReadData(uint8_t address)
{
	// 지정된 주소의 데이터를 읽어옴
	uint8_t rxData = 0; //  수신된 데이터를 저장할 변수
	DS1302_Selected(); // CE = high
	DS1302_TxData(address+1); // 지정된 주소를 전송(Write에서 1을 더하면 Read주소)
	rxData = DS1302_RxData(); // 수신된 데이터를 읽음
	DS1302_Deselected(); // CE = Low
	
	return BCD_to_Decimal(rxData);
}


void DS1302_GetTime(DS1302 *timeDate) // 매개변수는 DS1302 type의 timeDate 포인터 변수 
{
	timeDate->sec = DS1302_ReadData(ADDR_SEC);
	timeDate->min = DS1302_ReadData(ADDR_MIN);
	timeDate->hour = DS1302_ReadData(ADDR_HOUR);
}


void DS1302_GetDate(DS1302 *timeDate)
{
	timeDate->date = DS1302_ReadData(ADDR_DATE);
	timeDate->month = DS1302_ReadData(ADDR_MONTH);
	timeDate->dayOfweek = DS1302_ReadData(ADDR_DAYOFWEEK);
	timeDate->year = DS1302_ReadData(ADDR_YEAR);
}