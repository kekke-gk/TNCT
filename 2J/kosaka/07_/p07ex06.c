/***  p07ex06.c  ***/
/***  s12083  1320  �ܖ����S  ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int count;
	char s[50];
}str_t;

int main()
{
	FILE *fin,*fout;
	char inname[100],outname[100],ch[50];//ch�͂Ƃ肠��������Ă����ϐ��B
	int i=0,count=0,j,k,check=0,inw=1;//count�͒P��̎�ނ𐔂���
	str_t str[50];
	
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			str[i].s[j]='\0';
		}
		str[i].count=0;
		ch[i]=0;
	}
	i=0;
	j=0;
	
	printf("���̓t�@�C��������͂��Ă��������B");
	gets(inname);
	printf("�o�̓t�@�C��������͂��Ă��������B");
	gets(outname);
	
	fin=fopen(inname,"r");
	fout=fopen(outname,"w");
	if(fin==NULL){
		printf("can't open %s\n",inname);
		exit(1);
	}
	if(fout==NULL){
		printf("can't open %s\n",outname);
		exit(1);
	}

/*
��{��p07ex05�Ɠ����B
�@�p�������A���_�[�o�[�̒���́C�p�������A���_�[�o�[
�A�p�������A���_�[�o�[�ȊO�̒���́C�p��
�@�C�A���܂Ƃ߂āh�L���ȕ����h�ƌĂԂ��ƂƂ���B
�܂��L���ȕ����ȊO�̕������C�h�L���ł͂Ȃ������h�ƌĂԂ��ƂƂ���B
�L���ȕ��������͂��ꂽ�ꍇ�Cinw�ɂ͂O��������B
�L���ł͂Ȃ����������͂��ꂽ�ꍇ�Cinw�ɂ͂P��������B

�L���ȕ����̒���Ɂo
	�L���ȕ�����ǂݍ��񂾏ꍇ��i++�B
	�L���Ȃł͂Ȃ�������ǂݍ��񂾏ꍇ��
		���������ǂݍ��񂾕����͗L���ł͂Ȃ������ł���̂ŏ���
		ch�Ɠ���������str�̂ǂ����ɂ��邩�ǂ����m�F{
			�������ꍇ�C�������ꏊ��str[?].count�ɂP�𑫂��Bcheck�ɂP�����B
			�Ȃ������ꍇ�C����str.s��ch�����Bcount++�B
		}
		ch���N���A�B
�p
�L���ł͂Ȃ������̒���Ɂo
	�L���ȕ�����ǂݍ��񂾏ꍇ��i++
	�L���ł͂Ȃ�������ǂݍ��񂾏ꍇ�������Ȃ��B
�p

*/
	while(1){
		ch[i]=fgetc(fin);
		if(ch[i]==EOF){
			break;
		}
		if( ((isalnum(ch[i]) || ch[i]=='_')&&inw==0) || (isalnum(ch[i]) && inw==1 && (ch[i]<'0' || '9'<ch[i])) ){
			inw=0;
			i++;
		}else if(inw==0){
			ch[i]='\0';
			for(j=0;j<count;j++){
				if(strcmp(str[j].s , ch) == 0){
					str[j].count++;
					check=1;
					break;
				}
			}
			if(check==0){
				strcpy(str[count].s,ch);
				str[count].count++;
				count++;
				check=0;
			}
			for(k=0;k<50;k++){
				ch[k]='\0';
			}
			check=0;
			i=0;
			inw=1;
		
		}
	}
	
	for(i=0;i<count;i++){
		fprintf(fout,"%s %d\n",str[i].s,str[i].count);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

/**************** ���s���� *****************
include 1
stdio 1
h 1
int 1
main 1
printf 3
Hello 1
How 1
are 1
you 1
n 3
Fine 1
thanks 1
And 1
You 1
So 1
so 1
return 1


*******************************************/
