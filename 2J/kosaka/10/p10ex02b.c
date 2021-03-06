/***  p10ex02.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>

char board[8][8];

void printBoard(void)
{
	int i,j;
	static int count=1;
	printf("#%d is found.\n",count);
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			printf("%2c",board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	count++;
}

void columnwork(int column)
{
	int i,j,k=0;
	int status=1;
	if (column==8) { /*column=8でこの関数が呼び出されたら，解が見つかっているということなので*/
		printBoard(); /*発見された解を表示*/
		return;
	}
	for (i=0; i<8; i++) {
		status=1;
		//i行column列の位置にクインがおけるかどうかのチェック
		//おけるならstatusには1,そうでなければ0が入っているようにする
		//同じ列にQがあるかどうか検査
		for(j=0;j<8;j++){
			if(board[i][j]=='Q'){
				status=0;
				break;
			}
		}
		
		//同じ行にQがあるかどうか検査
		for(j=0;j<8;j++){
			if(board[j][column]=='Q'){
				status=0;
				break;
			}
		}
	
		//右斜めにQがあるかどうか検査
		k=0;
		for(j=0;j<8-abs(i-column);j++){
			if(board[i+k][column+k]=='Q'){
				status=0;
				break;
			}
			k++;
			if(i+k>7 && !(column+k>7)){//右の壁についたら
				k=-column;
			}
			if(column+k>7 && !(i+k>7)){//下の壁についたら
				k=-i;
			}
			if(i+k>7 && column+k>7){//角についたら
				k=-column;
				//columnとiの値は同じであるからどちらをｋに代入してもよい。
			}
		}
	
		//左斜めにQがあるかどうか検査
		k=0;
		for(j=0;j<8-abs(7-(i+column));j++){
			if(board[i+k][column-k]=='Q'){
				status=0;
				break;
			}
			k++;
			if(i+k>7 && !(column-k<0)){//右の壁についたら
				k=-(7-column);
			}
			if(!(i+k>7) && column-k<0){//上の壁についたら
				k=-i;
			}
			if(i+k>7 && column-k<0){//角についたら
				k=-column;
				//columnとiの値は同じであるからどちらをkに代入してもよい。
			}
		}
		if (status==1) { /*i行column列の位置にクインが置けるなら*/
			/* i行column列の位置にクインを置く */
			board[i][column]='Q';
			

			columnwork(column+1); /*（column+1）列の作業に行く*/
			/* i行column列の位置のクインをはずす */
			board[i][column]='0';
			
			
		}
	}

}

void initBoard(void)
{
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			board[i][j]='0';
		}
	}
}

int main()
{
	initBoard();
	columnwork(0);
	return 0;
}


/**************** 実行結果 *****************
#1 is found.
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0

#2 is found.
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 Q 0 0 0 0 0

#3 is found.
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0

#4 is found.
 Q 0 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0

#5 is found.
 0 0 0 0 0 Q 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0

#6 is found.
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0

#7 is found.
 0 0 0 0 Q 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0

#8 is found.
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 Q 0 0

#9 is found.
 0 0 0 0 Q 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 Q 0 0 0 0 0

#10 is found.
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0

#11 is found.
 0 0 0 0 Q 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0

#12 is found.
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0

#13 is found.
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 Q 0 0 0 0 0
 0 0 0 0 Q 0 0 0

#14 is found.
 0 0 0 0 Q 0 0 0
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 0 0 0 Q 0 0 0 0

#15 is found.
 0 0 0 0 0 0 0 Q
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0

#16 is found.
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 Q 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 Q 0

#17 is found.
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0

#18 is found.
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0

#19 is found.
 0 0 0 0 Q 0 0 0
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0

#20 is found.
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0

#21 is found.
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 0 Q
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0

#22 is found.
 0 0 0 0 0 0 0 Q
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0

#23 is found.
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 0 Q
 Q 0 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0

#24 is found.
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0

#25 is found.
 0 0 0 0 0 Q 0 0
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 Q 0 0 0 0 0

#26 is found.
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0

#27 is found.
 0 0 0 0 0 0 Q 0
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0

#28 is found.
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0

#29 is found.
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 0 0 0 Q 0 0 0 0

#30 is found.
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0

#31 is found.
 0 0 0 0 0 Q 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 Q 0 0 0 0

#32 is found.
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0

#33 is found.
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0

#34 is found.
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0

#35 is found.
 0 0 0 0 0 Q 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 0 0 Q 0 0 0 0 0

#36 is found.
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 Q 0 0 0 0 0

#37 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0

#38 is found.
 0 0 0 0 0 Q 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 Q 0 0 0 0 0

#39 is found.
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0

#40 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 Q 0 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0

#41 is found.
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0

#42 is found.
 0 0 0 0 0 Q 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q

#43 is found.
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0

#44 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0

#45 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0

#46 is found.
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 0 Q 0 0 0 0 0 0

#47 is found.
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0

#48 is found.
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0

#49 is found.
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0

#50 is found.
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0

#51 is found.
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 Q 0 0

#52 is found.
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0

#53 is found.
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0

#54 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0

#55 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 Q 0 0

#56 is found.
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0
 0 0 Q 0 0 0 0 0

#57 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0

#58 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0

#59 is found.
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0

#60 is found.
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q

#61 is found.
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0

#62 is found.
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0

#63 is found.
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0

#64 is found.
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0

#65 is found.
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0

#66 is found.
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 Q 0

#67 is found.
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0

#68 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 Q 0 0

#69 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0

#70 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 Q 0 0 0 0

#71 is found.
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 0 Q

#72 is found.
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 Q 0 0 0 0

#73 is found.
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 0 Q
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0

#74 is found.
 0 0 0 0 0 0 Q 0
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 Q 0 0 0

#75 is found.
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 0 Q
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0

#76 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0

#77 is found.
 0 0 0 0 0 0 Q 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 Q 0 0 0 0

#78 is found.
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 0 Q

#79 is found.
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 Q 0 0 0

#80 is found.
 0 0 0 0 Q 0 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 Q 0 0 0 0 0 0

#81 is found.
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0

#82 is found.
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 Q 0 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0

#83 is found.
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 0 Q 0 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0

#84 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 0 0 0 Q 0 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0

#85 is found.
 0 0 0 0 0 Q 0 0
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0
 0 0 Q 0 0 0 0 0

#86 is found.
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 0 Q
 Q 0 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0

#87 is found.
 0 0 0 0 0 Q 0 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0

#88 is found.
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 Q 0 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 Q 0 0 0 0 0 0 0
 0 0 0 0 0 Q 0 0

#89 is found.
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 Q 0 0 0 0 0 0 0

#90 is found.
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 Q 0 0 0 0 0 0 0

#91 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 Q 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 0 Q 0 0
 0 0 0 Q 0 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0

#92 is found.
 0 0 Q 0 0 0 0 0
 0 0 0 0 0 Q 0 0
 0 0 0 Q 0 0 0 0
 0 Q 0 0 0 0 0 0
 0 0 0 0 0 0 0 Q
 0 0 0 0 Q 0 0 0
 0 0 0 0 0 0 Q 0
 Q 0 0 0 0 0 0 0



*******************************************/
