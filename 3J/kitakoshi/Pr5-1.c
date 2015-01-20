#include <stdio.h>
#include <string.h>

#define MAX_STATION 10                  /* 最大の駅の数 */
#define ERROR    NULL

typedef struct Station {
	char name[20+1];                /* 駅名は最大全角10文字まで */
	int  time;                      /* 前の駅からの所要時間 */
	struct Station *next_addr;      /* 次のデータのアドレス */
} STATION;

int station_num = 0;                    /* ファイルから読み込んだ駅の数 */
STATION station[MAX_STATION];           /* 数値の入力用配列 */
STATION head;

int get_num(void) {
	int  i;
	int  d = 0;
	int  c = 0;
	rewind(stdin);
	for( i = 0; i < 5 && c != '\n' ; i++ ) { /* 5ケタまで */
		c = getchar();
		if ( c == '\n' ) break;
		if(c < '0' || '9' < c) break;
		d = d * 10 + c - '0';
	}
	rewind(stdin);
	return d;
}

int get_data_num(void){
	STATION *tmp=head.next_addr;
	int cnt;
	for(cnt=1;tmp->next_addr!=NULL;cnt++){
		tmp=tmp->next_addr;
	}
	return cnt;
}

/* データファイルの読み込み */
int read_data(void)
{
	FILE *fp;
	int i;
	/* キャラクタデータ読み込み */
	//fp = station_data.txtの読み込み
	fp=fopen("station_data.txt","r");
		if ( fp == NULL ){
			fprintf(stderr,"CANNOT OPEN station_data.txt\n");
			return -1;
		}
	for( i = 0; i < MAX_STATION; i++, station_num++ ) {
		if ( fscanf(fp,"%s\t%d",station[i].name,&station[i].time) != 2 ) break;
		/* まずは読み込んだ順にリストをつなぐ */
		station[i].next_addr = &station[i+1];
	}
	fclose(fp);
	/* リストの先頭はhead.next_addrにセット */
	head.next_addr = &station[0];
	/* リストの最後はNULLを入れておく */
	station[station_num-1].next_addr = NULL;
	return 0;
}

/* 路線データを表示 */
void station_disp(void)
{
	STATION *current_addr;
	current_addr = head.next_addr;

	while(1){
		printf("|ADDR:%20d|\n",current_addr);
		printf("|NAME:%20s|\n",current_addr->name);
		printf("|TIME:%20d|\n",current_addr->time);
		printf("|NEXT:%20d|\n",current_addr->next_addr);
		printf("\n");
		if(current_addr->next_addr == NULL)
			break;
		/* current_addrを更新 */
		current_addr=current_addr->next_addr;
	}
}

/* 入力された駅がリストに存在しているかどうかのチェック */
STATION *check(char target[])
{
	/* リストをたどって指定された駅が含まれているかどうか確認 */
	STATION *current_addr;
	current_addr = head.next_addr;
	while(1){
		if( strcmp(target,current_addr->name)==0 )
			return current_addr;
		if(current_addr->next_addr == NULL)
			break;
		current_addr = current_addr->next_addr;
	}
	return ERROR;
}

/* データの追加 */
void add(void)
{
	STATION *current_addr;
	char stationName[16];
	char targetChar[16];    // 追加する駅の直前の駅名を格納
	int a_point; /* 配列としての追加位置 */
	int i;    /* 物理的には最後に追加する */

	if(get_data_num() == MAX_STATION){
		printf("駅の数が上限です．\n");
		return;
	}
	a_point = station_num++;
	//a_point = get_data_num();
	printf("NAME = ");
	//fgets(station[a_point].name,16,stdin);
	fgets(stationName,16,stdin);
	//for( i=0; station[a_point].name[i] != '\n' && i != 15; i++ );
	for( i=0; stationName[i] != '\n' && i != 15; i++ );
	//station[a_point].name[i] = '\0';
   stationName[i]  = '\0';

   if(check(stationName)!=NULL){
	   printf("すでに存在する駅名です．\n");
	   return;
   }

   strcpy(station[a_point].name,stationName);


	/* ←↑改行コードを削除するための処理 */
	printf("TIME = ");
	station[a_point].time = get_num();
	station_disp();
	do{
		printf("どの駅の後に追加しますか?\nNAME = ");
		fgets(targetChar,16,stdin);
		for( i=0; targetChar[i] != '\n' && i != 15; i++ );
		targetChar[i] = '\0';
		/* ↑改行コードを削除するための処理 */
	} while( check(targetChar) == ERROR );
	current_addr=check(targetChar);
	/* データの追加（リストをつなぐ） */
	station[a_point].next_addr=current_addr->next_addr;
	current_addr->next_addr=&station[a_point];
	station_disp();
}

/* データの削除 */
void del(void)
{
	int i;
	STATION *forDel=NULL; // 削除したい要素を格納するポインタ
	STATION *current_addr;
	char targetChar[16];

	station_disp();
	if(get_data_num()==1){
		printf("駅の数が一つなので削除できません\n");
		return;
	}
	do{
		printf("どの駅を削除しますか?\nNAME = ");
		fgets(targetChar,16,stdin);
		for( i=0; targetChar[i] != '\n' && i != 15; i++ );
		targetChar[i] = '\0';
		/* ↑改行コードを削除するための処理 */
	} while( check(targetChar) == ERROR );
	current_addr = head.next_addr;
	/* 残り１つだったらそれ以上消さない */
	while(1){
		if(strcmp(current_addr->name,targetChar) == 0 && current_addr == head.next_addr){
			/* 先頭を削除したい場合 */
			head.next_addr = current_addr->next_addr;
			break;
		}

		forDel=current_addr->next_addr;
		if(forDel!=NULL && strcmp(forDel->name,targetChar)==0){
			current_addr->next_addr=forDel->next_addr;
			break;
		}
		/* 先頭以外を削除したい場合 */

		/* current_addrを更新 */
		current_addr=current_addr->next_addr;
	}
	station_disp();
}

/* 所要時間の計算 */
void calc(void)
{
	int sum=0, i;
	int flag=0;

	STATION *current_addr;
	char targetFrom[16],targetTo[16];


	if(get_data_num()==1){
		printf("駅の数が一つなので所要時間の計算は必要ありません．");
		return;
	}

	printf("どこからどこまでの所要時間を計算しますか？\n");
	do{
		printf("FROM(Station Name) = ");
		fgets(targetFrom,16,stdin);
		for( i=0; targetFrom[i] != '\n' && i != 15; i++ );
		targetFrom[i] = '\0';
		/* ↑改行コードを削除するための処理 */
	} while( check(targetFrom) == ERROR );
	do{
		printf("TO(Station Name) = ");
		fgets(targetTo,16,stdin);
		for( i=0; targetTo[i] != '\n' && i != 15; i++ );
		targetTo[i] = '\0';
		/* ↑改行コードを削除するための処理 */
	} while( check(targetTo) == ERROR );

    if(strcmp(targetFrom,targetTo)==0){
		printf("出発する駅と到着する駅が同じです．\n");
		return;
	}

	printf("%sから",targetFrom);
	printf("%sまでですね\n",targetTo);
	/* 所要時間を計算する */
	
	current_addr=head.next_addr;
	while(current_addr != NULL){
		if(flag==1){
			sum+=current_addr->time;
		}
		if(strcmp(targetFrom,current_addr->name)==0 || strcmp(targetTo,current_addr->name)==0){
			flag++;
			if(flag==2) break;
		}
		current_addr=current_addr->next_addr;
	}

	printf("所要時間は%dです\n",sum);
}

/* メニュー */
int menu(void)
{
	int c;
	while( 1 ){
		printf("1.表\示\n");   // 表と示の間の"\"はおまじない（外すとどうなるか、試してみてもよい
		printf("2.追加\n");
		printf("3.削除\n");
		printf("4.所要時間\n");
		printf("5.終了\n");
		c = get_num();
		if( c >= 1 && c <= 5 )
			break;
		else
			printf("1?5までの数字を入力してください\n");
	}
	switch( c ){
		case 1:
			station_disp();
			break;
		case 2:
			add();
			break;
		case 3:
			del();
			break;
		case 4:
			calc();
			break;
		case 5:
			return 1;
	}
	return 0;
}

int main(void)
{
	int end = 0;
	end = read_data();
	while( !end ){
		end = menu();
	}
	return 0;
}
