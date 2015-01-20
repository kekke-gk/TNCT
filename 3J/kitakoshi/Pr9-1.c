/* グラフ構造の幅優先探索 */

#include<stdio.h>

#define TRUE            1
#define FALSE           0
#define MAX_SIZE        11

int adjacent[MAX_SIZE][MAX_SIZE]; /* 隣接行列 */
int visited[MAX_SIZE];
int open_list[MAX_SIZE]; /* キュー */

char *graph_data[] = {
	"CI",           /* A : C I */
	"DGH",          /* B : D G H */
	"ADG",          /* C : A D G */
	"BCHIJ",        /* D : B C H I J */
	"FHJ",          /* E : F H J */
	"EGK",          /* F : E G K */
	"BCF",          /* G : B C F */
	"BDEJ",         /* H : B D E J */
	"AD",           /* I : A D */
	"DEHK",         /* J : D E H K */
	"FJ"            /* K : F J */
};


/* グラフの初期化 */
void init_graph(void)
{
	int i,j,focus=0;
	char *tmp;

	for(i=0;i<MAX_SIZE;i++){
		for(j=0;j<MAX_SIZE;j++){
			adjacent[i][j]=0;
		}
	}

	for(i=0;i<MAX_SIZE;i++){
		tmp=graph_data[i];
		while(tmp[focus] != '\0'){
			for(j=0;j<MAX_SIZE;j++){
				if(tmp[focus] == 'A'+j){
					adjacent[i][j]=1;
					break;
				}
			}
			focus++;
		}
		focus=0;
	}

	printf("隣接行列:\n");
	for(i=0;i<MAX_SIZE;i++){
		for(j=0;j<MAX_SIZE;j++){
			printf("%d ",adjacent[i][j]);
		}
		printf("\n");
	}
}

/* キューの初期化 */
void init_queue(int *q)
{
	int i;
	for( i = 0; i < MAX_SIZE; i++ ){
		q[i] = -1;
	}
}

/* キューの表示 */
void print_queue(int *q)
{
	int i;
	printf("{");
	for( i = 0; i < MAX_SIZE; i++ )
		if( q[i] != -1 )
			printf("%c",q[i]+'A');
	printf("}\n");
}

/* キューの中にデータdが存在しているかどうかをチェック */
int check_queue(int *q,int d)
{
	int i;
	for( i = 0; i < MAX_SIZE;i++ )
		if( q[i] == d ) return TRUE;
	return FALSE; 
}

/* キューにデータを入れる */
void enqueue(int *q, int d)
{
	int i;
	for(i=0;i<MAX_SIZE;i++){
		if(q[i] == -1){
			q[i]=d;
			return;
		}
	}
}

/* キューからデータを取り出す */
int dequeue(int *q)
{
	int i,data=q[0];
	for(i=0;i<MAX_SIZE-1;i++){
		q[i]=q[i+1];
	}
	q[i]=-1;
	return data;
}

/* 経路の探索（幅優先探索） */
void search(int now, int end)
{
	int i,data,chk=0;
	init_queue(open_list);
	enqueue(open_list,now);
	visited[now]=TRUE;

   	printf("searching ... %c\n",'A'+open_list[0]);
	printf("open_list = ");
	print_queue(open_list);
	
	while(open_list[0] != -1){
		data=dequeue(open_list);
		if(data==end){
			printf("Found.\n");
			return;
		}else{
			for(i=0;i<MAX_SIZE;i++){
				if(visited[i]!=TRUE && adjacent[i][data]==1){
					visited[i]=TRUE;
					enqueue(open_list,i);
					printf("searching ... %c\n",'A'+i);
					printf("open_list = ");
					print_queue(open_list);
				}
			}
		}
	}
}

/* メイン関数 */
int main(void)
{
	init_graph();
	search(0, 10 );         /* A から K の経路 */
	return 0;
}
