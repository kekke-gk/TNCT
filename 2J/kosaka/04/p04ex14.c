/***  p04ex14.c  ***/
/***  s12083  2J18  ŒÜ–¡‹—S  ***/

#include <stdio.h>

int main()
{
	char dayofweek[7][20]={
		"Sunday","Monday","Tuesday","Wednesday","Thrthday","Friday","Saturday"
	};
	int str;
	printf("number = ");
	scanf("%d",&str);
	printf("%s\n",dayofweek[str-1]);

	return 0;
}


/**************** ÀsŒ‹‰Ê *****************
number = 1
Sunday

number = 3
Tuesday

number = 2
Monday

number = 4
Wednesday

number = 5
Thrthday

number = 6
Friday

number = 7
Saturday
*******************************************/
