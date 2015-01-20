#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int main()
{
	int num[MAX],i=0,j,next,max;
	FILE *fp;

	fp=fopen("kadai-01-3.txt","r");
	if(fp==NULL){
		printf("can't read file");
		exit(1);
	}
	while(fscanf(fp,"%d",&num[i])!=EOF) i++;
	max=i;
	
	for(i=1;i<MAX;i++){
		next=num[i];
		for(j=i;j>=1 && num[j-1] > next;j--){
			num[j]=num[j-1];
		}
		num[j]=next;
	}
	
	for(i=0;i<max;i++){
		printf("%d ",num[i]);
	}
	
	return 0;
}