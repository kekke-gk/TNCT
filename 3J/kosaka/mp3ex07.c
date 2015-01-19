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

void wait_m4sec(int m4_sec)
/*10^-4secで指示する間なにもしない時間稼ぎ関数*/
/*たとえば　wait_m4sec(15);を呼ぶと1.5msec後にこの関数から戻る*/
{
    int i,j;
    for (i=0;i<m4_sec;i++) {
        for (j=0;j<419;j++); /*419の根拠を考えてみよう*/
    }
}

main()
{
	int i;
	initLed(); /*LEDの初期化*/
	turnOnLed(0); /*LED0のON*/
	while(1) {
		for (i=0;i<400;i++) { /*ループ4秒間ループ　デューティ比2%*/
			turnOnLed(1); /*LED1のON*/
			wait_m4sec(2);
			turnOffLed(1); /*LED1のOFF*/
			wait_m4sec(98);
		}
		for (i=0;i<400;i++) { /*ループ4秒間ループ　デューティ比4%*/
			turnOnLed(1); /*LED1のON*/
			wait_m4sec(4);
			turnOffLed(1); /*LED1のOFF*/
			wait_m4sec(96);
		}
		for (i=0;i<400;i++) { /*ループ4秒間ループ　デューティ比8%*/
			turnOnLed(1); /*LED1のON*/
			wait_m4sec(8);
			turnOffLed(1); /*LED1のOFF*/
			wait_m4sec(92);
		}
		for (i=0;i<400;i++) { /*ループ4秒間ループ　デューティ比16%*/
			turnOnLed(1); /*LED1のON*/
			wait_m4sec(16);
			turnOffLed(1); /*LED1のOFF*/
			wait_m4sec(84);
		}
		for (i=0;i<400;i++) { /*ループ4秒間ループ　デューティ比32%*/
			turnOnLed(1); /*LED1のON*/
			wait_m4sec(32);
			turnOffLed(1); /*LED1のOFF*/
			wait_m4sec(68);
		}
		for (i=0;i<400;i++) { /*ループ4秒間ループ　デューティ比64%*/
			turnOnLed(1); /*LED1のON*/
			wait_m4sec(64);
			turnOffLed(1); /*LED1のOFF*/
			wait_m4sec(36);
		}
	}
}
