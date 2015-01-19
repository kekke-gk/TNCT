/***  p07ex04.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>
#include<stdlib.h>

void reverseString(char string[])
{
	int i=0,j;
	char tmp[100];
	while(string[i]!='\0'){
		tmp[i]=string[i];
		i++;
	}
	for(j=0;j<i;j++){
		string[j]=tmp[i-j-1];
	}
}

int main()
{
	FILE *fin,*fout;
	char finame[30],foname[30],text[300]={0};
	int len=0,check=0;
	
	printf("読み込むファイル名を入力してください。\n");
	gets(finame);
	printf("書き込むファイル名を入力してください。\n");
	gets(foname);
	fin=fopen(finame,"r");
	fout=fopen(foname,"w");
	if(fin==NULL || fout==NULL){
		printf("can not open a file\n");
		exit(1);
	}
	
	while(fgets(text,300,fin)!=NULL){
		while(text[len]!=0) len++;
		if(text[len-1] == '\n'){
			text[len-1]=0;
			check=1;
		}
		reverseString(text);
		if(check==1){
			text[len-1]='\n';
		}
		fputs(text,fout);
		len=0;
		check=0;
	}

	return 0;
}


/**************** 実行結果 *****************
>h.oidts< edulcni#

)(niam tni
{
;)"n\?uoy era woH .olleH"(ftnirp    
;)"n\?uoY dnA .sknaht ,eniF"(ftnirp    
;)"n\.os oS"(ftnirp    
;0 nruter    
}

*******************************************/