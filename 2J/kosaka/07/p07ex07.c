/***  p07ex07.c  ***/
/***  s12083  1320  �ܖ����S  ***/

#include <stdio.h>

int main()
{
	double ddata[10]={
		1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0
	};
	double data[10]={0};
	FILE *fp;
	int dataSize,i;
	dataSize=sizeof(ddata)/sizeof(double);
	
	
	//�o�C�i���t�@�C���Ƀf�[�^���i�[���Ă������B
	
	fp=fopen("binary.bin","rb");
	if(fp==NULL){
		printf("can't open file\n");
		exit(1);
	}
	fread(data,sizeof(double),100,fp);
	
	for(i=0;i<dataSize;i++){
		printf("%.1f\n",data[i]);
	}
	return 0;
}


/**************** ���s���� *****************
1.0
2.0
3.0
4.0
5.0
6.0
7.0
8.0
9.0
10.0

*******************************************/
