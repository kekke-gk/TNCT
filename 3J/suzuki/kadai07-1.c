#include<stdio.h>
#include<stdlib.h>

void msort(int data[],int left,int right);
void merge(int data[],int left,int right,int m,int length);

void msort(int data[],int left,int right)
{
	int m,length=right-left+1;
	//printf("%d\n",length);
	if(length==1) return;
	m=(left+right)/2;
	msort(data,left,m);
	msort(data,m+1,right);

	merge(data,left,right,m,length);
}

void merge(int data[],int left,int right,int m,int length)
{
	int i,r=0,l=0,*buf;
	buf=(int *)malloc(length);
	
	for(i=left;i<=right;i++){
		if(left+r==m+1){
			buf[i-left]=data[m+1+l];
			l++;
		}else if(m+1+l==right+1){
			buf[i-left]=data[left+r];
			r++;
		}else if(data[left+r]<data[m+1+l]){
			buf[i-left]=data[left+r];
			r++;
		}else{
			buf[i-left]=data[m+1+l];
			l++;
		}
	}
	
	for(i=left;i<=right;i++){
		data[i]=buf[i-left];
		//printf("%d,",buf[i-left]);
	}
	//printf("\n");
}

int main()
{
	int i,a[]={2,1,5,3};
	msort(a,0,3);
	for(i=0;i<4;i++){
		printf("%d\n",a[i]);
	}
	return 0;

}
