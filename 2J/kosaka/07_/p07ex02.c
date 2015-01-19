/***  p07ex02.c  ***/
/***  s12083  2J18  �ܖ����S  ***/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fin,*fout;
	int point[50][5],total[5]={0},i=0,j;
	fin=fopen("marks.txt","r");
	if(fin==NULL){
		printf("can't open a file\n");
		exit(1);
	}
	fout=fopen("marks1.txt","w");
	if(fout==NULL){
		printf("can't open a file\n");
		exit(1);
	}
	
	while(fscanf(fin,"%d,%d,%d,%d",&point[i][0],&point[i][1],&point[i][2],&point[i][3]) == 4){
		point[i][4]=point[i][0]+point[i][1]+point[i][2]+point[i][3];
		for(j=0;j<5;j++){
			total[j]+=point[i][j];
		}
		i++;
	}
	
	fprintf(fout,"�p�ꕽ�ϓ_ %f\n",(double)total[0]/i);
	fprintf(fout,"���w���ϓ_ %f\n",(double)total[1]/i);
	fprintf(fout,"���ȕ��ϓ_ %f\n",(double)total[2]/i);
	fprintf(fout,"���ꕽ�ϓ_ %f\n",(double)total[3]/i);
	fprintf(fout,"�w�����Ƃ̑��_\n");
	for(j=0;j<i;j++){
		fprintf(fout,"	%d\n",point[j][4]);
	}
	fprintf(fout,"���_�̕��� %f\n",(double)total[4]/i);
	fclose(fin);
	fclose(fout);

	return 0;
}


/**************** ���s���� *****************
�p�ꕽ�ϓ_ 75.714286
���w���ϓ_ 77.523810
���ȕ��ϓ_ 76.023810
���ꕽ�ϓ_ 74.476190
�w�����Ƃ̑��_
	251
	400
	348
	331
	252
	400
	356
	350
	301
	322
	303
	379
	278
	272
	293
	374
	400
	377
	317
	383
	99
	400
	152
	328
	331
	281
	353
	262
	262
	336
	254
	256
	283
	367
	268
	146
	125
	313
	298
	204
	397
	355
���_�̕��� 303.738095


*******************************************/
