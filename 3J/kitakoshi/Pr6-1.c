/* ハッシュ法によるデータ管理（チェイン法版） */

#include <stdio.h>
#include <stdlib.h>

#define ERROR    -1
#define HASH_SIZE  9
typedef struct character {
	int no;                         /* キー */
	char name[16];                  /* 名前 */
	struct character *next_addr;    /* 次のデータのアドレス */
} CHARACTER;
CHARACTER *HashTable[HASH_SIZE];

/* 数値の入力用関数 */
int get_num(void)
{
	int  i;
	int  d = 0;
	int  c = 0;
	rewind(stdin);
	for( i = 0; i < 5 && c != '\n' ; i++ ) {
		/* 5ケタまで */
		c = getchar();
		if ( c == '\n' ) break;
		d = d * 10 + c - '0';
	}
	rewind(stdin);
	return d;
}

/* ハッシュ表からリスト構造で並んでいる様子を表示する */
void disp(void)
{
	int i = 0;
	struct character *current_addr;
	for( i = 0; i < HASH_SIZE; i++ ) {
		printf("-|%d|",i);
		printf("%2d|-",HashTable[i]);

        current_addr=HashTable[i];
		while(current_addr != NULL){
			printf("-|%d|",i);
			printf("%d:%d:%s:%d|-",current_addr,current_addr->no,current_addr->name,current_addr->next_addr);

			current_addr=current_addr->next_addr;
		}
		printf("\n");
	}
}

/* ハッシュ値の計算 */
int hash(int h)
{
	return h % HASH_SIZE;
}

/* データの追加 */
void add(void)
{
	struct character *p;
	struct character *q;
	int i=0, j;
	int h;
	/* 追加データのためのメモリを確保 */
	p=(CHARACTER *)malloc(sizeof(CHARACTER));
	printf("NO＝");
	p->no = get_num();
	printf("名前＝");
	fgets(p->name,16,stdin);
	for( j=0; p->name[j] != '\n' && j != 15; j++ );
	p->name[j] = '\0';
	/* ↑改行コードを削除するための処理 */
	p->next_addr = NULL;
	h = hash( p->no );
	if( HashTable[h] == NULL ) {
		/* HashTable[h]にまだデータが存在してなかったときの処理 */
		printf("a\n");
		HashTable[h]=p;
		printf("b\n");
	} else {
		/* HashTable[h]に既にデータが存在していたときの処理 */
		q=HashTable[h];
		while(q->next_addr != NULL){
			q=q->next_addr;
		}
		q->next_addr=p;
	}
	disp();
}

/* データの削除 */
int del(void)
{
	int i=0, h;
	struct character *current_addr,*head,*target;
	int point;
	disp();
	printf("NO＝");
	point = get_num();
	h = hash(point);

	current_addr=HashTable[h];
	target=HashTable[h];
	while(target != NULL){
		if(target->no == point){
			if(current_addr == target){
				HashTable[h]=current_addr->next_addr;
			}else{
				current_addr->next_addr=target->next_addr;
			}
			disp();
			return 1;
		}
		current_addr=target;
		target=current_addr->next_addr;
	}
	printf("NOT FOUND.\n");
	return ERROR;
}

/* データの探索 */
int search(void)
{
	int i=0, h;
	struct character *current_addr,*head,*target;
	int point;
	printf("NO＝");
	point = get_num();
	h = hash(point);

	current_addr=HashTable[h];
	while(current_addr!= NULL){
		if(current_addr->no == point){
			printf("探索キー%dに対応するデータは%sです．\n",point,current_addr->name);
			printf("-|%d|",h);
			printf("%2d:%d:%s|-\n",current_addr,current_addr->no,current_addr->name);
			i++;
		}
		current_addr=current_addr->next_addr;
	}
	if(i!=0){
		printf("******************************\n\n");
		disp();
		return 1;
	}
	printf("NOT FOUND.\n");
	return ERROR;
}


/* メニュー */
int menu(void)
{
	int c;
	while( 1 ) {
		printf("1.表\示\n");      // 課題5と同様の理由で，"表"と"示"の間に"\"を挿入
		printf("2.追加\n");
		printf("3.削除\n");
		printf("4.探索\n");
		printf("5.終了\n");
		c = get_num();
		if( c >= 1 && c <= 5 )  break;
		else                                    printf("1?5までの数字を入力してください\n");
	}
	switch( c ) {
		case 1:
			disp();
			break;
		case 2:
			add();
			break;
		case 3:
			del();
			break;
		case 4:
			search();
			break;
		case 5:
			return 1;
	}
	return 0;
}

int main(void)
{
	int i, end = 0;
	/* ハッシュ表を初期化 */
	for( i = 0; i < HASH_SIZE; i++ )
		HashTable[i] = NULL;
	while( !end ) {
		end = menu();
	}
	return 0;
}
