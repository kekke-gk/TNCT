/***  p05ex10.c  ***/
/***  s12083  1320  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

int checkString(char s[]);

int main()
{
	char s1[]="1234";
	char s2[]="123";
	char s3[]="12345";
	char s4[]="A123";
	char s5[]="123#";
	char s6[]="1231";

	printf("%5s => %d\n",s1,checkString(s1) );
	printf("%5s => %d\n",s2,checkString(s2) );
	printf("%5s => %d\n",s3,checkString(s3) );
	printf("%5s => %d\n",s4,checkString(s4) );
	printf("%5s => %d\n",s5,checkString(s5) );
	printf("%5s => %d\n",s6,checkString(s6) );

	return 0;
}

int checkString(char s[])
{
	int i,j,size=0;
	while(s[size]!=0){
		size++;
	}
	for(i=0;i<4;i++){
		if(s[i]<'0' || s[i]>'9'){
			return 1;
		}
	}
	if(s[0]==s[1] || s[0]==s[2] || s[0]==s[3] || s[1]==s[2] || s[1]==s[3] || s[2]==s[3]){
		return 1;
	}
	if(size != 4){
		return 1;
	}
	return 0;
}

/**************** ŽÀsŒ‹‰Ê *****************
 1234 => 0
  123 => 1
12345 => 1
 A123 => 1
 123# => 1
 1231 => 1

*******************************************/
