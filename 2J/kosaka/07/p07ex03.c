/***  p07ex03.c  ***/
/***  s12083  1320  �ܖ����S  ***/

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
	
	printf("�t�@�C��������͂��Ă��������B");
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
	
	printf("�s�� %d, ������ %d\n",lineNumber,charNumber);
	return 0;
}


/**************** ���s���� *****************
�t�@�C��������͂��Ă��������B03.c
�s�� 7, ������ 150

*******************************************/
