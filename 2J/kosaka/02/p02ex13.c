/***  p02ex13.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>

int main()
{
	int x,sum=0,count;
	for(count=0;count<10;count++){
		scanf("%d",&x);
		sum+=x;
	}
	printf("%d\n",sum);

	return 0;
}


/**************** 実行結果 *****************
1 2 3 4 5 6 7 8 9 10
55

11 12 13 14 15 16 17 18 19 20
155

*******************************************/
