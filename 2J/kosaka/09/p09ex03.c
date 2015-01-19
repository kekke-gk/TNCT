/***  p09ex03.c  ***/
/***  s12083  2J18  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

void right(char *d,char *s,int);
int mystrlen(char *str);

int main()
{
	char str1[]="exercises";
	char str2[32]="abcdefghijklmn";
	char str3[32]="abcdefghijklmn";
	right(str2,str1,5);
	puts(str2);
	right(str3,str1,10);
	puts(str3);
	return 0;
}

void right(char *d,char *s,int n)
{
	int i,ld,ls;
	char *d2;
	d2=d;
	ls=mystrlen(s);
	ld=mystrlen(d);
	for(i=0;i<ld+1;i++){
		*d2='\0';
		d2+=sizeof(char);
	}
	if(ls-n<0) n=ls;
	for(i=0;i<n;i++){
		*(d+i*sizeof(char))=*(s+(ls-n+i)*sizeof(char));
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
cises
exercises
*******************************************/
