/***  p07ex02.c  ***/
/***  s12083  1320  五味京祐  ***/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	FILE *fp1;
	int point[100][5]={0};
	int i=0,j;
	double sum[5]={0};
	
	fp=fopen("marks.txt","r");
	if(fp==NULL){
		printf("can't open a file\n");
		exit(1);
	}
	
	fp1=fopen("marks1.txt","w");
	
	while( fscanf(fp,"%d,%d,%d,%d",&point[i][0],&point[i][1],&point[i][2],&point[i][3]) == 4){
		sum[0]+=point[i][0];
		sum[1]+=point[i][1];
		sum[2]+=point[i][2];
		sum[3]+=point[i][3];
		point[i][5]=point[i][0]+point[i][1]+point[i][2]+point[i][3];
		i++;
	}
	for(j=0;j<i;j++){
		sum[4]+=point[j][5];
	}
	
	fprintf(fp1,"英語平均点 %f\n",sum[0]/i);
	fprintf(fp1,"数学平均点 %f\n",sum[1]/i);
	fprintf(fp1,"理科平均点 %f\n",sum[2]/i);
	fprintf(fp1,"国語平均点 %f\n",sum[3]/i);
	fprintf(fp1,"学生ごとの総点\n");
	for(j=0;j<i;j++){
		fprintf(fp1,"	%d\n",point[j][5]);
	}
	fprintf(fp1,"総点の平均\n");
	fprintf(fp1,"	%f\n",sum[4]/i);
	return 0;
}


/**************** 実行結果 *****************
英語平均点 75.714286
数学平均点 77.523810
理科平均点 76.023810
国語平均点 74.476190
学生ごとの総点
	100
	68
	79
	64
	100
	81
	95
	78
	75
	87
	90
	68
	66
	71
	98
	100
	91
	89
	89
	21
	100
	36
	97
	86
	75
	88
	62
	62
	92
	57
	55
	58
	97
	69
	38
	31
	94
	64
	55
	97
	87
	355
総点の平均
	82.500000


*******************************************/
