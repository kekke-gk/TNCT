/***  p07ex03.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char fn[30],text[100]={0};
	int ln=0,cn=0,i=0;
	
	printf("ファイル名を入力してください。\n");
	gets(fn);
	fp=fopen(fn,"r");
	if(fp==NULL){
		printf("can not open a file\n");
		exit(1);
	}
	
	while(fgets(text,100,fp) != NULL){
		while(text[i]) i++;
		cn+=i;
		ln++;
	}
	fclose(fp);
	
	printf("行数 %d, 文字数 %d\n",ln,cn);

	return 0;
}


/**************** 実行結果 *****************
ファイル名を入力してください。
03.c
行数 7, 文字数 150

*******************************************/
