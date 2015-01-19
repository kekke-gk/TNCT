#include <3048fone.h>
#include "h8_3048fone.h"

void waitmsec(int msec)
{
	int i,j;
	for (i=0;i<msec;i++) {
		for (j=0;j<4190;j++);
	}
}

void pushreleaseSW(void)
/*プッシュスイッチが押されるまで待って，*/
/*その後離されるまで待つ関数　　　　　　*/
{
	while (checkPushSW(0)==0);
	while (checkPushSW(0)==1);
}

main()
{
	int i=0;
	initLed();
	initSCI1();
	initPushSW();
	while(1) {
		pushreleaseSW();
		((i%=2)==0)?turnOnLed(0):turnOffLed(0);
		i++;
	}
	
}
