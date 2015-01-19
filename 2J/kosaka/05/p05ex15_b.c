/***  p05ex15.c  ***/
/***  s12083  2J18  �ܖ����S  ***/

/*
�Z�Ɩ��̐����ŁA��ɐ��I�Ⓒ����(���Ă�ꂽ)���������Ƃ����ݒ�B
�v���C���[���Z�ŁA�R���s���[�^�������ł��B
�����̂悤�Ȑݒ�ɂ����̂́A�v���O���~���O�𒻂点�邽�߂ł���B
��܂����v��������킯�ł͂���܂���B
*/

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
			printf("\n���ɂ������̏�������B\n");
			printf("�������A���ɂ�����񂾂ˁB���ɂ�������D������B\n");
			break;

		case 1:
			printf("\n���̏������ˁB\n");
			printf("����..���ɂ�����񑁘R�Ȃ񂾂���B\n");
			printf("�ł��A���͂��ɂ�����񂪑�D������B\n");
			break;
	}
	return 0;
}


int humTurn()
{
	char s[5];
	int h,b,count=0;
	printf("\n���ɂ�����񂪐ӂ߂�Ԃ���B\n");
	printf("���̗p�ӂ���������\�z����4���̐��������Ă�\n");
	scanf("%s",s);
	
	while(checkString(s)){
		count++;
		if(count>3){
			printf("\n�������{������B�������ɂ������̂��ƂȂ�Ēm��Ȃ�����I�I�I\n");
			exit(1);
		}
		printf("�����A���ɂ������A�������Ȑ�������͂��Ȃ��ł�B\n");
		printf("���������͂��āB\n");
		scanf("%s",s);
	}
	
	h=countHit(cs,s);

	if(h == 4) return 1;

	b=countBlow(cs,s);
	
	printf("\n���ɂ������̃o�[�J�A�n�Y������\n");
	printf("Hit: %d  Blow: %d  ����B\n",h,b);
	
	return 0;
}


int comTurn()
{
	char s[5]={0};
	int h,b,count=0,i=0,check=0,tmp;

	printf("\n��������d����Ԃ��ˁB\n");

//�\���̂�����̂��烉���_���ɑI��
	while(1){
		tmp=rand()%5040;
		if(!alst[tmp].check){
			strcpy(s,alst[tmp].s);
			break;
		}
	}

	printf("%s ����Ȃ����ȁ`\n",s);
	printf("Hit Blow�̏��ɓ��͂��ĂˁB\n");
	printf("�C���`�L�̓_������I\n");
	scanf("%d %d",&h,&b);

	while(h>4 || b>4 || h<0 || b<0 || (h==3&&b==1)){
		count++;
		if(count>3){
			printf("\n�������{������B�������ɂ������̂��ƂȂ�Ēm��Ȃ�����I�I�I\n");
			exit(1);
		}
		printf("�����A���ɂ������A�������Ȑ�������͂��Ȃ��ł�B\n");
		printf("���������͂��āB\n");
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
//����̓v���C���[�̓��̓~�X�ł���̂ŁC�{��
	for(i=0;i<5040;i++){
		if( !alst[i].check ){
			check=1;
			break;
		}
	}
	if(!check){
		printf("\n���ɂ������R�����ł���I�ǂ����Ă���Ȃ��Ƃ���́H\n");
		printf("���ɂ������Ȃ�đ�������I�I�I\n");
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

	printf("���ɂ������A�n�߂��B\n");
	printf("�݂��ɈقȂ�4���̐�����p�ӂ��ĂˁB�����Ɗo���Ƃ��Ă�ˁB\n");
	printf("�������ł�����space�������ĂˁB\n");
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
/*���t�̃���
hit����blow���̑g�ݍ��킹�͎���14�ʂ肪����B

(hit,blow)
(0,0)	(1,0)	(2,0)	(3,0)	(4,0)
(0,1)	(1,1)	(2,1)
(0,2)	(1,2)	(2,2)
(0,3)	(1,3)
(0,4)

�����ɂ����ɂ���Ă������ɏꍇ����������B

1.(4,0)
2.(0,4)(1,3)(2,2)(3,0)
3.(0,3)(1,2)(2,1)(0,2)(1,1)(2,0)
4.(0,1)(1,0)
5.(0,0)

�����āC���ꂼ��ɂ��Č��t��ݒ肵�Ă����B

����ȏꍇ�ɂ���
�Z�̐ӂ߂̏ꍇ
�E�Q���Ȃ�ǂ���������C�u�����C�����Ă�v�ƌ��킹��B
�E�S�C�T�̒���ɂQ�ɂȂ����ꍇ�C�u�}�Ɍ����������v�ƌ��킹��B
�E�Q�̒���ɂT�ɂȂ����ꍇ�C�u���ɂ�������߂Ȃ��Łv�ƌ��킹��B
/**************** ���s���� *****************


*******************************************/
