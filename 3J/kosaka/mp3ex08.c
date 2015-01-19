/**********************************************************
LEDÇÃPWM(PulseWidthModulation)ãÏìÆ
**********************************************************/
#include <3048fone.h>
#include "h8_3048fone.h"

void waitmsec(int msec)
/*msecä‘Ç»Ç…Ç‡ÇµÇ»Ç¢éûä‘â“Ç¨ä÷êî*/
{
	int i,j;
	for (i=0;i<msec;i++) {
		for (j=0;j<4190;j++);    /*4190ÇÕé¿ë™Ç…ÇÊÇ¡ÇƒãÅÇﬂÇΩíl 25MHzãÏìÆ*/
	}
}

main()
{
	int i;
	initLed(); /*LEDÇÃèâä˙âª*/
	while(1) {
		turnOnLed(1); /*LED1ÇÃON*/
		waitmsec(11);
		turnOffLed(1); /*LED1ÇÃOFF*/
		waitmsec(11);
	}
}
