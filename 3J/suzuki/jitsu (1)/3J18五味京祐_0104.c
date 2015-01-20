#include<stdio.h>
#include<string.h>

#define MAX 100

void bubble(int chud,FILE *fi,FILE *fo);
void selection(int chud,FILE *fp,FILE *fo);
void insertion(int chud,FILE *fp,FILE *fo);
FILE *fileOpen(char*,char*);

int main()
{
	char finame[64],foname[64]={0};
	int chal,chud;
	FILE *fi,*fo;
	
	printf("入力ファイル名を入力してください．\n");
	scanf("%s",finame);
	
	fi=fileOpen(finame,"r");
	
	strncpy(foname,finame,strlen(finame)-strlen(strrchr(finame,'.')));
	strcat(foname,".out");
	
	fo=fileOpen(foname,"w");
	
	
	printf("実行するアルゴリズムを選択してください．\n|バブルソート---1   選択ソート---2   挿入ソート---3|");
	scanf("%d",&chal);
	printf("並べ替え方法を選択してください．\n|昇順---1   降順---2|");
	scanf("%d",&chud);
	
	switch(chal){
		case 1:
			bubble(chud,fi,fo);
			break;
			
		case 2:
			selection(chud,fi,fo);
			break;
			
		case 3:
			insertion(chud,fi,fo);
			break;
			
		default:
			printf("おかしな値を入力しないでください．\n");
	}
	
	fclose(fi);
	fclose(fo);
	
	return 0;
}

void bubble(int chud,FILE *fi,FILE *fo)
{
	int num[MAX],i=0,j,tmp,max;
	
	while(fscanf(fi,"%d",&num[i])!=EOF) i++;
	max=i;
	
	for(i=MAX-1;0<i;i--){
		for(j=0;j<i;j++){
			if((num[j]>num[j+1] && chud==1) || (num[j]<num[j+1] && chud==2)){
				tmp=num[j];
				num[j]=num[j+1];
				num[j+1]=tmp;
			}
		}
	}
	
	for(i=0;i<max;i++){
		fprintf(fo,"%d\n",num[i]);
	}
}


void selection(int chud,FILE *fi,FILE *fo)
{
	int num[MAX],i=0,j,tmp,focus,max;
	
	while(fscanf(fi,"%d",&num[i])!=EOF) i++;
	max=i;
	
	for(i=0;i<MAX;i++){
		focus=i;
		for(j=i+1;j<MAX;j++){
			if((num[focus]>num[j] && chud==1)  ||  (num[focus]<num[j] && chud==2)){
				focus=j;
			}
		}
		tmp=num[focus];
		num[focus]=num[i];
		num[i]=tmp;
	}
	
	for(i=0;i<max;i++){
		fprintf(fo,"%d\n",num[i]);
	}

}

void insertion(int chud,FILE *fi,FILE *fo)
{
	int num[MAX],i=0,j,next,max;

	while(fscanf(fi,"%d",&num[i])!=EOF) i++;
	max=i;
	
	for(i=1;i<MAX;i++){
		next=num[i];
		for(j=i;j>=1 && ((num[j-1] > next && chud==1) || (num[j-1] < next && chud==2));j--){
			num[j]=num[j-1];
		}
		num[j]=next;
	}
	
	for(i=0;i<max;i++){
		fprintf(fo,"%d\n",num[i]);
	}
}

FILE *fileOpen(char fname[],char open[])
{
	FILE *fp;
	fp=fopen(fname,open);
	if(fp==NULL){
		printf("can't open %s\n",fname);
		exit(1);
	}
	
	return fp;

}