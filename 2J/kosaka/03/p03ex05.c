/***  p03ex05.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>

int main()
{
	int x=0,sum=0,count=0;
	do{
		sum+=x;
		scanf("%d",&x);
		count++;
		if(x<0 && count==0){
			printf("合計値と平均値は求められない\n");
			return 0;
		}
	}while(x>0);
	printf("%d %.1f\n",sum,(double)sum/(double)count);

	return 0;
}


/**************** 実行結果 *****************
1 2 3 4 5 6 7 8 9 10 -1
55 5.5

1 2 3 4 5 -1
15 3.0

-1
合計値と平均値は求められない
*******************************************/
