/***  p07ex05.c  ***/
/***  s12083  1320  �ܖ����S  ***/

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

	printf("���̓t�@�C��������͂��Ă��������B");
	gets(inname);
	printf("�o�̓t�@�C��������͂��Ă��������B");
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

//inw���O�̂Ƃ��p�����̒�
/*
inw���P�̂Ƃ��͓ǂݍ��񂾕������A���t�@�x�b�g�̂Ƃ��̂ݏo�͂���B
inw���O�̂Ƃ��͓ǂݍ��񂾕������p�������A���_�[�o�[��������o�͂���B
inw���P�̂Ƃ��ɓǂݍ��񂾕������p�����ȊO��������count++�����Ď��̓�ɕ��򂷂�B
	count���W�Ŋ������]�肪�O����������s�B
	count���W�Ŋ������]�肪�O�ȊO��������󔒁B
inw���O�̂Ƃ��ɓǂݍ��񂾕������p�����ȊO�������牽�����Ȃ��B
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


/**************** ���s���� *****************
wer qwe123 wer456 sw_qwe q12_12 qwe A123B123 wsed_123
*******************************************/
