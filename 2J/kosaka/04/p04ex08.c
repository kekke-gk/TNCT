/***  p04ex08.c  ***/
/***  s12083  2J18  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

int main()
{
	char str1[100],str2[100];
	printf("str1= ");
	gets(str1);
	printf("str2= ");
	gets(str2);
	printf("%s %s => ",str1,str2);
	if(str1[0]==str2[0]){
		printf("equal\n");
	}else printf("not equal\n");
	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************
str1= robot
str2= atom
robot atom => not equal

str1= robot
str2= rocket
robot rocket => equal

str1= pan
str2= pen
pan pen => equal

str1= sea
str2= see
sea see => equal

str1= abc
str2= def
abc def => not equal
*******************************************/
