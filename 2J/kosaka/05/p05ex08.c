/***  p05ex08.c  ***/
/***  s12083  1320  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

void mid(char d[],char s[],int m,int n)
{
	int i,j=0,k=0;
	while(d[j]!=0){
		d[j]=0;
		j++;
	}
	while(s[k]!=0){
		k++;
	}
	if(k<m){
		d[0]='\0';
		return;
	}
	for(i=0;i<n;i++){
		d[i]=s[m+i-1];
		//d[i]=s[m+i];
	}
}

int main()
{
	char str1[]="exercises";
	char str2[32]="abcdefghijklmn";
	char str3[32]="abcdefghijklmn";
	char str4[32]="abcdefghijklmn";
	puts(str1);
	mid(str2,str1,2,5);
	puts(str2);
	mid(str3,str1,2,10);
	puts(str3);
	mid(str4,str1,12,3);
	puts(str4);
	printf("%d\n",str4[0]);
	return 0;
}

/**************** ŽÀsŒ‹‰Ê *****************
exercises
xerci
xercises

0
*******************************************/
