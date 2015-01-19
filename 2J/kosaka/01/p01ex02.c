/*** p01ex02.c ***/
/*** s12083 2J18 ŒÜ–¡‹ž—S ***/ 

#include <stdio.h> 

int main() 
{ 
	int factorial1=1;
	int factorial2=1*2;
	int factorial3=1*2*3;
	printf("%5d %5d %5d\n",2*2,2*2*2,2*2*2*2);
	printf("%5d %5d %5d\n",3*3,3*3*3,3*3*3*3);
	printf("%5d %5d %5d\n",4*4,4*4*4,4*4*4*4);
	printf("%5d %5d %5d\n",5*5,5*5*5,5*5*5*5);
	return 0; 
} 

/*
    4     8    16
    9    27    81
   16    64   256
   25   125   625
*/