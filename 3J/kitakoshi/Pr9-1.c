/* �O���t�\���̕��D��T�� */

#include<stdio.h>

#define TRUE            1
#define FALSE           0
#define MAX_SIZE        11

int adjacent[MAX_SIZE][MAX_SIZE]; /* �אڍs�� */
int visited[MAX_SIZE];
int open_list[MAX_SIZE]; /* �L���[ */

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


/* �O���t�̏����� */
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

	printf("�אڍs��:\n");
	for(i=0;i<MAX_SIZE;i++){
		for(j=0;j<MAX_SIZE;j++){
			printf("%d ",adjacent[i][j]);
		}
		printf("\n");
	}
}

/* �L���[�̏����� */
void init_queue(int *q)
{
	int i;
	for( i = 0; i < MAX_SIZE; i++ ){
		q[i] = -1;
	}
}

/* �L���[�̕\�� */
void print_queue(int *q)
{
	int i;
	printf("{");
	for( i = 0; i < MAX_SIZE; i++ )
		if( q[i] != -1 )
			printf("%c",q[i]+'A');
	printf("}\n");
}

/* �L���[�̒��Ƀf�[�^d�����݂��Ă��邩�ǂ������`�F�b�N */
int check_queue(int *q,int d)
{
	int i;
	for( i = 0; i < MAX_SIZE;i++ )
		if( q[i] == d ) return TRUE;
	return FALSE; 
}

/* �L���[�Ƀf�[�^������ */
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

/* �L���[����f�[�^�����o�� */
int dequeue(int *q)
{
	int i,data=q[0];
	for(i=0;i<MAX_SIZE-1;i++){
		q[i]=q[i+1];
	}
	q[i]=-1;
	return data;
}

/* �o�H�̒T���i���D��T���j */
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

/* ���C���֐� */
int main(void)
{
	init_graph();
	search(0, 10 );         /* A ���� K �̌o�H */
	return 0;
}
