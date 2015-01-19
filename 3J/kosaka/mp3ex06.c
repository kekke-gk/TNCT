#include <3048fone.h>

void initLed_P1()
{
	P1.DDR = 0xf;
}

void turnOnLed_P1(short int number)
{ 
	static const unsigned char mask[]={1,2,4,8};
	P1.DR.BYTE |= mask[number];
}

void turnOffLed_P1(short int number)
{
	static const unsigned char mask[]={0xfe,0xfd,0xfb,0xf7};
	P1.DR.BYTE &= mask[number];
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
	initLed_P1();
	while(1) {
		turnOnLed_P1(0);
		waitmsec(2000);
		turnOffLed_P1(0);
		
		turnOnLed_P1(1);
		waitmsec(2000);
		turnOffLed_P1(1);
		
		turnOnLed_P1(2);
		waitmsec(2000);
		turnOffLed_P1(2);
		
		turnOnLed_P1(3);
		waitmsec(2000);
		turnOffLed_P1(3);
	}
}
