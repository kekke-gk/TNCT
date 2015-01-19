/***  p07ex04.c  ***/
/***  s12083  1320  五味京祐  ***/

#include <stdio.h>
#include <stdlib.h>

void reverseString(char string[])
{
	char string2[100];
	int i=0,j;
	
	while(string[i]){
		string2[i]=string[i];
		i++;
	}
	for(j=0;j<i;j++){
		string[j]=string2[i-j-1];
	}
}

int main()
{
	FILE *fin;
	FILE *fout;
	char infilename[100],outfilename[100];
	char textbuffer[512]={0},textbuffer2[512]={0};
	int i=0,j;
	
	printf("読み込みファイル名を入力してください。");
	gets(infilename);
	fin=fopen(infilename,"r");
	printf("書き出しファイル名を入力してください。");
	gets(outfilename);
	fout=fopen(outfilename,"w");
	
	if(fin==NULL){
		printf("can't open file <%s>\n",infilename);
		exit(1);
	}
	if(fout==NULL){
		printf("can't open file <%s>\n",outfilename);
		exit(1);
	}
	
	while( fgets(textbuffer,512,fin) != NULL ){
		//while( textbuffer[i]) i++;
		//for(j=0;j<i-1;j++){
		//	textbuffer2[j]=textbuffer[j];
		//}
		//reverseString(textbuffer2);
		//fprintf(fout,"%s\n",textbuffer2);
		reverseString(textbuffer);
		fprintf(fout,"%s",textbuffer);
		for(i=0;i<512;i++){
			textbuffer[i]=0;
			textbuffer2[i]=0;
		}
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
