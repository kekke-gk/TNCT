/***  p04ex10.c  ***/
/***  s12083  2J18  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

int main()
{
	char str1[100],str2[100];
	int i=0,j;
	printf("str1= ");
	gets(str1);
	printf("str2= ");
	gets(str2);
	while(str1[i]!='\0'){
		i++;
	}
	printf("%s %s =>",str1,str2);
	for(j=0;j<i;j++){
		if(str1[j]!=str2[j]){
			printf("not equal\n");
			return 0;
		}
	}
	printf("equal\n");

	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************
str1= robot
str2= robit
robot robit =>not equal

str1= robot
str2= robot
robot robot =>equal

str1= same
str2= time
same time =>not equal

str1= get
str2= got
get got =>not equal

str1= big
str2= bag
big bag =>not equal
*******************************************/
