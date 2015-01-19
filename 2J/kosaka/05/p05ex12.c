/***  p05ex12.c  ***/
/***  s12083  1320  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

int countBlow(char s1[],char s2[])
{
	int i,j,count=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(s1[i]==s2[j] && i!=j){
				count++;
			}
		}
	}

	return count;
}

int main()
{
	char s0[]="1234";
	char s1[]="9387", s2[]="9807", s3[]="0391", s4[]="4213", s5[]="4312";
	
	printf("%s %s => %d\n",s0,s1,countBlow(s0,s1) );
	printf("%s %s => %d\n",s0,s2,countBlow(s0,s2) );
	printf("%s %s => %d\n",s0,s3,countBlow(s0,s3) );
	printf("%s %s => %d\n",s0,s4,countBlow(s0,s4) );
	printf("%s %s => %d\n",s0,s5,countBlow(s0,s5) );

	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************
1234 9387 => 1
1234 9807 => 0
1234 0391 => 2
1234 4213 => 3
1234 4312 => 4

*******************************************/
