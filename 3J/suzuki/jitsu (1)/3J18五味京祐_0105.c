#include<stdio.h>
#include<string.h>

void sort(FILE*,FILE*,void (*sortFunc)());
void bubble(int*,int,int);
void selection(int*,int,int);
void insertion(int*,int,int);
FILE *fileOpen(char*,char*);
int getLine(FILE*);
void swap(int*,int*);

int main()
{
	char finame[64],foname[64]={0};
	int chal;
	FILE *fi,*fo;
	void (*func[])()={bubble,selection,insertion};
	
	printf("入力ファイル名を入力してください．\n");
	scanf("%s",finame);
	
	fi=fileOpen(finame,"r");
	
	strncpy(foname,finame,strlen(finame)-strlen(strrchr(finame,'.')));
	strcat(foname,".out");
	
	fo=fileOpen(foname,"w");
	
	do{
		printf("実行するアルゴリズムを選択してください．\n|バブルソート---1   選択ソート---2   挿入ソート---3|");
		scanf("%d",&chal);
	}while(!(1<=chal && chal<=3));
	
	sort(fi,fo,func[chal-1]);
	
	fclose(fi);
	fclose(fo);
	
	return 0;
}

void sort(FILE *fi,FILE *fo,void (*sortFunc)())
{
	int *num,i=0,j,max,chud;
	
	do{
		printf("並べ替え方法を選択してください．\n|昇順---1   降順---2|");
		scanf("%d",&chud);
	}while(!(chud==1 || chud==2));

	num=(int *)calloc(getLine(fi),sizeof(int));
	
	while(fscanf(fi,"%d",&num[i])!=EOF) i++;
	max=i;
	
	sortFunc(num,max,chud);
	
	for(i=0;i<max;i++){
		fprintf(fo,"%d\n",num[i]);
	}

}
void bubble(int num[],int max,int chud)
{
	int i,j;
	
	for(i=max-1;0<i;i--){
		for(j=0;j<i;j++){
			if((num[j]>num[j+1] && chud==1) || (num[j]<num[j+1] && chud==2)){
				swap(&num[j],&num[j+1]);
			}
		}
	}
}


void selection(int num[],int max,int chud)
{
	int i,j,focus;
	
	for(i=0;i<max;i++){
		focus=i;
		for(j=i+1;j<max;j++){
			if((num[focus]>num[j] && chud==1)  ||  (num[focus]<num[j] && chud==2)){
				focus=j;
			}
		}
		swap(&num[focus],&num[i]);
	}
}

void insertion(int num[],int max,int chud)
{
	int i,j,next;
	
	for(i=1;i<max;i++){
		next=num[i];
		for(j=i;j>=1 && ((num[j-1] > next && chud==1) || (num[j-1] < next && chud==2));j--){
			num[j]=num[j-1];
		}
		num[j]=next;
	}
}

FILE *fileOpen(char fname[],char open[])
{
	FILE *fp;
	if((fp=fopen(fname,open))==NULL){
		printf("can't open %s\n",fname);
		exit(1);
	}
	
	return fp;
}

int getLine(FILE *fp)
{
	int i=0,buf;
	while(fscanf(fp,"%d",&buf)!=EOF) i++;
	rewind(fp);
	return i;
}

void swap(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}