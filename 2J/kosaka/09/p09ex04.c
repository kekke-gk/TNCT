/***  p09ex04.c  ***/
/***  s12083  2J18  ŒÜ–¡‹—S  ***/

#include <stdio.h>

void mid(char *d,char *s,int,int);
int mystrlen(char *str);

int main()
{
	char str1[]="exercises";
	char str2[32]="abcdefghijklmn";
	char str3[32]="abcdefghijklmn";
	puts(str1);
	mid(str2,str1,2,5);
	puts(str2);
	mid(str3,str1,2,10);
	puts(str3);
	return 0;
}

void mid(char *d,char *s,int m,int n)
{
	int i,ld,ls;
	char *d2;
	d2=d;
	ld=mystrlen(d);
	ls=mystrlen(s);
	for(i=0;i<ld+1;i++){
		*d2='\0';
		d2+=sizeof(char);
	}

	if(m<=ls){
		for(i=0;i<n;i++){
			*(d+i*sizeof(char))=*(s+(i+m-1)*sizeof(char));
		}
	}else{
		*d='\0';
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
xerci
xercises
*******************************************/
