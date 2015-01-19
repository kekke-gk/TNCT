/**********************************************************
プッシュスイッチと時間割り込みによってLEDのPWM制御を行う
**********************************************************/
#include <3048fone.h>
#include "h8_3048fone.h"

volatile int led0,led1;
const int period=10; /*周期10msec*/
const int low=1;

main()
{
	unsigned char swStatus=0;
	initLed();
	initPushSW();
	led0=led1=0;
	initTimer1Int(1000); /*タイマ割り込み1msec */
	                     /*単位はμsec ITUch1のみ使用*/
	E_INT();        /*CPU割り込み許可*/
	startTimer1();  /*時間割り込みタイマスタート*/
	
	
	while(1){
		swStatus=getPushSW();
		if(swStatus == 0x00){
			led0=1;
			led1=1;
		}else if(swStatus == 0x01){
			led0=2;
			led1=0;
		}else if(swStatus == 0x02){
			led0=5;
			led1=0;
		}else if(swStatus == 0x03){
			led0=10;
			led1=0;
		}else if(swStatus == 0x04){
			led0=0;
			led1=2;
		}else if(swStatus == 0x08){
			led0=0;
			led1=5;
		}else if(swStatus == 0x0C){
			led0=0;
			led1=10;
		}else{
			led0=0;
			led1=0;
		}

	}
}

#pragma asm
    .SECTION    MYVEC, DATA, LOCATE=H'000070
    .ORG        H'000070  ;IMIA1
    .DATA.L     _TimerIntFunc
    .SECTION    P,CODE,ALIGN=2 ;これを忘れてはいけない
#pragma endasm

#pragma interrupt (TimerIntFunc)
void TimerIntFunc() /*タイマ割り込みルーチン*/
{
	static int tick=0;
	clearTimer1Flag();  /*タイマステータスフラグのクリア 忘れないこと*/
	if (tick<led0) {
		turnOnLed(0);
	} else {
		turnOffLed(0);
	}
	if (tick<led1) {
		turnOnLed(1);
	} else {
		turnOffLed(1);
	}
	tick++;
	if (tick==period) tick=0;
}
