#include<stdio.h>
#include<time.h>

int main()
{
	int i;
	
	clock_t start,end;
	start=clock();
	
	for(i=0;i<100;i++);
	
	end=clock();
	printf("%.2f•b‚©‚©‚è‚Ü‚µ‚½\n",(double)(end-start));
}