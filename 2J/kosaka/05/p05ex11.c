/***  p05ex11.c  ***/
/***  s12083  1320  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

int countHit(char s1[],char s2[])
{
	int i,count=0;
	for(i=0;i<4;i++){
		if(s1[i]==s2[i]) count++;
	}
	return count;
}

int main()
{
	char s0[]="1234";
	char s1[]="9837",s2[]="9817",s3[]="1837",s4[]="1834",s5[]="1234";
	
	printf("%s %s => %d\n",s0,s1,countHit(s0,s1) );
	printf("%s %s => %d\n",s0,s2,countHit(s0,s2) );
	printf("%s %s => %d\n",s0,s3,countHit(s0,s3) );
	printf("%s %s => %d\n",s0,s4,countHit(s0,s4) );
	printf("%s %s => %d\n",s0,s5,countHit(s0,s5) );

	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************
1234 9837 => 1
1234 9817 => 0
1234 1837 => 2
1234 1834 => 3
1234 1234 => 4

*******************************************/
