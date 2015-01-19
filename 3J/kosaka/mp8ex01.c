/**********************************************************
割り込みを用いた時計　起動時からの経過時間［秒］を
SCI1へ出力，WINDOWSのHyperTerminalなどで受信できる。
ただし，設定は
38400baud, Async, 8bit , NoParity, stop1
**********************************************************/
#include <3048fone.h>
#include "h8_3048fone.h"

volatile unsigned int counter;/*0.1s単位でカウント*/

int status=0;/*0ならスタート,1ならストップ*/

main()
{
	unsigned int counter1;
	unsigned int t1,t2;
	short int tmp;
	initSCI1(); /*SCI-ch1の初期化*/
	initTimer1Int(1000); /*ITUch1のインターバルタイマ初期化設定*/
						  /*単位μsなので，時間割り込み1msec*/
	E_INT();        /*CPU割り込み許可*/
	startTimer1();  /*ITUch1タイマスタート*/
	counter=0;
	while(1) {
		tmp=SCI1_chkgetChar();
		if(tmp=='A' || tmp=='a'){
			status=0;
		}else if(tmp=='B' || tmp=='b'){
			status=1;
		}else if(tmp=='C' || tmp=='c'){
			counter=0;
		}
		
		counter1=counter;
		t1=counter1/1000;
		t2=counter1%1000;
		SCI1_printf("%10u.%1u \r",t1,t2); 

	}
}


#pragma asm
	.SECTION    MYVEC, DATA, LOCATE=H'000070
	.ORG        H'000070  ;IMIA1
	.DATA.L     _TimerIntFunc
	.SECTION    P,CODE,ALIGN=2 ;これを忘れてはいけない
#pragma endasm

#pragma interrupt (TimerIntFunc)
void TimerIntFunc() /*インターバルタイマ割り込みルーチン*/
{
	if(status==0){
		counter++;
	}
	clearTimer1Flag();  /*ITUch1タイマフラグのクリア 忘れないこと*/
}
