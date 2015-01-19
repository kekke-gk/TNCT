/***  p04ex02.c  ***/
/***  s12083  2J18  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

int main()
{
	int i,m,d,a=0,numberofdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	printf("month day=");
	scanf("%d %d",&m,&d);
	for(i=1;i<m;i++){
		a+=numberofdays[i];
	}
	printf("%d\n",a+d);
	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************
month day=1 25
25

month day=3 2
61

*******************************************/
