/***  p09ex01.c  ***/
/***  s12083  2J18  ŒÜ–¡‹—S  ***/

#include <stdio.h>

int mystrlen(char *str)
{
	int count=0;
	while(*str!='\0'){
		str+=sizeof(char);
		count++;
	}
	
	return count;
}

int main()
{
	char  str1[]="exercises";
	char  str2[]="pointer programing";
	int cnt1,cnt2;
	cnt1=mystrlen(str1);
	cnt2=mystrlen(str2);
	printf("%s %d\n",str1,cnt1);
	printf("%s %d\n",str2,cnt2);
	return 0;
}


/**************** ÀsŒ‹‰Ê *****************
exercises 9
pointer programing 18
*******************************************/
