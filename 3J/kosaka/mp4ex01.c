/**********************************************************
マザーボードの8ビットスイッチによってLEDのON-OFFを行う
**********************************************************/
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
	P2.DDR=0;
	P2.PCR.BYTE=0xff;
	while(1) {
		turnOnLed(0);
		turnOnLed(1);
		if (P2.DR.BIT.B1==0) waitmsec(500);
		else waitmsec(250);
		turnOffLed(0);
		turnOffLed(1);
		if (P2.DR.BIT.B1==0) waitmsec(500);
		else waitmsec(250);
	}
}