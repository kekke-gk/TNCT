/***  p07ex05.c  ***/
/***  s12083  1320  �ܖ����S  ***/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	FILE *fin,*fout;
	char inname[100],outname[100];
	int ch[512]={0};
	int i=0,count=0,inw=1;

	printf("���̓t�@�C��������͂��Ă��������B\n");
	gets(inname);
	printf("�o�̓t�@�C��������͂��Ă��������B\n");
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
�@�p�������A���_�[�o�[�̒���́C�p�������A���_�[�o�[
�A�p�������A���_�[�o�[�ȊO�̒���́C�p��
�@�C�A���܂Ƃ߂āh�L���ȕ����h�ƌĂԂ��ƂƂ���B
�܂��L���ȕ����ȊO�̕������C�h�L���ł͂Ȃ������h�ƌĂԂ��ƂƂ���B
�L���ȕ��������͂��ꂽ�ꍇ�Cinw�ɂ͂O��������B
�L���ł͂Ȃ����������͂��ꂽ�ꍇ�Cinw�ɂ͂P��������B

�L���ȕ����̒���Ɂo
	�L���ȕ�����ǂݍ��񂾏ꍇ�͂��̂܂܏o�͂���B
	�L���Ȃł͂Ȃ�������ǂݍ��񂾏ꍇ��count++�����C���̓�ɕ��򂷂�B
		�P�Dcount���W�Ŋ������]�肪�O����������s�B
		�Q�Dcount���W�Ŋ������]�肪�O�ȊO��������󔒁B
�p
�L���ł͂Ȃ������̒���Ɂo
	�L���ȕ�����ǂݍ��񂾏ꍇ�͂��̂܂܏o�͂���B
	�L���ł͂Ȃ�������ǂݍ��񂾏ꍇ�������Ȃ��B
�p
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


/**************** ���s���� *****************
wer qwe123 wer456 sw_qwe q12_12 qwe A123B123 wsed_123
*******************************************/
