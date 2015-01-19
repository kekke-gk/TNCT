/***  p04ex12.c  ***/
/***  s12083  2J18  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

int main()
{
	char str[100];
	while(1){
		printf("‚QJ‚ÌoÈ”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >>");
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


/**************** ŽÀsŒ‹‰Ê *****************
‚QJ‚ÌoÈ”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >>2J01
2J01 => correct
‚QJ‚ÌoÈ”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >>2J13
2J13 => correct
‚QJ‚ÌoÈ”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >>2J29
2J29 => correct
‚QJ‚ÌoÈ”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >>2J30
2J30 => correct
‚QJ‚ÌoÈ”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >>2J1
2J1 => incorrect
‚QJ‚ÌoÈ”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >>2J9
2J9 => incorrect
‚QJ‚ÌoÈ”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >>2J50
2J50 => incorrect
‚QJ‚ÌoÈ”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >>2J123
2J123 => incorrect
‚QJ‚ÌoÈ”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >>2J00
2J00 => incorrect
‚QJ‚ÌoÈ”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >>2J
2J => incorrect
‚QJ‚ÌoÈ”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >>zzzz
*******************************************/
