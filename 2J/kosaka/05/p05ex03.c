/***  p05ex03.c  ***/
/***  s12083  2J18  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>
#include <math.h>

double heronformula(double,double,double);

int main()
{
	double a,b,c,area;
	a=3.0;
	b=4.0;
	c=5.0;
	area=heronformula(a,b,c);
	printf("a,b,c,area=%lf, %lf, %lf, %lf\n",a,b,c,area);
	a=3.0;
	b=4.0;
	c=8.0;
	area=heronformula(a,b,c);
	printf("a,b,c,area=%lf, %lf, %lf, %lf\n",a,b,c,area);
	return 0;

}

double heronformula(double a,double b,double c)
{
	double s,p;
	if(a+b<c || a+c<b || b+c<a) return 0;
	s=(a+b+c)/2;
	p=(s-a)*(s-b)*(s-c)*s;
	return sqrt(p);
}
/**************** ŽÀsŒ‹‰Ê *****************
a,b,c,area=3.000000, 4.000000, 5.000000, 6.000000
a,b,c,area=3.000000, 4.000000, 8.000000, 0.000000

*******************************************/
