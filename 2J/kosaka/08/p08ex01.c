/***  p08ex01.c  ***/
/***  s12083  2J18  �ܖ����S  ***/

#include <stdio.h>
#include <math.h>

#define PAI 3.14159265358979

typedef struct{
	int x;
	int y;
}point_t;

point_t rotatePoint(point_t point,double theta)
{
	point_t npoint;
	npoint.x=point.x*cos(theta)-point.y*sin(theta);
	npoint.y=point.x*sin(theta)+point.y*cos(theta);
	
	//x cos�� - y sin�� , x sin�� + y cos�� 
	return npoint;
}

int main()
{
	point_t point={100,100};
	double rad0=PAI/4,rad1=-1*PAI/4;
	
	printf(" ��/4��] : (x,y)=(%d,%d)\n",rotatePoint(point,rad0));
	printf("-��/4��] : (x,y)=(%d,%d)\n",rotatePoint(point,rad1));
	
	return 0;
}


/**************** ���s���� *****************
 ��/4��] : (x,y)=(0,141)
-��/4��] : (x,y)=(141,0)
*******************************************/
