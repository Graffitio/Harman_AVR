/*
 * LED.c
 *
 * Created: 2023-07-10 오후 3:36:16
 *  Author: USER
 */ 
//0123 4567

//0000 0000
//1000 0001
//0100 0010
//0010 0100
//0001 1000

//0000 0000

//0001 1000
//0010 0100
//0100 0010
//1000 0001
//0000 0000

#include "LED.h"

void ledInit(LED *led) // led의 주소를 받을 거야
{
	*(led->port -1) |=(1 << led->pin); // initial value = 0
	// = *(led->port -1) = *(led->pin-1) | (1<<led->pin));
	// 포트에 해당하는 핀을 출력으로 설정(0번 핀)
	// port-1을 하면 DDR로 간다
	// Datasheet상, 포트보다 주소값이 한 단계 아래인 것을 활용
	// *(led->port -1)를 이용해서 port에서 DDR로 접근
	// |=(1 << led->pin) OR연산을 통해 led->pin으로 지정된 포트를 출력으로 설정
	// 여기서 1은 0x01
	//*(led->port-1) |= (1<< led->pin+7);
}

void ledOn(LED *led)
{
	// 해당 핀을 high로 설정
	*(led->port) |= (1<<led->pin);
}

void ledOff(LED *led)
{
	// 해당 핀을 low로 설정
	*(led->port) &= ~(1<<led->pin);
	//*(led->port) &= ~(1<<led->pin+7);
}


//#include "LED.h"
//
//void ledInit(LED *led)
//{
	//(led->port-1) |= (1 << led->pin);
	//// (led->port-1) = *(led->port-1) | (1 << led->pin);
	//// (*led).(port-1) : 구조체 포인터 변수 led가 쳐다보는 구조체 LED의 멤버인 (port-1 = DDR)
	//// (*led).pin : 현재 pin의 값 = 0x00;
	//// DDR을 현재 사용하는 pin의 번호와 같은 port를 출력으로 변경
	//// 현재 0번 pin을 사용하고 있으니, 
//}
//
//void ledOn(LED *led)
//{
	//
//}
//
//void ledOff(LED *led)
//{
	//
//}