/***  p05ex06.c  ***/
/***  s12083  1320  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

void left(char d[],char s[],int n)
{
	int i=0;
	while(d[i]!=0){
		d[i]=0;
		i++;
	}
	for(i=0;i<n;i++){
		d[i]=s[i];
	}
}

int main()
{
	char str1[]="exercises";
	char str2[32]="abcdefghijklmn";
	char str3[32]="abcdefghijklmn";
	left(str2,str1,5);
	puts(str2);
	left(str3,str1,10);
	puts(str3);

	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************
exerc
exercises

*******************************************/
