#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void swap(int*,int*);
int lsort(int*,int,int);
int rsort(int*,int,int);

int main()
{
	int i,nums[MAX],right,left,cnt=0;
	FILE *fp;
	
	if((fp=fopen("kadai-02-1.txt","r"))==NULL){
		printf("can't open a file\n");
		exit(1);
	}
	
	while(fscanf(fp,"%d",&nums[cnt]) != EOF) cnt++;
	
	left=0;right=cnt-1;
	
	while(left<right){
		right=rsort(nums,left,right);
		
		if(left>=right-1) break;
		
		left=lsort(nums,left,right);
	}
	
	for(i=0;i<cnt;i++){
		printf("%d\n",nums[i]);
	}
	
	return 0;
}

int lsort(int nums[],int left,int right){
	int i,j,focus=left;
	
	for(i=right;i>left;i--){
		if(nums[i-1]>=nums[i]){
			focus=i;
			swap(&nums[i-1],&nums[i]);
		}
	}
	
	return focus;
}

int rsort(int nums[],int left,int right){
	int i,j,focus=right;
	
	for(i=left;i<right;i++){
		if(nums[i]>=nums[i+1]){
			focus=i;
			swap(&nums[i],&nums[i+1]);
		}
	}
	
	return focus;
}

void swap(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}