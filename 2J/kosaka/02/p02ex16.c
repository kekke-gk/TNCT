/***  p02ex16.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>

int main()
{
	int x=0,sum=0,count;
	while(x>=0){
		scanf("%d",&x);
		for(count=1;;count++){
			if(!(x/=10)) break;
		}
		printf("%d\n",count);
	}

	return 0;
}

/**************** 実行結果 *****************
3
1

54
2

634
3

1234
4

98740
5

234563
6

6759432
7

56478765
8
*******************************************/
