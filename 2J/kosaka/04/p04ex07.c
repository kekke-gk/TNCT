/***  p04ex07.c  ***/
/***  s12083  2J18  å‹ñ°ãûóS  ***/

#include <stdio.h>

int main()
{
	int i=0,count=0;
	char txt[100];
	gets(txt);
	while(txt[i]!=0){
		if(txt[i]=='e') count++;
		i++;
	}
	printf("%d\n",count);

	return 0;
}


/**************** é¿çsåãâ  *****************
abcdefg
1

I'm getting closer to my home.
3

Kunugidamachi Hachioji Tokyo
0

eeeee
5

I want little sister.
2
*******************************************/
