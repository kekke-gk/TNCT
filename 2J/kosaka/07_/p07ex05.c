/***  p07ex05.c  ***/
/***  s12083  1320  五味京祐  ***/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	FILE *fin,*fout;
	char inname[100],outname[100];
	int ch[512]={0};
	int i=0,count=0,inw=1;

	printf("入力ファイル名を入力してください。\n");
	gets(inname);
	printf("出力ファイル名を入力してください。\n");
	gets(outname);
	
	fin=fopen(inname,"r");
	if(fin==NULL){
		printf("can't open %s\n",inname);
		exit(1);
	}
	fout=fopen(outname,"w");
	if(fout==NULL){
		printf("can't open %s\n",outname);
		exit(1);
	}

/*
①英数字かアンダーバーの直後の，英数字かアンダーバー
②英数字かアンダーバー以外の直後の，英字
①，②をまとめて”有効な文字”と呼ぶこととする。
また有効な文字以外の文字を，”有効ではない文字”と呼ぶこととする。
有効な文字が入力された場合，inwには０を代入する。
有効ではない文字が入力された場合，inwには１を代入する。

有効な文字の直後に｛
	有効な文字を読み込んだ場合はそのまま出力する。
	有効なではない文字を読み込んだ場合はcount++をし，次の二つに分岐する。
		１．countを８で割った余りが０だったら改行。
		２．countを８で割った余りが０以外だったら空白。
｝
有効ではない文字の直後に｛
	有効な文字を読み込んだ場合はそのまま出力する。
	有効ではない文字を読み込んだ場合何もしない。
｝
*/
	while(1){
		ch[i]=fgetc(fin);
		if(ch[i]==EOF){
			fclose(fin);
			fclose(fout);
			return 0;
		}
		if( ((isalnum(ch[i])!=0 || ch[i]=='_')&&inw==0) || (isalnum(ch[i])!=0 && inw==1 && (ch[i]<'0' || '9'<ch[i])) ){
			inw=0;
			fputc(ch[i],fout);
		}else if(inw==0){
			count++;
			if(count%8==0){
				fprintf(fout,"\n");
			}else fprintf(fout," ");
			inw=1;
		}
		i++;
	}
}


/**************** 実行結果 *****************
wer qwe123 wer456 sw_qwe q12_12 qwe A123B123 wsed_123
*******************************************/
