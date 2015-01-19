/***  p09ex02.c  ***/
/***  s12083  2J18  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

void left(char *d,char *s,int n);
int mystrlen(char *str);

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

void left(char *d,char *s,int n)
{
	int i,l;
	char *d2;
	d2=d;
	l=mystrlen(d);
	for(i=0;i<l+1;i++){
		*d2='\0';
		d2+=sizeof(char);
	}
	for(i=0;i<n;i++){
		*d=*s;
		d+=sizeof(char);
		s+=sizeof(char);
	}
}

int mystrlen(char *str)
{
	int count=0;
	while(*str!='\0'){
		str+=sizeof(char);
		count++;
	}
	
	return count;
}

/**************** ŽÀsŒ‹‰Ê *****************
exerc
exercises
*******************************************/
