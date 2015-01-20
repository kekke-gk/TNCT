#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char *test;
}testt;

testt testA;

int main()
{
	int i;
	testA.test=(char *)malloc(sizeof(char) * 20);
	
	for(i=0;i<23;i++){
		testA.test[i]='a';
	}
	testA.test[i]='\0';
	
	printf("%s\n",testA.test);
	
	return 0;
}