#include<stdio.h>

#define MAX 10

int main()
{
	int num[MAX],i,j,tmp;
	for(i=0;i<MAX;i++){
		scanf("%d",&num[i]);
	}
	
	for(i=MAX-1;0<i;i--){
		for(j=0;j<i;j++){
			if(num[j]>num[j+1]){
				tmp=num[j];
				num[j]=num[j+1];
				num[j+1]=tmp;
			}
		}
	}
	
	for(i=0;i<MAX;i++){
		printf("%d ",num[i]);
	}
	
	return 0;
}