#include<stdio.h>
#include<stdlib.h>

#define FILE_NAME "kadai-05-sample1.txt"
#define DATANUM 1000000

void msort(int data[],int left,int right);
void merge(int data[],int left,int right,int m,int length);

void msort(int data[],int left,int right)
{
	int m,length=right-left+1;
	if(length==1) return;
	m=(left+right)/2;
	msort(data,left,m);
	msort(data,m+1,right);

	merge(data,left,right,m,length);
}

void merge(int data[],int left,int right,int m,int length)
{
	int i,j,r=left,l=right,buf[DATANUM],tmp;
	
	for(i=m+1,j=right;i<j;i++,j--){
		tmp=data[i];
		data[i]=data[j];
		data[j]=tmp;
	}

	for(i=left;i<=right;i++){
		if(data[r]<=data[l]){
			buf[i]=data[r];
			r++;
		}else{
			buf[i]=data[l];
			l--;
		}
	}
	
	for(i=left;i<=right;i++){
		data[i]=buf[i];
	}
}

int main()
{
	FILE *fp;
	int i,data[DATANUM],num=0;
	if((fp=fopen(FILE_NAME,"r"))==NULL){
		printf("cannot open file\n");
		exit(1);
	}
	while(fscanf(fp,"%d",&data[num])!=EOF) num++;
	msort(data,0,num-1);
	for(i=0;i<num;i++){
		printf("%d\n",data[i]);
	}
	return 0;

}
