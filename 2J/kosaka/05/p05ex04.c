/***  p05ex04.c  ***/
/***  s12083  2J18  ŒÜ–¡‹—S  ***/

#include <stdio.h>

double average(int array[], int size)
{
	int i;
	double total=0;
	for(i=0;i<size;i++){
		total+=array[i];
	}
	return total/size;
}

int main()
{
	int x[100]={0},count=0;
	double r;
	do{
		scanf("%d",&x[count]);
		count++;
	}while(x[count-1]>=0);
	r=average(x,count-1);
	printf("%f\n",r);
	return 0;
}


/**************** ÀsŒ‹‰Ê *****************
1 2 3 4 5 6 7 8 9 10 -1
5.500000

1 2 3 4 5 6 -1
3.500000
*******************************************/
