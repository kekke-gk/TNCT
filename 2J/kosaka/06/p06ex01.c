/***  p06ex01.c  ***/
/***  s12083  2J18  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>
#include <stdlib.h>

int delay2(int var)
{
	static int buffer[4]={0};
	static int putpos=3;
	static int getpos=0;
	buffer[putpos]=var;
	putpos++;
	if(putpos==4) putpos=0;
	getpos++;
	if (getpos==4) getpos=0;
	return buffer[getpos];
}

int main()
{
	int i;
	int x,y;
	for(i=0;i<100000;i++) {
		x=rand();
		y=delay2(x);
		if (i<10 || 99990<i) printf("%8d x=%6d y=%6d\n",i,x,y);
	}
	return 0;
}

/**************** ŽÀsŒ‹‰Ê *****************
       0 x=    41 y=     0
       1 x= 18467 y=     0
       2 x=  6334 y=    41
       3 x= 26500 y= 18467
       4 x= 19169 y=  6334
       5 x= 15724 y= 26500
       6 x= 11478 y= 19169
       7 x= 29358 y= 15724
       8 x= 26962 y= 11478
       9 x= 24464 y= 29358
   99991 x= 11501 y= 13761
   99992 x= 10554 y= 20000
   99993 x= 30951 y= 11501
   99994 x= 20500 y= 10554
   99995 x= 31777 y= 30951
   99996 x=  5801 y= 20500
   99997 x=  4280 y= 31777
   99998 x=  5253 y=  5801
   99999 x=  1629 y=  4280

*******************************************/
