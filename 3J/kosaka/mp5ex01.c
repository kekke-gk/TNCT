/**********************************************************
�}�U�[�{�[�h��8�r�b�g�X�C�b�`���Ȃ����Ă���P2�̊e�r�b�g��
���ڌ��Ă݂悤�B
�܂��C�֐�get8BitSW()������l�����Ă݂悤�B
**********************************************************/
#include <3048fone.h>
#include "h8_3048fone.h"

main()
{
	int i;
	initSCI1();
	initPushSW();
	while(1) {
		for(i=3;i>=0;i--){
			SCI1_printf("%d:%s ",i,(checkPushSW(i)==1?"ON ":"OFF"));
		}
		SCI1_printf("\n");
	}
}
