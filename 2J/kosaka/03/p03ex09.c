/***  p03ex09.c  ***/
/***  s12083  2J18  �ܖ����S  ***/

#include <stdio.h>

int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(j<=2 || j>=n-1 || i<=2 || i>=n-1){
				printf("*");
			}else printf("-");
		}
		printf("\n");
	}


	return 0;
}


/**************** ���s���� *****************
1
*

2
**
**

3
***
***
***

5
*****
*****
**-**
*****
*****

10
**********
**********
**------**
**------**
**------**
**------**
**------**
**------**
**********
**********

20
********************
********************
**----------------**
**----------------**
**----------------**
**----------------**
**----------------**
**----------------**
**----------------**
**----------------**
**----------------**
**----------------**
**----------------**
**----------------**
**----------------**
**----------------**
**----------------**
**----------------**
********************
********************
*******************************************/