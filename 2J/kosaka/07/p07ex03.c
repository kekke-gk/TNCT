/***  p07ex03.c  ***/
/***  s12083  1320  五味京祐  ***/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char textbuffer[512]={0};
	char filename[100];
	int lineNumber=0;
	int charNumber=0;
	int i=0;
	
	printf("ファイル名を入力してください。");
	gets(filename);
	
	fp=fopen(filename,"r");
	if(fp==NULL){
		printf("can't open file <%s>\n",filename);
		exit(1);
	}
	
	while( fgets(textbuffer,512,fp) != NULL ){
		while(textbuffer[i]) i++;
		charNumber+=i;
		lineNumber++;
	}
	fclose(fp);
	
	printf("行数 %d, 文字数 %d\n",lineNumber,charNumber);
	return 0;
}


/**************** 実行結果 *****************
ファイル名を入力してください。03.c
行数 7, 文字数 150

*******************************************/
