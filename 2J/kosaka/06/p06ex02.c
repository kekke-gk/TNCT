/***  p06ex02.c  ***/
/***  s12083  2J18  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

double movingAverage(int var)
{
	static int buffer[6]={0};
	static int putpos=5;
	static int getpos=5;
	static double ave=0;
	
	buffer[putpos]=var;
	
	ave+=buffer[putpos];
	putpos++;
	if(putpos==6) putpos=0;
	
	getpos++;
	if (getpos==6) getpos=0;
	ave-=buffer[getpos];
	
	
	return ave/5;
}

int main()
{
	int x;
	double y;
	for(x=0;x<10;x++) {
		y=movingAverage(x);
		printf("x=%6d y=%10.2lf\n",x,y);
	}

	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************
x=     0 y=      0.00
x=     1 y=      0.20
x=     2 y=      0.60
x=     3 y=      1.20
x=     4 y=      2.00
x=     5 y=      3.00
x=     6 y=      4.00
x=     7 y=      5.00
x=     8 y=      6.00
x=     9 y=      7.00

*******************************************/
