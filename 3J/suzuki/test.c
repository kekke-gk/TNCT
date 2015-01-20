#include<stdio.h>
#include<string.h>

int main()
{
	char finame[]="test.txt",foname[100]={0};

	
	printf("%d\n",strlen(finame)-strlen(strrchr(finame,'.')));
	strncpy(foname,finame,strlen(finame)-strlen(strrchr(finame,'.')));
	strcat(foname,".dat");
	
	printf("%s\n",foname);
	
	return 0;
}