/***  p09ex06.c  ***/
/***  s12083  2J18  �ܖ����S  ***/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}hairetu_t;

int main()
{
	hairetu_t *hairetu;
	int n,n2,i,j=2,keta=0,count=0;
	printf("n�܂ł̑f�������߂܂��B\n������͂��Ă��������B >>");
	scanf("%d",&n);
	n2=n;
	while(n2/=10) keta++;
	hairetu=malloc(n*sizeof(hairetu_t));
	for(i=1;i<=n;i++){
		hairetu[i].x=i;
		hairetu[i].y=0;
	}
	hairetu[1].y=1;
	//0���Ƒf���A�P���ƍ�����
	for(i=2;i<n;i++){
		while(j*i<=n){
			hairetu[j*i].y=1;
			j++;
		}
		j=2;
	}
	
	for(i=1;i<=n;i++){
		if(hairetu[i].y==0){
			printf("%*d",keta+1,hairetu[i].x);
			count++;
			if(count%10==0) printf("\n");
		}
	}
	

	return 0;
}


/**************** ���s���� *****************
n�܂ł̑f�������߂܂��B
������͂��Ă��������B >>100
  2  3  5  7 11 13 17 19 23 29
 31 37 41 43 47 53 59 61 67 71
 73 79 83 89 97

*******************************************/
