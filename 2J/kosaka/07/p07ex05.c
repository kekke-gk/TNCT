/***  p07ex05.c  ***/
/***  s12083  1320  五味京祐  ***/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	FILE *fin;
	FILE *fout;
	char inname[100],outname[100];
	int ch[512]={0};
	int i=0,count=0,inw=1;

	printf("入力ファイル名を入力してください。");
	gets(inname);
	printf("出力ファイル名を入力してください。");
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

//inwが０のとき英数字の中
/*
inwが１のときは読み込んだ文字がアルファベットのときのみ出力する。
inwが０のときは読み込んだ文字が英数字かアンダーバーだったら出力する。
inwが１のときに読み込んだ文字が英数字以外だったらcount++をして次の二つに分岐する。
	countを８で割った余りが０だったら改行。
	countを８で割った余りが０以外だったら空白。
inwが０のときに読み込んだ文字が英数字以外だったら何もしない。
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
		}else{
			if(inw==0){
				count++;
				if(count%8==0){
					fprintf(fout,"\n");
				}else fprintf(fout," ");
			}
			inw=1;
		}
		i++;
	}
	return 0;
}


/**************** 実行結果 *****************
wer qwe123 wer456 sw_qwe q12_12 qwe A123B123 wsed_123
*******************************************/
