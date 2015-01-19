/***  p04ex09.c  ***/
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
	if(str1[0]==str2[0]&&str1[1]==str2[1]&&str1[2]==str2[2]) printf("equal\n");
	else printf("not equal\n");

	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************
str1= robot
str2= root
robot root => not equal

str1= speaker
str2= speech
speaker speech => equal

str1= time
str2= game
time game => not equal

str1= sea
str2= see
sea see => not equal

str1= see
str2= seen
see seen => equal
*******************************************/
