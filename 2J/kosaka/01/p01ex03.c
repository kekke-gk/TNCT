/*** p01ex03.c ***/
/*** s12083 2J18 ŒÜ–¡‹ž—S ***/ 

#include <stdio.h> 

int main() 
{ 
	int factorial1=1;
	int factorial2=1*2;
	int factorial3=1*2*3;
	int factorial4=1*2*3*4;
	int factorial5=1*2*3*4*5;
	int factorial6=1*2*3*4*5*6;
	int factorial7=1*2*3*4*5*6*7;
	int factorial8=1*2*3*4*5*6*7*8;
	int factorial9=1*2*3*4*5*6*7*8*9;
	
	printf("factorial1 =%7d\n",factorial1);
	printf("factorial2 =%7d\n",factorial2);
	printf("factorial3 =%7d\n",factorial3);
	printf("factorial4 =%7d\n",factorial4);
	printf("factorial5 =%7d\n",factorial5);
	printf("factorial6 =%7d\n",factorial6);
	printf("factorial7 =%7d\n",factorial7);
	printf("factorial8 =%7d\n",factorial8);
	printf("factorial9 =%7d\n",factorial9);
	return 0; 
} 

/*
factorial1 =      1
factorial2 =      2
factorial3 =      6
factorial4 =     24
factorial5 =    120
factorial6 =    720
factorial7 =   5040
factorial8 =  40320
factorial9 = 362880
*/