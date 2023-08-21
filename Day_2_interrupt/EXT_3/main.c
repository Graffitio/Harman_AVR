/*
 * EXT_3.c
 *
 * Created: 2023-07-12 오후 7:09:26
 * Author : USER
 */ 
//#define F_CPU 16000000UL
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//
//int cnt;
//uint8_t buttonState = 0;
//// Segment 배열 선언 //
//uint8_t seg_arr[] ={
	//0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x67
//};
//
//
//
//ISR(INT4_vect)
//{
	//buttonState = 1;
//}
//
//
//int main(void)
//{ 
    //DDRA = 0xff; // PORTA all 출력 모드
	//DDRE &= ~(1<<PINE4); // PORTE 입력 모드
	//
	//// 4번 핀 인터럽트 활성화 //
	//EICRB |= (1<<ISC41) | (0<<ISC40);
	//EIMSK |= (1<<INT4);
	//sei();
	//
    //while (1) 
    //{
		//if (buttonState)
		//{
			//_delay_ms(50);
			//if (!(PINE & (1<<PINE4))) // 눌러진 상태라면, pin4 : 1->0
			//{
				//if(cnt<10)
				//{
					//PORTA = seg_arr[cnt];
					//cnt++;
					//if(cnt == 10) cnt=0;
				//}
			//}
			//buttonState = 0;
		//}
			//
    //}
//}


//#define F_CPU 16000000UL
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//
//
//// Segment 배열 선언 //
//uint8_t seg_arr[] ={
	//0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x67
//};
//
//
//int main()
//{
	//
	//int count = 0;
	//DDRA = 0xff;
	//
	//while(1)
	//{
		//PORTA = seg_arr[count];
		//count = (count+1)%10;
		//
		//_delay_ms(500);		
	//}	
//}


//#define F_CPU 16000000UL
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//
//#define		FND_DATA_DDR	DDRA  // 데이터 포트
//#define		FND_SELECT_DDR	DDRF  // 셀렉트 포트(자릿수 선택)
//#define		FND_DATA_PORT	PORTA // 0 ~ 7
//#define		FND_SELECT_PORT	PORTF // 0 ~ 4
//
//// 디스플레이 함수 선언 //
//void FND_Display(uint16_t data); // 8bit면 255까지밖에 없기 때문에, 4자리 다 쓰려고 16bit
//
//
//
//int main()
//{
	//FND_DATA_DDR = 0xff; // 출력 모드
	//FND_SELECT_DDR = 0xff; // 출력 모드
	//FND_SELECT_PORT = 0x00; // 0부터 시작
	//
	//uint16_t count = 0;
	//uint32_t time_tick = 0;
	//uint32_t prev_time = 0;
//
	//while(1)
	//{
		//FND_Display(count);
		//// 시간 지연 함수 //
		//// 딜레이 함수처럼 쓸 수 있는 함수 틱
		//// delay 함수가 CPU를 많이 잡아 먹지 않도록 하기 위해 만든 함수
		//if (time_tick - prev_time > 100) 
		//{
			//prev_time = time_tick;
			//count++; // 결국 카운트는 100ms마다 하나씩 올라감
			         //// 잔상효과를 활용하여 출력 
		//}
		//_delay_ms(1); // 1ms 시간 지연
		//time_tick++; // 
	//}
//}
//
//
//
//void FND_Display(uint16_t data)
//{
	//static uint8_t position = 0;
	//uint8_t fnd_data[] = {
		//0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x67
	//};
	//
	//switch(position)
	//{
		//case 0 : // 첫 번째 자리 -> 0번 pin Low, 나머지는 High  / 출력을 받아서 입력으로 넣어주면 회로 완성
		//FND_SELECT_PORT &= ~(1<<PINF0);
		//FND_SELECT_PORT |= (1<<PINF1) | (1<<PINF2) | (1<<PINF3);
		//FND_DATA_PORT = fnd_data[data/1000];
		//break;
		//
		//case 1 : 
		//FND_SELECT_PORT &= ~(1<<PINF1);
		//FND_SELECT_PORT |= (1<<PINF0) | (1<<PINF2) | (1<<PINF3);
		//FND_DATA_PORT = fnd_data[data/100%10];
		//break;
//
		//case 2 : 
		//FND_SELECT_PORT &= ~(1<<PINF2);
		//FND_SELECT_PORT |= (1<<PINF1) | (1<<PINF0) | (1<<PINF3);
		//FND_DATA_PORT = fnd_data[data/10%10];
		//break;
		//
		//case 3 : 
		//FND_SELECT_PORT &= ~(1<<PINF3);
		//FND_SELECT_PORT |= (1<<PINF1) | (1<<PINF2) | (1<<PINF0);
		//FND_DATA_PORT = fnd_data[data%10];
		//break;		
	//}
	//position++;
	//position = position % 4; // 4자리만 출력하고 다시 처음으로
	//
//}





#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define		FND_DATA_DDR	DDRA  // 데이터 포트
#define		FND_SELECT_DDR	DDRF  // 셀렉트 포트(자릿수 선택)
#define		FND_DATA_PORT	PORTA // 0 ~ 7
#define		FND_SELECT_PORT	PORTF // 0 ~ 4

// 디스플레이 함수 선언 //
void FND_Display(uint16_t data); // 8bit면 255까지밖에 없기 때문에, 4자리 다 쓰려고 16bit


volatile uint32_t time_tick;
uint16_t count;
volatile uint8_t start_stop;
uint16_t count_ovfl;
uint8_t LED_Data;
uint8_t up_down;



ISR(TIMER0_OVF_vect)
{
	time_tick++;
	if(up_down%2)
	{
		if(count > 0)
		{
			if(time_tick == 250)
			{
				count--;
				time_tick = 0;
			}
		}
		else count = 9999;
	}
	else
	{
		if (count<9999)
		{
			if (time_tick == 250)  // 2ms마다 ISR 실행되므로 100ms마다 count++
			{
				count++;
				time_tick = 0;
			}
		}
		else count = 0;
	}
}

ISR(INT4_vect) // start/stop
{
	if (start_stop%2)
		TIMSK = (1<<TOIE0);
	else TIMSK = (0<<TOIE0);
	start_stop++;
}

ISR(INT5_vect) // reset
{
	start_stop = 0;
	count = 0;
	count_ovfl = 0;
	LED_Data = 0;
	PORTD = LED_Data;
}

ISR(INT6_vect)
{
	up_down++;
	TIMSK = (1<<TOIE0);		
}



int main()
{
	FND_DATA_DDR = 0xff; // 출력 모드
	FND_SELECT_DDR = 0xff; // 출력 모드
	FND_DATA_PORT = 0x00; // 0부터 시작
	DDRE &= ~(1<<DDRE4) | ~(1<<DDRE5) | ~(1<<DDRE6);
	DDRD = 0xff;
	PORTD = 0x00;
	
	
	
	TCCR0 = (1<<CS02) | (1<<CS01) | (0<<CS00); // 256 분주
	TCNT0 = 131;
	EICRB |= (1<<ISC41) | (0<<ISC40) | (1<<ISC51) | (0<<ISC50) | (1<<ISC61) | (0<<ISC60);
	EIMSK |= (1<<INT4) | (1<<INT5) | (1<<INT6);
	TIMSK = (1<<TOIE0);
	
	sei();

	while(1)
	{
		FND_Display(count);
		_delay_ms(4);
		if(up_down%2)
		{
			if (count == 0)
			{
				_delay_ms(10);
				if (count_ovfl>0)
				{
					LED_Data &= ~(1<<count_ovfl);
					PORTD = LED_Data;
					count_ovfl--;
				}
				else
				{
					count_ovfl = 8;
					LED_Data = 0xff;
					PORTD = LED_Data;
				}
			}
		}
		else
		{		
			if (count == 9999)
			{
				_delay_ms(10);
				if(count_ovfl<8)
				{
					LED_Data |= (1<<count_ovfl);
					PORTD = LED_Data;
					count_ovfl++;
				}
				else
				{
					count_ovfl = 0;
					LED_Data = 0;
					PORTD = LED_Data;
				}
			}
		}
	}
}


void FND_Display(uint16_t data)
{
	static uint8_t position = 0;
	uint8_t fnd_data[] = {
		0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x67
	};
		
	switch(position)
	{
		case 0 : // 첫 번째 자리 -> 0번 pin Low, 나머지는 High  / 출력을 받아서 입력으로 넣어주면 회로 완성
		FND_SELECT_PORT &= ~(1<<PINF0);
		FND_SELECT_PORT |= (1<<PINF1) | (1<<PINF2) | (1<<PINF3);
		FND_DATA_PORT = fnd_data[data/1000];
		break;
		
		case 1 :
		FND_SELECT_PORT &= ~(1<<PINF1);
		FND_SELECT_PORT |= (1<<PINF0) | (1<<PINF2) | (1<<PINF3);
		FND_DATA_PORT = fnd_data[data/100%10];
		break;

		case 2 :
		FND_SELECT_PORT &= ~(1<<PINF2);
		FND_SELECT_PORT |= (1<<PINF1) | (1<<PINF0) | (1<<PINF3);
		FND_DATA_PORT = fnd_data[data/10%10];
		break;
		
		case 3 :
		FND_SELECT_PORT &= ~(1<<PINF3);
		FND_SELECT_PORT |= (1<<PINF1) | (1<<PINF2) | (1<<PINF0);
		FND_DATA_PORT = fnd_data[data%10];
		break;
	}
	position++;
	position = position % 4; // 4자리만 출력하고 다시 처음으로
	
}













//#define F_CPU 16000000UL
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//
//#define		FND_DATA_DDR	DDRA  // 데이터 포트
//#define		FND_SELECT_DDR	DDRF  // 셀렉트 포트(자릿수 선택)
//#define		FND_DATA_PORT	PORTA // 0 ~ 7
//#define		FND_SELECT_PORT	PORTF // 0 ~ 4
//
//// 디스플레이 함수 선언 //
//void FND_Display(); // 8bit면 255까지밖에 없기 때문에, 4자리 다 쓰려고 16bit
//void FND_set_data(uint16_t data);
//uint16_t FND_get_data();
//
//
//volatile uint32_t time_tick;
//uint16_t count;
//volatile uint8_t start_stop = 0;
//uint16_t FND_count;
//
//
//ISR(TIMER0_OVF_vect)
//{
	//time_tick++;
	//if (time_tick == 50)  // 2ms마다 ISR 실행되므로 100ms마다 count++
	//{
		////FND_BAR_PORT = ~FND_BAR_PORT;
		//FND_set_data(count);
		//count++;
		//time_tick = 0;
	//}
//}
//
//ISR(INT4_vect) // start/stop
//{
	//if (start_stop%2)
	//TIMSK = (1<<TOIE0);
	//else TIMSK = (0<<TOIE0);
	//start_stop++;
//}
//
//ISR(INT5_vect) // reset
//{
	//start_stop = 0;
	//count = 0;
	//FND_set_data(count);
//}
//
//
//int main()
//{
	//FND_DATA_DDR = 0xff; // 출력 모드
	//FND_SELECT_DDR = 0xff; // 출력 모드
	//FND_DATA_PORT = 0x00; // 0부터 시작
	//DDRE = 0x00; // 외부 인터럽트 핀에 맞게 연결해서 사용할 것.
	//
	//TCCR0 = (1<<CS02) | (1<<CS01) | (0<<CS00); // 256 분주
	//TCNT0 = 131;
	//EICRB |= (1<<ISC41) | (0<<ISC40) | (1<<ISC51) | (0<<ISC50);
	//EIMSK |= (1<<INT4) | (1<<INT5);
	//TIMSK = (1<<TOIE0);
	//
	//sei();
//
	//while(1) // while문 내에서는 버튼을 받기 위해 기다려야 한다.
	//{
		//FND_Display();
		//_delay_ms(1);
	//}
//}
//
//
//void FND_Display()
//{
	//static uint8_t position = 0;
	//uint8_t fnd_data[] = {
		//0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x67
	//};
	//
	//uint16_t data = FND_get_data();
	//FND_off();
	//switch(position)
	//{
		//case 0 : // 첫 번째 자리 -> 0번 pin Low, 나머지는 High  / 출력을 받아서 입력으로 넣어주면 회로 완성
		//FND_SELECT_PORT &= ~(1<<PINF0);
		//FND_SELECT_PORT |= (1<<PINF1) | (1<<PINF2) | (1<<PINF3);
		//FND_DATA_PORT = fnd_data[data/1000];
		//break;
		//
		//case 1 :
		//FND_SELECT_PORT &= ~(1<<PINF1);
		//FND_SELECT_PORT |= (1<<PINF0) | (1<<PINF2) | (1<<PINF3);
		//FND_DATA_PORT = fnd_data[data/100%10];
		//break;
//
		//case 2 :
		//FND_SELECT_PORT &= ~(1<<PINF2);
		//FND_SELECT_PORT |= (1<<PINF1) | (1<<PINF0) | (1<<PINF3);
		//FND_DATA_PORT = fnd_data[data/10%10];
		//break;
		//
		//case 3 :
		//FND_SELECT_PORT &= ~(1<<PINF3);
		//FND_SELECT_PORT |= (1<<PINF1) | (1<<PINF2) | (1<<PINF0);
		//FND_DATA_PORT = fnd_data[data%10];
		//break;
	//}
	//position++;
	//position = position % 4; // 4자리만 출력하고 다시 처음으로
	//
//}
//
//
//void FND_set_data(uint16_t data)
//{
	//if (data >= 10000)
	//{
		//data = 9999;
	//}
	//FND_count = data;
//}
//
//uint16_t FND_get_data()
//{
	//return FND_count;
//}