/* �O���t�\���̐[���D��T�� */

#include<stdio.h>
#define TRUE      1
#define FALSE     0
#define MAX_SIZE 11

typedef struct character{
	int  no;                        /* �L�[ */
	char name;                      /* ���O */
	struct character *next_addr;    /* ���̃f�[�^�̃A�h���X */
}CELL;

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

CELL *adjacent[MAX_SIZE]; /* �אڃ��X�g */
int visited[MAX_SIZE];
int path[MAX_SIZE];

/* ���X�g�\���ŕ���ł���l�q��\������ */
void disp(void) {
	int i = 0;
	CELL *current_addr;
	printf("�אڃ��X�g:\n");
	for( i = 0; i < MAX_SIZE; i++ ){
		if( adjacent[i] != NULL ){
			current_addr = adjacent[i];
			do{
				printf("-|%c|-",current_addr->name);
				current_addr = current_addr->next_addr;
			}while( current_addr != NULL );
		}
		printf("\n");
	}
}

/* �f�[�^�̒ǉ� */
void add(int parent, int child) {
	CELL *p;
	CELL *q;
	p = (CELL *)malloc(sizeof(CELL));
	p->no = child;
	p->name = 'A' + child;
	p->next_addr = NULL;
	q = adjacent[parent];
	while ( q->next_addr != NULL ) {
		q = q->next_addr;
	}
	q->next_addr = p;
}

/* �O���t�̏����� */
void init_graph(void) {
	int i,j,k;
	CELL *p,*q;
	for(i=0;i<MAX_SIZE;i++){
		visited[i]=FALSE;
	}
	for(i=0;i<MAX_SIZE;i++){
		adjacent[i] = (CELL *)malloc(sizeof(CELL));
		adjacent[i]->no = i;
		adjacent[i]->name = 'A'+i;
		adjacent[i]->next_addr = NULL;
	}
	for(i=0;i<MAX_SIZE;i++){
		q=adjacent[i];
		for(j=0;graph_data[i][j]!='\0';j++){
			p=(CELL *)malloc(sizeof(CELL));
			p->no=graph_data[i][j]-'A';
			p->name=graph_data[i][j];
			p->next_addr=NULL;
			q->next_addr=p;
			q=p;
		}
	}
	disp();
}

/* �o�H�̕\�� */
void print_path(int num) {
	int i;
	for( i = 0; i <= num; i++ ){
		printf("%c ", path[i] + 'A' );
	}
	printf("\n");
}

/* �o�H�̒T���i�[���D��T���j */
void search(int num, int now, int end) {
	CELL *p;
	visited[now]=TRUE;
	path[num]=now;
	if(now==end){
		print_path(num);
	}else{
		for(p=adjacent[now];p!=NULL;p=p->next_addr){
			if(visited[p->no]==FALSE){
				search(num+1,p->no,end);
			}
		}
	}
	visited[now]=FALSE;
}


/* ���C���֐� */
int main(void) {
	init_graph();
	search( 0, 0, 10 );             /* A(0) ���� K(10) �̌o�H */
	return 0;
}
