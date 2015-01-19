#include <3048fone.h>
#include "h8_3048fone.h"

 /*SCI-ch1ÇÃèâä˙âª 38400bit/sec*/
void myinitSCI1_38400()
{
	short int i;
	SCI1.SCR.BYTE = 0;       /* clear all flags */
					  /* 2400-38400baud are available at n=0(cks1=0,cks2=0) */
	SCI1.SMR.BYTE = 0;       /* Async, 8bit , NoParity, stop1, 1/1 */
	SCI1.BRR = 19;          /* 38400baud (CPU=25MHz) */
	for(i=0;i<1000;i++);      /* wait more than 1bit time */
	SCI1.SCR.BYTE = 0x30;    /* scr = 0011 0000 (TE=1,RE=1) */
	return;
}

 /*SCI-ch1ÇÃèâä˙âª 19200bit/sec*/
void myinitSCI1_19200()
{
	short int i;
	SCI1.SCR.BYTE = 0;       /* clear all flags */
					  /* 2400-38400baud are available at n=0(cks1=0,cks2=0) */
	SCI1.SMR.BYTE = 0;       /* Async, 8bit , NoParity, stop1, 1/1 */
	SCI1.BRR = 40;             /* 19200baud (CPU=25MHz) */
	for(i=0;i<1000;i++);      /* wait more than 1bit time */
	SCI1.SCR.BYTE = 0x30;    /* scr = 0011 0000 (TE=1,RE=1) */
	return;
}

 /*SCI-ch1ÇÃèâä˙âª 1200bit/sec*/
void myinitSCI1_1200()
{
	short int i;
	SCI1.SCR.BYTE = 0;       /* clear all flags */
					  /* 2400-38400baud are available at n=0(cks1=0,cks2=0) */
	SCI1.SMR.BYTE = 1;       /* Async, 8bit , NoParity, stop1, 1/1 */
	SCI1.BRR = 162;             /* 1200baud (CPU=25MHz) */
	for(i=0;i<1000;i++);      /* wait more than 1bit time */
	SCI1.SCR.BYTE = 0x30;    /* scr = 0011 0000 (TE=1,RE=1) */
	return;
}

main()
{
	int count=0;
	/*myinitSCI1_38400();/**/
	/*myinitSCI1_19200();/**/
	myinitSCI1_1200();/**/
	while (1) {
		SCI1_printf("Hello %6d\n",count++);
	}
}
