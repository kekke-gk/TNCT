/***  p05ex02.c  ***/
/***  s12083  2J18  ŒÜ–¡‹—S  ***/

#include <stdio.h>

double average4(double,double,double,double);

int main()
{
	double ans;
	ans=average4(10.0, 20.0, 30.0, 40.0);
	printf("%f\n",ans);
	return 0;
}

double average4(double x1,double x2,double x3,double x4)
{
	double ave;
	ave=(x1+x2+x3+x4)/4.0;
	return ave;
}
/**************** ÀsŒ‹‰Ê *****************
25.000000

*******************************************/
