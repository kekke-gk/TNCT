/***  p09ex05.c  ***/
/***  s12083  2J18  ŒÜ–¡‹—S  ***/

#include <stdio.h>

void reverseString(char *s);
int mystrlen(char *str);

int main()
{
	char  str1[]="exercises";
	char  str2[]="pointer programing";
	puts(str1);
	reverseString(str1);
	puts(str1);
	puts(str2);
	reverseString(str2);
	puts(str2);
	return 0;
}

void reverseString(char *s)
{
	int i,l;
	char a;
	l=mystrlen(s);
	for(i=0;i<l/2;i++){
		a=*(s+i*sizeof(char));
		*(s+i*sizeof(char))=*(s+(l-1-i)*sizeof(char));
		*(s+(l-1-i)*sizeof(char))=a;
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


/**************** ÀsŒ‹‰Ê *****************
exercises
sesicrexe
pointer programing
gnimargorp retniop
*******************************************/
