/**********************************************************
LED��PWM(PulseWidthModulation)�쓮
**********************************************************/
#include <3048fone.h>
#include "h8_3048fone.h"

void waitmsec(int msec)
/*msec�ԂȂɂ����Ȃ����ԉ҂��֐�*/
{
	int i,j;
	for (i=0;i<msec;i++) {
		for (j=0;j<4190;j++);    /*4190�͎����ɂ���ċ��߂��l 25MHz�쓮*/
	}
}

main()
{
	int i;
	initLed(); /*LED�̏�����*/
	while(1) {
		turnOnLed(1); /*LED1��ON*/
		waitmsec(11);
		turnOffLed(1); /*LED1��OFF*/
		waitmsec(11);
	}
}
