/***  p07ex03.c  ***/
/***  s12083  2J18  �ܖ����S  ***/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char fn[30],text[100]={0};
	int ln=0,cn=0,i=0;
	
	printf("�t�@�C��������͂��Ă��������B\n");
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
	
	printf("�s�� %d, ������ %d\n",ln,cn);

	return 0;
}


/**************** ���s���� *****************
�t�@�C��������͂��Ă��������B
03.c
�s�� 7, ������ 150

*******************************************/
