/***  p07ex07.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int i,size;
	char name[100];
	double ddata2[10];
	double ddata[10]={
		1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0
	};
	printf("ファイル名を入力してください。\n");
	gets(name);
	fp=fopen(name,"wb");
	if(fp==NULL){
		printf("can't open a file\n");
		exit(1);
	}
	
	size=sizeof(ddata)/sizeof(double);
	
	fwrite(ddata,sizeof(double),size,fp);
	
	fclose(fp);
	fp=fopen(name,"rb");
	
	fread(ddata2,sizeof(double),10,fp);
	for(i=0;i<size;i++){
		printf("%.1f ",ddata2[i]);
	}
	fclose(fp);

	return 0;
}


/**************** 実行結果 *****************
7.bin
1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0

*******************************************/
