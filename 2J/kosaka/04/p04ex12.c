/***  p04ex12.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>

int main()
{
	char str[100];
	while(1){
		printf("２Jの出席番号を入力してください >>");
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


/**************** 実行結果 *****************
２Jの出席番号を入力してください >>2J01
2J01 => correct
２Jの出席番号を入力してください >>2J13
2J13 => correct
２Jの出席番号を入力してください >>2J29
2J29 => correct
２Jの出席番号を入力してください >>2J30
2J30 => correct
２Jの出席番号を入力してください >>2J1
2J1 => incorrect
２Jの出席番号を入力してください >>2J9
2J9 => incorrect
２Jの出席番号を入力してください >>2J50
2J50 => incorrect
２Jの出席番号を入力してください >>2J123
2J123 => incorrect
２Jの出席番号を入力してください >>2J00
2J00 => incorrect
２Jの出席番号を入力してください >>2J
2J => incorrect
２Jの出席番号を入力してください >>zzzz
*******************************************/
