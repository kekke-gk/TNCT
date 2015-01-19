#include <3048fone.h>

void initLed()
{
	P5.DDR = 0xf;
}

void turnOnLed(short int number)
{ 
	static const unsigned char mask[]={1,2,4,8};
	P5.DR.BYTE |= mask[number];
}

void turnOffLed(short int number)
{
	static const unsigned char mask[]={0xfe,0xfd,0xfb,0xf7};
	P5.DR.BYTE &= mask[number];
}

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
		turnOffLed(1); 
		waitmsec(1000);
		turnOffLed(0); 
		turnOnLed(1); 
		waitmsec(1000);
	}
}
