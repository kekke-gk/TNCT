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

void wait_m4sec(int m4_sec)
/*10^-4sec�Ŏw������ԂȂɂ����Ȃ����ԉ҂��֐�*/
/*���Ƃ��΁@wait_m4sec(15);���ĂԂ�1.5msec��ɂ��̊֐�����߂�*/
{
    int i,j;
    for (i=0;i<m4_sec;i++) {
        for (j=0;j<419;j++); /*419�̍������l���Ă݂悤*/
    }
}

main()
{
	int i;
	initLed(); /*LED�̏�����*/
	turnOnLed(0); /*LED0��ON*/
	while(1) {
		for (i=0;i<400;i++) { /*���[�v4�b�ԃ��[�v�@�f���[�e�B��2%*/
			turnOnLed(1); /*LED1��ON*/
			wait_m4sec(2);
			turnOffLed(1); /*LED1��OFF*/
			wait_m4sec(98);
		}
		for (i=0;i<400;i++) { /*���[�v4�b�ԃ��[�v�@�f���[�e�B��4%*/
			turnOnLed(1); /*LED1��ON*/
			wait_m4sec(4);
			turnOffLed(1); /*LED1��OFF*/
			wait_m4sec(96);
		}
		for (i=0;i<400;i++) { /*���[�v4�b�ԃ��[�v�@�f���[�e�B��8%*/
			turnOnLed(1); /*LED1��ON*/
			wait_m4sec(8);
			turnOffLed(1); /*LED1��OFF*/
			wait_m4sec(92);
		}
		for (i=0;i<400;i++) { /*���[�v4�b�ԃ��[�v�@�f���[�e�B��16%*/
			turnOnLed(1); /*LED1��ON*/
			wait_m4sec(16);
			turnOffLed(1); /*LED1��OFF*/
			wait_m4sec(84);
		}
		for (i=0;i<400;i++) { /*���[�v4�b�ԃ��[�v�@�f���[�e�B��32%*/
			turnOnLed(1); /*LED1��ON*/
			wait_m4sec(32);
			turnOffLed(1); /*LED1��OFF*/
			wait_m4sec(68);
		}
		for (i=0;i<400;i++) { /*���[�v4�b�ԃ��[�v�@�f���[�e�B��64%*/
			turnOnLed(1); /*LED1��ON*/
			wait_m4sec(64);
			turnOffLed(1); /*LED1��OFF*/
			wait_m4sec(36);
		}
	}
}
