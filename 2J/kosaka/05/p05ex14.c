/***  p05ex14.c  ***/
/***  s12083  1320  五味京祐  ***/

#include <stdio.h>

int checkString(char s[]);
void generateNumber(char theNumber[]);
int countHit(char s1[],char s2[]);
int countBlow(char s1[],char s2[]);

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
		}
		if(checkString(theNumber) == 0) break;
	}
}

int countHit(char s1[],char s2[])
{
	int i,count=0;
	for(i=0;i<4;i++){
		if(s1[i]==s2[i]) count++;
	}
	return count;
}

int countBlow(char s1[],char s2[])
{
	int i,j,count=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(s1[i]==s2[j] && i!=j){
				count++;
			}
		}
	}

	return count;
}


int main()
{
	char num[5],inum[5];
	int check,hit,blow,count=0;
	srand((unsigned) time(NULL));
	generateNumber(num);

	do{
		while(1){
			if(count == 0){
				printf("ヒットアンドブローゲーム有効文字列を入力してください。\n");
			}
			gets(inum);
			check=checkString(inum);
			if(check == 1){
				printf("もう一度入力してください。\n");
			}else break;
		}
		
		hit=countHit(num,inum);
		blow=countBlow(num,inum);
		printf("ヒット数 %d, ブロー数 %d\n\n",hit,blow);
		count++;
	}while(hit != 4);

	printf("%d 回で正解できました。\n",count);
	return 0;
}


/**************** 実行結果 *****************
ヒットアンドブローゲーム有効文字列を入力してください。
0123
ヒット数 0, ブロー数 1

4567
ヒット数 0, ブロー数 3

4568
ヒット数 0, ブロー数 2

4587
ヒット数 0, ブロー数 3

4507
ヒット数 0, ブロー数 4

5470
ヒット数 2, ブロー数 2

7054
ヒット数 0, ブロー数 4

7450
ヒット数 1, ブロー数 3

5740
ヒット数 4, ブロー数 0

9 回で正解できました。
*******************************************/
