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
		turnOnLed(1); 
		waitmsec(125);
		turnOffLed(1); 
		waitmsec(125);
		turnOnLed(1); 
		waitmsec(125);
		turnOffLed(1); 
		waitmsec(125);

		turnOnLed(0); 
		waitmsec(125);
		turnOffLed(0); 
		waitmsec(125);
		turnOnLed(0); 
		waitmsec(125);
		turnOffLed(0); 
		waitmsec(125);

		turnOnLed(1); 
		waitmsec(250);
		turnOffLed(1); 
		waitmsec(250);

		turnOnLed(0); 
		waitmsec(250);
		turnOffLed(0); 
		waitmsec(250);


	}
}
