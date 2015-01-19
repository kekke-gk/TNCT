/***  p05ex09.c  ***/
/***  s12083  1320  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

void reverseString(char s[])
{
	char str[100];
	int i=0,n;
	while(s[i]!=0){
		i++;
	}
	for(n=0;n<i;n++){
		str[n]=s[i-n-1];
	}
	for(n=0;n<i;n++){
		s[n]=str[n];
	}
}

int main()
{
	char str[]="exercises";
	
	puts(str);
	reverseString(str);
	puts(str);

	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************
exercises
sesicrexe

*******************************************/
