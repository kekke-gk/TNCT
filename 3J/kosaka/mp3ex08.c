/**********************************************************
LEDのPWM(PulseWidthModulation)駆動
**********************************************************/
#include <3048fone.h>
#include "h8_3048fone.h"

void waitmsec(int msec)
/*msec間なにもしない時間稼ぎ関数*/
{
	int i,j;
	for (i=0;i<msec;i++) {
		for (j=0;j<4190;j++);    /*4190は実測によって求めた値 25MHz駆動*/
	}
}

main()
{
	int i;
	initLed(); /*LEDの初期化*/
	while(1) {
		turnOnLed(1); /*LED1のON*/
		waitmsec(11);
		turnOffLed(1); /*LED1のOFF*/
		waitmsec(11);
	}
}
