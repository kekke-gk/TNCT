/***  p04ex11.c  ***/
/***  s12083  2J18  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

int main()
{
	char str1[100],str2[100];
	int i=0,j=0,k,l;
	printf("str1= ");
	gets(str1);
	printf("str2= ");
	gets(str2);

	while(str1[i]!='\0'){
		i++;
	}

	while(str2[j]!='\0'){
		j++;
	}
	if(i<j) k=j;
	else k=i;
	printf("%s %s =>",str1,str2);
	for(l=0;l<k;l++){
		if(str1[l]!=str2[l]){
			printf("not equal\n");
			return 0;
		}
	}
	printf("equal\n");


	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************
str1= robot
str2= robotics
robot robotics =>not equal

str1= robotics
str2= robot
robotics robot =>not equal

str1= robot
str2= robot
robot robot =>equal

str1= time
str2= game
time game =>not equal

str1= seem
str2= seen
seem seen =>not equal
*******************************************/
