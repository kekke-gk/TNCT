/***  p05ex15.c  ***/
/***  s12083  2J18  �ܖ����S  ***/

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>//srand�̂���

int checkString(char s[]);
int countHit(char s1[],char s2[]);
int countBlow(char s1[],char s2[]);
void generateNumber(char theNumber[]);
void start();
int humTurn();
int comTurn();

typedef struct{
	int check;
	char s[5];
}string_t;

char cs[5]={0};//Computer String
string_t alst[5040]={0};//All String  10permutation4�łT�O�S�O�ʂ�

int main()
{
	int check;
	start();
	
	while(1){
		if(humTurn()){
			check=0;
			break;
		}
		
		if(comTurn()){
			check=1;
			break;
		}
	}

	switch(check){
		case 0:
			printf("\n���Ȃ��̏����ł��B\n");
			break;

		case 1:
			printf("\n���̏����ł��B\n");
			break;
	}
	return 0;
}


int humTurn()
{
	char s[5];
	int h,b,count=0;
	printf("\n���Ȃ��̔Ԃł��B\n");
	printf("���̗p�ӂ���������\�z����4���̐�������͂��Ă��������B\n");
	scanf("%s",s);
	
	while(checkString(s)){
		count++;
		if(count>3){
			printf("\n�ԈႦ�����ł��B\n");
			exit(1);
		}
		printf("�������Ȑ�������͂��Ȃ��ł��������B\n");
		printf("������x���͂��Ă��������B\n");
		scanf("%s",s);
	}
	
	h=countHit(cs,s);

	if(h == 4) return 1;

	b=countBlow(cs,s);
	
	printf("\n�͂���ł��B\n");
	printf("Hit: %d  Blow: %d\n",h,b);
	
	return 0;
}


int comTurn()
{
	char s[5]={0};
	int h,b,count=0,i=0,check=0,tmp;

	printf("\n���̔Ԃł��B\n");

//�\���̂�����̂��烉���_���ɑI��
	while(1){
		tmp=rand()%5040;
		if(!alst[tmp].check){
			strcpy(s,alst[tmp].s);
			break;
		}
	}

	printf("%s �ł͂Ȃ��ł��傤���H\n",s);
	printf("Hit Blow�̏��ɓ��͂��Ă��������B\n");
	printf("�R�͂��Ȃ��ł��������ˁB\n");
	scanf("%d %d",&h,&b);

	while(h>4 || b>4 || h<0 || b<0 || (h==3&&b==1)){
		count++;
		if(count>3){
			printf("\n�ԈႦ�����ł��B\n");
			exit(1);
		}
		printf("�������Ȑ�������͂��Ȃ��ł��������B\n");
		printf("������x���͂��Ă��������B\n");
		scanf("%d %d",&h,&b);
	}
	
	if(h == 4){
		return 1;
	}

	for(i=0;i<5040;i++){
		if(	countBlow(s,alst[i].s)!=b || countHit(s,alst[i].s)!=h){
			alst[i].check=1;
		}
	}

//check���O�ł���i�\���̂���j�p�^�[�������݂��Ȃ�������
//����̓v���C���[�̓��̓~�X�ł���̂ŏI������B
	for(i=0;i<5040;i++){
		if( !alst[i].check ){
			check=1;
			break;
		}
	}
	if(!check){
		printf("\n���Ȃ��C�R�����܂����ˁB\n");
		printf("���͂��Ȃ��̂��Ƃ������ł��B\n");
		exit(1);
	}

	return 0;
}


void start()
{
	int i,j,count=0,check=0;

	srand((unsigned) time(NULL));

	generateNumber(cs);

	for(i=0;i<5040;i++){
		alst[i].s[0]='0';
		alst[i].s[1]='0';
		alst[i].s[2]='0';
		alst[i].s[3]='0';
		alst[i].s[4]=0;
		alst[i].check=0;
	}

//�P�O�O�O�O��J��Ԃ��ĂO�P�Q�R�`�X�W�V�U�܂ł�
//�q�b�g�A���h�u���[�L������������ׂđ������
	for(i=0;i<10000;i++){
		alst[count].s[3]++;

//�J��オ��v�Z
		for(j=3;j>=1;j--){
			if(alst[count].s[j]>'9'){
				alst[count].s[j-1]++;
				alst[count].s[j]-=10;
			}
		}
		
//�������X�W�V�U��������I���
		check=0;
		for(j=0;j<4;j++){
			if(alst[count].s[j] != '9'-j){
				check=1;
				break;
			}
		}
		if(!check) break;

	
//������4������������
		if( !checkString(alst[count].s) ){
			strcpy(alst[count+1].s,alst[count].s);
			count++;
		}

			
	}

	printf("�ł́C�n�߂܂��傤�B\n");
	printf("�݂��ɈقȂ�4���̐�����p�ӂ��Ă��������B�Y��Ȃ��悤�ɂ��Ă��������ˁB\n");
	printf("�������ł�����space�������Ă��������B\n");
	while(getch() != ' ');
}


int checkString(char s[])
{
	int i,j,size=0;
	while(s[size]!=0){
		size++;
	}
	for(i=0;i<4;i++){
		if(s[i]<'0' || s[i]>'9'){
			return 1;
		}
	}
	if(s[0]==s[1] || s[0]==s[2] || s[0]==s[3] || s[1]==s[2] || s[1]==s[3] || s[2]==s[3]){
		return 1;
	}
	if(size != 4){
		return 1;
	}
	return 0;
}


int countHit(char s1[],char s2[])
{
	int i,count=0;
	for(i=0;i<4;i++){
		if(s1[i]==s2[i]) count++;
	}
	return count;
}


int countBlow(char s1[],char s2[])
{
	int i,j,count=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(s1[i]==s2[j]){
				count++;
			}
		}
	}

	return count-countHit(s1,s2);
}


void generateNumber(char theNumber[])
{
	int i=0;
	while(theNumber[i]!=0){
		theNumber[i]=0;
		i++;
	}
	while(1){
		for(i=0;i<4;i++){
			theNumber[i]=rand()%10+'0';
		}
		if(checkString(theNumber) == 0) break;
	}
}


/**************** ���s���� *****************
�ł́C�n�߂܂��傤�B
�݂��ɈقȂ�4���̐�����p�ӂ��Ă��������B�Y��Ȃ��悤�ɂ��Ă��������ˁB
�������ł�����space�������Ă��������B

���Ȃ��̔Ԃł��B
���̗p�ӂ���������\�z����4���̐�������͂��Ă��������B
1234

�͂���ł��B
Hit: 1  Blow: 1

���̔Ԃł��B
3784 �ł͂Ȃ��ł��傤���H
Hit Blow�̏��ɓ��͂��Ă��������B
�R�͂��Ȃ��ł��������ˁB
1 1

���Ȃ��̔Ԃł��B
���̗p�ӂ���������\�z����4���̐�������͂��Ă��������B
5678

�͂���ł��B
Hit: 0  Blow: 1

���̔Ԃł��B
7954 �ł͂Ȃ��ł��傤���H
Hit Blow�̏��ɓ��͂��Ă��������B
�R�͂��Ȃ��ł��������ˁB
1 0

���Ȃ��̔Ԃł��B
���̗p�ӂ���������\�z����4���̐�������͂��Ă��������B
1290

�͂���ł��B
Hit: 1  Blow: 2

���̔Ԃł��B
6034 �ł͂Ȃ��ł��傤���H
Hit Blow�̏��ɓ��͂��Ă��������B
�R�͂��Ȃ��ł��������ˁB
1293
2
�������Ȑ�������͂��Ȃ��ł��������B
������x���͂��Ă��������B


2 0

���Ȃ��̔Ԃł��B
���̗p�ӂ���������\�z����4���̐�������͂��Ă��������B
1293

�͂���ł��B
Hit: 1  Blow: 2

���̔Ԃł��B
6824 �ł͂Ȃ��ł��傤���H
Hit Blow�̏��ɓ��͂��Ă��������B
�R�͂��Ȃ��ł��������ˁB
1 1

���Ȃ��̔Ԃł��B
���̗p�ӂ���������\�z����4���̐�������͂��Ă��������B
1295

�͂���ł��B
Hit: 2  Blow: 2

���̔Ԃł��B
2134 �ł͂Ȃ��ł��傤���H
Hit Blow�̏��ɓ��͂��Ă��������B
�R�͂��Ȃ��ł��������ˁB
2 2

���Ȃ��̔Ԃł��B
���̗p�ӂ���������\�z����4���̐�������͂��Ă��������B
1925

�͂���ł��B
Hit: 1  Blow: 3

���̔Ԃł��B
1234 �ł͂Ȃ��ł��傤���H
Hit Blow�̏��ɓ��͂��Ă��������B
�R�͂��Ȃ��ł��������ˁB
4 0

���̏����ł��B

*******************************************/