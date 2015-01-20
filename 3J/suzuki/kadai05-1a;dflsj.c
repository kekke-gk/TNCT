#include<stdio.h>

void swap(int *a,int *b);

//[a,b)‚Ì”ÍˆÍ‚ðƒ\[ƒg
void quicksort(int d[],int a,int b)
{
	int pivot,a_=a,b_=b,check=0,finala,finalb;

	if(b - a == 1){
		printf("—ˆ‚½‚æ");
		printf("a->%d b->%d\n",a,b);
		//swap(&d[a],&d[b]);
		return;
	}
	

	pivot=d[a];

	while(1){
		do{a++;}while(d[a]<=pivot);
		do{b--;}while(d[b]>=pivot);
		if(a>=b) break;
		printf("d[%d](%d)  &  d[%d](%d)\n",a,d[a],b,d[b]);
		swap(&d[a],&d[b]);
		finala=a;
		finalb=b;
	}
	swap(&d[b],&d[a_]);
	
	//quicksort(d,a_,finala);
	
	quicksort(d,b+1,b_);
}

void swap(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int main(){
	int i,a[8]={52,6,68,23,18,76,41,37};
	
	quicksort(a,0,8);

	for(i=0;i<8;i++){
		printf("%d ",a[i]);
	}

	return 0;
}

/*
1324059867
*/