/***  p04ex12.c  ***/
/***  s12083  2J18  �ܖ����S  ***/

#include <stdio.h>

int main()
{
	char str[100];
	while(1){
		printf("�QJ�̏o�Ȕԍ�����͂��Ă������� >>");
		gets(str);
		if(str[0]=='z' && str[1]=='z' && str[2]=='z' && str[3]=='z') return 0;
		printf("%s => ",str);
		if(str[0]=='2' && str[1]=='J' && str[2]>='0' && str[2]<='4' && str[3]>='0' && str[3]<='9' && str[4]=='\0'){
			if(!(str[2]=='0' && str[3]=='0')) printf("correct\n");
			else printf("incorrect\n");
		}else printf("incorrect\n");

	}

	return 0;
}


/**************** ���s���� *****************
�QJ�̏o�Ȕԍ�����͂��Ă������� >>2J01
2J01 => correct
�QJ�̏o�Ȕԍ�����͂��Ă������� >>2J13
2J13 => correct
�QJ�̏o�Ȕԍ�����͂��Ă������� >>2J29
2J29 => correct
�QJ�̏o�Ȕԍ�����͂��Ă������� >>2J30
2J30 => correct
�QJ�̏o�Ȕԍ�����͂��Ă������� >>2J1
2J1 => incorrect
�QJ�̏o�Ȕԍ�����͂��Ă������� >>2J9
2J9 => incorrect
�QJ�̏o�Ȕԍ�����͂��Ă������� >>2J50
2J50 => incorrect
�QJ�̏o�Ȕԍ�����͂��Ă������� >>2J123
2J123 => incorrect
�QJ�̏o�Ȕԍ�����͂��Ă������� >>2J00
2J00 => incorrect
�QJ�̏o�Ȕԍ�����͂��Ă������� >>2J
2J => incorrect
�QJ�̏o�Ȕԍ�����͂��Ă������� >>zzzz
*******************************************/
