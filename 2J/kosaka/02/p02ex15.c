/***  p02ex15.c  ***/
/***  s12083  2J18  ŒÜ–¡‹—S  ***/

#include <stdio.h>

int main()
{
	int x=0,sum=0,count=-1;
	do{
		sum+=x;
		scanf("%d",&x);
		count++;
	}while(x>=0);
	
	printf("%d %.1f\n",sum,(double)sum/(double)count);

	return 0;
}

/*
int main()
{
	int x,sum=0,count=-1;
	do{
		scanf("%d",&x);
		sum+=x;
		count++;
	}while(x>=0);
	sum-=x;
	
	
	printf("%d %.1f\n",sum,(double)sum/(double)count);

	return 0;
}
*/

/**************** ÀsŒ‹‰Ê *****************
1 2 3 4 5 6 7 8 9 10 -1
55 5.5

1 2 3 4 5 -1
15 3.0

*******************************************/
