#include<stdio.h>
#include<stdlib.h>

#define FILE_NAME "sorted.dat"
#define DATA_NUM 10000001

int read_data(FILE *fp,int data[]);
int input_targetnum();
int search_linenum(int data[],int targetnum,int size);
void output_message(int linenum);

int main()
{
	FILE *fp;
	static int data[DATA_NUM];
	int targetnum,linenum,size;

	if((fp=fopen(FILE_NAME,"r"))==NULL){
		printf("cannot open file %s",FILE_NAME);
		exit(0);
	}

	size=read_data(fp,data);

	targetnum=input_targetnum();

	linenum=search_linenum(data,targetnum,size);

	output_message(linenum);

	return 0;
}

int read_data(FILE *fp,int data[])
{
	int i=0;
	while((fscanf(fp,"%d",&data[i]))!=EOF) i++;
	return i;
}

int input_targetnum()
{
	int num;
	printf("input target number ->");
	scanf("%d",&num);
	return num;
}

int search_linenum(int data[],int targetnum,int size)
{
	int focus,right=0,left=size-1;
	focus=(left+right)/2;
	if(targetnum<data[0] || data[size-1]<targetnum) return -1;
	while(data[focus]!=targetnum){
		if(right>=left) return -1;
		if(data[focus]<targetnum){
			right=focus+1;
		}else{
			left=focus-1;
		}
		focus=(left+right)/2;
	}
	return focus;
}
	
void output_message(int linenum)
{
	if(linenum==-1){
		printf("not found target number\n");
	}else{
		printf("line number -> %d\n",linenum);
	}
}
