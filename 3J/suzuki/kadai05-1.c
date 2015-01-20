#include<stdio.h>

#define SWAP(type,a,b){type tmp=a;a=b;b=tmp;}

//[a,b)‚Ì”ÍˆÍ‚ğƒ\[ƒg
void quicksort(int d[],int a,int b)
{
	int pivot,a_=a,check=0;



	if(b-a == 1) return;

	pivot=d[a];

	while(1){
		while(d[a]<pivot) a++;

		while(d[b]>pivot) b--;
		if(a>=b) break;
		SWAP(int,d[a],d[b]);
	}
	SWAP(int,d[b-1],d[a_]);
	printf("->%d\n",b-1);
	
	//quicksort(d,0,b);
	//quicksort(d,b+1,10);
}

int main(){
	int i,a[10]={5,4,7,6,0,8,9,1,4,2};
	
	quicksort(a,0,9);

	for(i=0;i<10;i++){
		printf("%d",a[i]);
	}

	return 0;
}

/*
10 - 0 = 10
3,3
0123869546*/