#include<stdio.h>

#define MAX 10

int main()
{
	int num[MAX],i,j,tmp,min;
	for(i=0;i<MAX;i++){
		scanf("%d",&num[i]);
	}
	
	for(i=0;i<MAX;i++){
		min=i;
		for(j=i+1;j<MAX;j++){
			if(num[min]>num[j]){
				min=j;
			}
		}
		tmp=num[min];
		num[min]=num[i];
		num[i]=tmp;
	}
	
	for(i=0;i<MAX;i++){
		printf("%d ",num[i]);
	}
	
	return 0;
}