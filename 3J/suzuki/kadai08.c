#include<stdio.h>

#define FILE_NAME ""
#define DATA_NUM 1000000

int main()
{
	FILE *fp;
	int data[DATA_NUM]={0,2,4,6,8,9,10},targetnum;

	open_file(fp);

	read_data(fp,data);

	targetnum=input_targetnum();

	linenum=search_linenum(data,targetnum);

	output_message(linenum);
}

void open_file(FILE *fp)
{
	if((fp=fopen(FILE_NAME,"r"))==NULL){
		printf("cannot open file %s",FILE_NAME);
		exit(1);
	}
}

void read_data(FILE *fp,int data[])
{
	int i=0;
	while((fscanf(fp,"%d",data[i]))!=EOF) i++;
}

int input_targetnum()
{
	int num;
	printf("input target number ->");
	scanf("%d",&num);
	return num;
}

int search_linenum(int data[],int targetnum)
{
	int focus=sizeof(data)/sizeof(data[0]);
	while(data[focus]!=targetnum){
		if(data[focus]<targetnum){
			focus+=focus/2;
		}else{
			focus-=focus/2;
		}
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
