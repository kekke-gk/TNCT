/***  p07ex06.c  ***/
/***  s12083  1320  五味京祐  ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int count;
	char s[50];
}str_t;

int main()
{
	FILE *fin,*fout;
	char inname[100],outname[100],ch[50];//chはとりあえず入れておく変数。
	int i=0,count=0,j,k,check=0,inw=1;//countは単語の種類を数える
	str_t str[50];
	
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			str[i].s[j]='\0';
		}
		str[i].count=0;
		ch[i]=0;
	}
	i=0;
	j=0;
	
	printf("入力ファイル名を入力してください。");
	gets(inname);
	printf("出力ファイル名を入力してください。");
	gets(outname);
	
	fin=fopen(inname,"r");
	fout=fopen(outname,"w");
	if(fin==NULL){
		printf("can't open %s\n",inname);
		exit(1);
	}
	if(fout==NULL){
		printf("can't open %s\n",outname);
		exit(1);
	}

/*
基本はp07ex05と同じ。
①英数字かアンダーバーの直後の，英数字かアンダーバー
②英数字かアンダーバー以外の直後の，英字
①，②をまとめて”有効な文字”と呼ぶこととする。
また有効な文字以外の文字を，”有効ではない文字”と呼ぶこととする。
有効な文字が入力された場合，inwには０を代入する。
有効ではない文字が入力された場合，inwには１を代入する。

有効な文字の直後に｛
	有効な文字を読み込んだ場合はi++。
	有効なではない文字を読み込んだ場合は
		たった今読み込んだ文字は有効ではない文字であるので消去
		chと同じ文字列がstrのどこかにあるかどうか確認{
			あった場合，あった場所のstr[?].countに１を足す。checkに１を代入。
			なかった場合，次のstr.sにchを代入。count++。
		}
		chをクリア。
｝
有効ではない文字の直後に｛
	有効な文字を読み込んだ場合はi++
	有効ではない文字を読み込んだ場合何もしない。
｝

*/
	while(1){
		ch[i]=fgetc(fin);
		if(ch[i]==EOF){
			break;
		}
		if( ((isalnum(ch[i]) || ch[i]=='_')&&inw==0) || (isalnum(ch[i]) && inw==1 && (ch[i]<'0' || '9'<ch[i])) ){
			inw=0;
			i++;
		}else if(inw==0){
			ch[i]='\0';
			for(j=0;j<count;j++){
				if(strcmp(str[j].s , ch) == 0){
					str[j].count++;
					check=1;
					break;
				}
			}
			if(check==0){
				strcpy(str[count].s,ch);
				str[count].count++;
				count++;
				check=0;
			}
			for(k=0;k<50;k++){
				ch[k]='\0';
			}
			check=0;
			i=0;
			inw=1;
		
		}
	}
	
	for(i=0;i<count;i++){
		fprintf(fout,"%s %d\n",str[i].s,str[i].count);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

/**************** 実行結果 *****************
include 1
stdio 1
h 1
int 1
main 1
printf 3
Hello 1
How 1
are 1
you 1
n 3
Fine 1
thanks 1
And 1
You 1
So 1
so 1
return 1


*******************************************/
