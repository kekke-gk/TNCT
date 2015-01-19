/***  p04ex13.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>

int main()
{
	char str[301]={0};
	int a=0,e=0,i=0,o=0,u=0,j;
	printf("文字列を入力してください\n");
	gets(str);
	printf("入力された文字列は次のものです。\n%s\n",str);
	for(j=0;j<301;j++){
		if(str[j]=='a' || str[j]=='A') a++;
		if(str[j]=='e' || str[j]=='E') e++;
		if(str[j]=='i' || str[j]=='I') i++;
		if(str[j]=='o' || str[j]=='O') o++;
		if(str[j]=='u' || str[j]=='U') u++;
	}
	printf("集計結果\n");
	printf("number of vowels A,a=	%d\n",a);
	printf("number of vowels E,e=	%d\n",e);
	printf("number of vowels I,i=	%d\n",i);
	printf("number of vowels O,o=	%d\n",o);
	printf("number of vowels U,u=	%d\n",u);

	return 0;
}


/**************** 実行結果 *****************
文字列を入力してください
hello!
入力された文字列は次のものです。
hello!
集計結果
number of vowels A,a=   0
number of vowels E,e=   1
number of vowels I,i=   0
number of vowels O,o=   1
number of vowels U,u=   0

文字列を入力してください
Over this year, I have seen many Japanese entertainment show on television that
are obviously supposed to make people laugh and have a good time. However, some
of these shows are not funny at all.
入力された文字列は次のものです。
Over this year, I have seen many Japanese entertainment show on television that
are obviously supposed to make people laugh and have a good time. However, some
of these shows are not funny at all.
集計結果
number of vowels A,a=   16
number of vowels E,e=   25
number of vowels I,i=   7
number of vowels O,o=   16
number of vowels U,u=   4
*******************************************/
