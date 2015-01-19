/**********************************************************
���荞�݂�p�������v�@�N��������̌o�ߎ��ԁm�b�n��
SCI1�֏o�́CWINDOWS��HyperTerminal�ȂǂŎ�M�ł���B
�������C�ݒ��
38400baud, Async, 8bit , NoParity, stop1
**********************************************************/
#include <3048fone.h>
#include "h8_3048fone.h"

volatile unsigned int counter;/*0.1s�P�ʂŃJ�E���g*/

int status=0;/*0�Ȃ�X�^�[�g,1�Ȃ�X�g�b�v*/

main()
{
	unsigned int counter1;
	unsigned int t1,t2;
	short int tmp;
	initSCI1(); /*SCI-ch1�̏�����*/
	initTimer1Int(1000); /*ITUch1�̃C���^�[�o���^�C�}�������ݒ�*/
						  /*�P�ʃ�s�Ȃ̂ŁC���Ԋ��荞��1msec*/
	E_INT();        /*CPU���荞�݋���*/
	startTimer1();  /*ITUch1�^�C�}�X�^�[�g*/
	counter=0;
	while(1) {
		tmp=SCI1_chkgetChar();
		if(tmp=='A' || tmp=='a'){
			status=0;
		}else if(tmp=='B' || tmp=='b'){
			status=1;
		}else if(tmp=='C' || tmp=='c'){
			counter=0;
		}
		
		counter1=counter;
		t1=counter1/1000;
		t2=counter1%1000;
		SCI1_printf("%10u.%1u \r",t1,t2); 

	}
}


#pragma asm
	.SECTION    MYVEC, DATA, LOCATE=H'000070
	.ORG        H'000070  ;IMIA1
	.DATA.L     _TimerIntFunc
	.SECTION    P,CODE,ALIGN=2 ;�����Y��Ă͂����Ȃ�
#pragma endasm

#pragma interrupt (TimerIntFunc)
void TimerIntFunc() /*�C���^�[�o���^�C�}���荞�݃��[�`��*/
{
	if(status==0){
		counter++;
	}
	clearTimer1Flag();  /*ITUch1�^�C�}�t���O�̃N���A �Y��Ȃ�����*/
}
