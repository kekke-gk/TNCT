/***  p03ex05.c  ***/
/***  s12083  2J18  �ܖ����S  ***/

#include <stdio.h>

int main()
{
	int x=0,sum=0,count=0;
	do{
		sum+=x;
		scanf("%d",&x);
		count++;
		if(x<0 && count==0){
			printf("���v�l�ƕ��ϒl�͋��߂��Ȃ�\n");
			return 0;
		}
	}while(x>0);
	printf("%d %.1f\n",sum,(double)sum/(double)count);

	return 0;
}


/**************** ���s���� *****************
1 2 3 4 5 6 7 8 9 10 -1
55 5.5

1 2 3 4 5 -1
15 3.0

-1
���v�l�ƕ��ϒl�͋��߂��Ȃ�
*******************************************/
