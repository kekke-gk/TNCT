#include <3048fone.h>
#include "h8_3048fone.h"

void waitmsec(int msec)
{
	int i,j;
	for (i=0;i<msec;i++) {
		for (j=0;j<4190;j++);
	}
}

main()
{
	initLed();
	initSCI1();
	initPushSW();
	while(1) {
		if(P4.DR.BYTE>>4 == 0xe/*1110*/){
			turnOnLed(0);
			turnOnLed(1);
			waitmsec(250);
			turnOffLed(0);
			turnOffLed(1);
			waitmsec(250);
		}else if(P4.DR.BYTE>>4 == 0xd/*1101*/){
			turnOnLed(0);
			turnOnLed(1);
			waitmsec(500);
			turnOffLed(0);
			turnOffLed(1);
			waitmsec(500);
		}else if(P4.DR.BYTE>>4 == 0xb/*1011*/){
			turnOnLed(0);
			turnOnLed(1);
			waitmsec(1000);
			turnOffLed(0);
			turnOffLed(1);
			waitmsec(1000);
		}
	}
	
}