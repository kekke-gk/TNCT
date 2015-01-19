/***  p05ex13.c  ***/
/***  s12083  1320  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>
#include <time.h>

int checkString(char s[]);
void generateNumber(char theNumber[]);

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
//			printf("%c", theNumber[i]);
		}
		
		if(checkString(theNumber) == 0) break;
	}
}

int main()
{
	char aNumber[10]="abcdefg"; /*ŒŸØ‚Ì‚½‚ß‚ÉˆÓ–¡‚Ì‚È‚¢•¶Žš—ñ‚ð‰Šú’l‚Æ‚·‚é*/
	int count;
	srand((unsigned) time(NULL));/*—”—ñ¶¬‚Ì‰Šú‰»*/
	for (count=0; count<10; count++) {
		generateNumber(aNumber);
		puts(aNumber);
	}

	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************
3649
4913
2941
1679
2034
7890
6295
8659
4081
7465

*******************************************/
