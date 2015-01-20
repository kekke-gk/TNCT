#include<stdio.h>
#include<stdlib.h>

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
	FILE *fp,*fo;
	int i=0,*a,size=0,tmp;
	
	fp=fopen(FILE_NAME,"r");
	if(fp==NULL){
		printf("cant open %s\n",FILE_NAME);
		exit(1);
	}
	fo=fopen("quick.txt","w");
	if(fo==NULL){
		printf("cant create file\n");
		exit(1);
	}
	
	a=(int *)malloc(10000000);
	while(fscanf(fp,"%d",&a[i])!=EOF) i++;
	size=i;
	quicksort(a,0,size-1);

	for(i=0;i<size;i++){
		fprintf(fo,"%d\n",a[i]);
	}

	return 0;
}
