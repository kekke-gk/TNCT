/***  p04ex15.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>

int main()
{
	int sq[50],i;
	for(i=0;i<50;i++){
		sq[i]=(i+1)*(i+1);
	}

	for(i=0;i<50;i+=2){
		printf("%d ",sq[i]);
	}
	return 0;
}


/**************** 実行結果 *****************
1 9 25 49 81 121 169 225 289 361 441 529 625 729 841 961 1089 1225 1369 1521 168
1 1849 2025 2209 2401

*******************************************/
