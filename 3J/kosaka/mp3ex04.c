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
	while(1) {
		turnOnLed(0); 
		turnOnLed(1); 
		waitmsec(5*1000);
		turnOffLed(0); 
		turnOffLed(1); 
		waitmsec(5*1000);


	}
}
