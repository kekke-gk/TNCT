/***  p05ex15.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>//srandのため

int checkString(char s[]);
int countHit(char s1[],char s2[]);
int countBlow(char s1[],char s2[]);
void generateNumber(char theNumber[]);
void start();
int humTurn();
int comTurn();

typedef struct{
	int check;
	char s[5];
}string_t;

char cs[5]={0};//Computer String
string_t alst[5040]={0};//All String  10permutation4で５０４０通り

int main()
{
	int check;
	start();
	
	while(1){
		if(humTurn()){
			check=0;
			break;
		}
		
		if(comTurn()){
			check=1;
			break;
		}
	}

	switch(check){
		case 0:
			printf("\nあなたの勝ちです。\n");
			break;

		case 1:
			printf("\n私の勝ちです。\n");
			break;
	}
	return 0;
}


int humTurn()
{
	char s[5];
	int h,b,count=0;
	printf("\nあなたの番です。\n");
	printf("私の用意した数字を予想して4桁の数字を入力してください。\n");
	scanf("%s",s);
	
	while(checkString(s)){
		count++;
		if(count>3){
			printf("\n間違えすぎです。\n");
			exit(1);
		}
		printf("おかしな数字を入力しないでください。\n");
		printf("もう一度入力してください。\n");
		scanf("%s",s);
	}
	
	h=countHit(cs,s);

	if(h == 4) return 1;

	b=countBlow(cs,s);
	
	printf("\nはずれです。\n");
	printf("Hit: %d  Blow: %d\n",h,b);
	
	return 0;
}


int comTurn()
{
	char s[5]={0};
	int h,b,count=0,i=0,check=0,tmp;

	printf("\n私の番です。\n");

//可能性のあるものからランダムに選択
	while(1){
		tmp=rand()%5040;
		if(!alst[tmp].check){
			strcpy(s,alst[tmp].s);
			break;
		}
	}

	printf("%s ではないでしょうか？\n",s);
	printf("Hit Blowの順に入力してください。\n");
	printf("嘘はつかないでくださいね。\n");
	scanf("%d %d",&h,&b);

	while(h>4 || b>4 || h<0 || b<0 || (h==3&&b==1)){
		count++;
		if(count>3){
			printf("\n間違えすぎです。\n");
			exit(1);
		}
		printf("おかしな数字を入力しないでください。\n");
		printf("もう一度入力してください。\n");
		scanf("%d %d",&h,&b);
	}
	
	if(h == 4){
		return 1;
	}

	for(i=0;i<5040;i++){
		if(	countBlow(s,alst[i].s)!=b || countHit(s,alst[i].s)!=h){
			alst[i].check=1;
		}
	}

//checkが０である（可能性のある）パターンが存在しなかったら
//それはプレイヤーの入力ミスであるので終了する。
	for(i=0;i<5040;i++){
		if( !alst[i].check ){
			check=1;
			break;
		}
	}
	if(!check){
		printf("\nあなた，嘘をつきましたね。\n");
		printf("私はあなたのことが嫌いです。\n");
		exit(1);
	}

	return 0;
}


void start()
{
	int i,j,count=0,check=0;

	srand((unsigned) time(NULL));

	generateNumber(cs);

	for(i=0;i<5040;i++){
		alst[i].s[0]='0';
		alst[i].s[1]='0';
		alst[i].s[2]='0';
		alst[i].s[3]='0';
		alst[i].s[4]=0;
		alst[i].check=0;
	}

//１００００回繰り返して０１２３～９８７６までの
//ヒットアンドブロー有効文字列をすべて代入する
	for(i=0;i<10000;i++){
		alst[count].s[3]++;

//繰り上がり計算
		for(j=3;j>=1;j--){
			if(alst[count].s[j]>'9'){
				alst[count].s[j-1]++;
				alst[count].s[j]-=10;
			}
		}
		
//もしも９８７６だったら終わり
		check=0;
		for(j=0;j<4;j++){
			if(alst[count].s[j] != '9'-j){
				check=1;
				break;
			}
		}
		if(!check) break;

	
//正しい4文字だったら
		if( !checkString(alst[count].s) ){
			strcpy(alst[count+1].s,alst[count].s);
			count++;
		}

			
	}

	printf("では，始めましょう。\n");
	printf("互いに異なる4桁の数字を用意してください。忘れないようにしてくださいね。\n");
	printf("準備ができたらspaceを押してください。\n");
	while(getch() != ' ');
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
			if(s1[i]==s2[j]){
				count++;
			}
		}
	}

	return count-countHit(s1,s2);
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


/**************** 実行結果 *****************
では，始めましょう。
互いに異なる4桁の数字を用意してください。忘れないようにしてくださいね。
準備ができたらspaceを押してください。

あなたの番です。
私の用意した数字を予想して4桁の数字を入力してください。
1234

はずれです。
Hit: 1  Blow: 1

私の番です。
3784 ではないでしょうか？
Hit Blowの順に入力してください。
嘘はつかないでくださいね。
1 1

あなたの番です。
私の用意した数字を予想して4桁の数字を入力してください。
5678

はずれです。
Hit: 0  Blow: 1

私の番です。
7954 ではないでしょうか？
Hit Blowの順に入力してください。
嘘はつかないでくださいね。
1 0

あなたの番です。
私の用意した数字を予想して4桁の数字を入力してください。
1290

はずれです。
Hit: 1  Blow: 2

私の番です。
6034 ではないでしょうか？
Hit Blowの順に入力してください。
嘘はつかないでくださいね。
1293
2
おかしな数字を入力しないでください。
もう一度入力してください。


2 0

あなたの番です。
私の用意した数字を予想して4桁の数字を入力してください。
1293

はずれです。
Hit: 1  Blow: 2

私の番です。
6824 ではないでしょうか？
Hit Blowの順に入力してください。
嘘はつかないでくださいね。
1 1

あなたの番です。
私の用意した数字を予想して4桁の数字を入力してください。
1295

はずれです。
Hit: 2  Blow: 2

私の番です。
2134 ではないでしょうか？
Hit Blowの順に入力してください。
嘘はつかないでくださいね。
2 2

あなたの番です。
私の用意した数字を予想して4桁の数字を入力してください。
1925

はずれです。
Hit: 1  Blow: 3

私の番です。
1234 ではないでしょうか？
Hit Blowの順に入力してください。
嘘はつかないでくださいね。
4 0

私の勝ちです。

*******************************************/
