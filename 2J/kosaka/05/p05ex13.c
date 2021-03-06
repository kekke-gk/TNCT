/***  p05ex13.c  ***/
/***  s12083  1320  五味京祐  ***/

#include <stdio.h>
#include <time.h>

int checkString(char s[]);
void generateNumber(char theNumber[]);

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


void generateNumber(char theNumber[])
{
	int i=0;
	while(theNumber[i]!=0){
		theNumber[i]=0;
		i++;
	}
	while(1){
		for(i=0;i<4;i++){
			theNumber[i]=rand()%10+'0';
//			printf("%c", theNumber[i]);
		}
		
		if(checkString(theNumber) == 0) break;
	}
}

int main()
{
	char aNumber[10]="abcdefg"; /*検証のために意味のない文字列を初期値とする*/
	int count;
	srand((unsigned) time(NULL));/*乱数列生成の初期化*/
	for (count=0; count<10; count++) {
		generateNumber(aNumber);
		puts(aNumber);
	}

	return 0;
}


/**************** 実行結果 *****************
3649
4913
2941
1679
2034
7890
6295
8659
4081
7465

*******************************************/
