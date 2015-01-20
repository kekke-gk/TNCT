#include<stdio.h>

void swap(int *a,int *b);

#define FILE_NAME "kadai-05-sample1.txt"

void quicksort(int d[],int a,int b)
{
	int pivot,a_=a,b_=b;

	if(a>=b){
		return;
	}
	
	pivot=d[a];

	while(1){
		while(d[a]<pivot) a++;
		while(d[b]>pivot) b--;
		if(a>=b) break;
		printf("d[%d](%d)  &  d[%d](%d)\n",a,d[a],b,d[b]);
		swap(&d[a],&d[b]);
		a++;
		b--;
	}
	
	quicksort(d,a_,a-1);
	
	quicksort(d,b+1,b_);
}

void swap(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int main(){
	FILE *fp;
	int i=0,a[1000001];
	
	fp=fopen(FILE_NAME,"r");
	if(fp==NULL){
		printf("cant open %s\n",FILE_NAME);
		exit(1);
	}
	while(fscanf(fp,"%d",&a[i])!=EOF) i++;
	
	quicksort(a,0,7);

	for(i=0;i<8;i++){
		printf("%d ",a[i]);
	}

	return 0;
}