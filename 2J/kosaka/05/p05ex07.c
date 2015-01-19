/***  p05ex07.c  ***/
/***  s12083  1320  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

void right(char d[],char s[],int n)
{
	int i,p=0,q=0;
	while(d[p]!=0){
		d[p]=0;
		p++;
	}
	while(s[q]!=0){
		q++;
	}
	if(q-n<0) q=n;
	for(i=0;i<n;i++){
		d[i]=s[q-n+i];
	}
}

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


/**************** ŽÀsŒ‹‰Ê *****************
cises
exercises
*******************************************/
