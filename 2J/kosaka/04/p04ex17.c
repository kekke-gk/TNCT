/***  p04ex17.c  ***/
/***  s12083  2J18  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

int main()
{
	int i,testdata[20]={0};
	for(i=2*2;i<20;i+=2) testdata[i]=1;
	for(i=3*2;i<20;i+=3) testdata[i]=1;
	for(i=0;i<20;i++) printf("%d",testdata[i]);
	printf("\n");

	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************
00001010111010111010

*******************************************/
