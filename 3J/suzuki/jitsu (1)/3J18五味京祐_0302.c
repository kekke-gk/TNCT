#include<stdio.h>
#include<string.h>
#include<time.h>

void sort(FILE*,FILE*,int (*sortFunc)());
int bubble(int*,int,int);
int selection(int*,int,int);
int insertion(int*,int,int);
int shell(int*,int,int);
int hinsertion(int*,int,int,int);
FILE *fileOpen(char*,char*);
int getLine(FILE*);
void swap(int*,int*);

int main()
{
	char finame[64],foname[64]={0};
	int chal;
	FILE *fi,*fo;
	int (*func[])()={bubble,selection,insertion,shell};
	
	
	printf("入力ファイル名を入力してください．\n");
	scanf("%s",finame);
	
	fi=fileOpen(finame,"r");
	
	strncpy(foname,finame,strlen(finame)-strlen(strrchr(finame,'.')));
	strcat(foname,".out");
	
	fo=fileOpen(foname,"w");
	
	do{
		printf("実行するアルゴリズムを選択してください．\n|バブルソート---1   選択ソート---2   挿入ソート---3   シェルソート---4|");
		scanf("%d",&chal);
	}while(!(1<=chal && chal<=4));
	
	sort(fi,fo,func[chal-1]);
	
	fclose(fi);
	fclose(fo);
	
	
	return 0;
}

void sort(FILE *fi,FILE *fo,int (*sortFunc)())
{
	int *num,i=0,j,max,chud,count;
	clock_t first_time;
	
	do{
		printf("並べ替え方法を選択してください．\n|昇順---1   降順---2|");
		scanf("%d",&chud);
	}while(!(chud==1 || chud==2));

	num=(int *)calloc(getLine(fi),sizeof(int));
	
	while(fscanf(fi,"%d",&num[i])!=EOF) i++;
	max=i;
	
	first_time=clock();
	
	count=sortFunc(num,max,chud);
	
	printf("CPU使用時間：%f秒\n",(double)(clock() - first_time) / (double)CLOCKS_PER_SEC);
	printf("データの交換回数：%d回\n",count);
	
	for(i=0;i<max;i++){
		fprintf(fo,"%d\n",num[i]);
	}

}
int bubble(int num[],int max,int chud)
{
	int i,j,count=0;
	
	for(i=max-1;0<i;i--){
		for(j=0;j<i;j++){
			if((num[j]>num[j+1] && chud==1) || (num[j]<num[j+1] && chud==2)){
				swap(&num[j],&num[j+1]);
				count+=3;
			}
		}
	}
	return count;
}


int selection(int num[],int max,int chud)
{
	int i,j,focus,count=0;
	
	for(i=0;i<max;i++){
		focus=i;
		for(j=i+1;j<max;j++){
			if((num[focus]>num[j] && chud==1)  ||  (num[focus]<num[j] && chud==2)){
				focus=j;
			}
		}
		swap(&num[focus],&num[i]);
		count+=3;
	}
	return count;
}

int insertion(int num[],int max,int chud)
{
	int i,j,next,count=0;
	
	for(i=1;i<max;i++){
		next=num[i];
		count++;
		for(j=i;j>=1 && ((num[j-1] > next && chud==1) || (num[j-1] < next && chud==2));j--){
			num[j]=num[j-1];
			count++;
		}
		num[j]=next;
		count++;
	}
	return count;
}

int shell(int num[],int max,int chud)
{
	int i,j,count=0,h;
		
	for(h=1;h<max;h=h*3+1);
	h/=3;
	
	while(1){
		count+=hinsertion(num,max,chud,h);
		if(h==1) break;
		h/=3;
	}
	return count;
}

int hinsertion(int num[],int max,int chud,int h)
{
	int i,j,next,count=0;
	
	for(i=h;i<max;i+=h){
		next=num[i];
		count++;
		for(j=i;j>=1 && ((num[j-h] > next && chud==1) || (num[j-h] < next && chud==2));j-=h){
			num[j]=num[j-h];
			count++;
		}
		num[j]=next;
		count++;
	}
	return count;
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