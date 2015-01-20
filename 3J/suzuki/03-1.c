#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int shell(int*,int,int);
int insertion(int*,int,int,int);

int main()
{
	FILE *fi;
	char fname[]="kadai-01-3.txt";
	int nums[MAX],i=0,j;
	
	fi=fopen(fname,"r");
	if(fi==NULL){
		printf("cant open %s\n",fname);
		exit(1);
	}
	
	while(fscanf(fi,"%d",&nums[i])!=EOF) i++;
	
	shell(nums,i,1);
	
	for(j=0;j<i;j++){
		printf("%d\n",nums[j]);
	}
	
	return 0;
}

int shell(int num[],int max,int chud)
{
	int i,j,count=0,h;
		
	for(h=1;h<max;h=h*3+1);
	h/=3;
	
	while(1){
		count+=insertion(num,max,chud,h);
		if(h==1) break;
		h/=3;
	}
	return count;
}

int insertion(int num[],int max,int chud,int h)
{
	int i,j,next,count=0;
	
	for(i=h;i<max;i+=h){
		next=num[i];
		count++;
		for(j=i;j>=h && ((num[j-h] > next && chud==1) || (num[j-h] < next && chud==2));j-=h){
			num[j]=num[j-h];
			count++;
		}
		num[j]=next;
		count++;
	}
	return count;
}

