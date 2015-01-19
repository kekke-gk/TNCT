#include <stdio.h>
#include <stdlib.h>

/******************************************************
５×５の盤面でのチェスのknightの移動で盤面すべてのセルを
通過する手順を見つけて表示します。
５×５の配列をつくり，訪問していないところには０を埋め
訪問したところには，訪問順番号を書きます。
ただし盤面端のチェックを簡単にするため，周囲外側に２列
多く配列をつくり，?１を埋めておきます。
   x 0 1 2 3 4 5 6 7 8
 y                   
 0  -1-1-1-1-1-1-1-1-1
 1  -1-1-1-1-1-1-1-1-1
 2  -1-1 0 0 0 0 0-1-1
 3  -1-1 0 0 0 0 0-1-1
 4  -1-1 0 0 0 0 0-1-1
 5  -1-1 0 0 0 0 0-1-1
 6  -1-1 0 0 0 0 0-1-1
 7  -1-1-1-1-1-1-1-1-1
 8  -1-1-1-1-1-1-1-1-1
******************************************************/
typedef struct {
    int x;
    int y;
} move_t; //一手先の移動量を表す型

int board[5+4][5+4];              //盤面配列
move_t move[8]={
    {2,1},{1,2},{-1,2},{-2,1},
    {-2,-1},{-1,-2},{1,-2},{2,-1}
};                               //一手の移動量の全種類
int counter;                     //手数カウンタ

void printBoard(void) //盤面の全表示
{
    int i,j;
    static int found=0; //見つけた巡回方法の個数
    printf("Tour #%d is found.\n",++found);
    for (i=2; i<7; i++) {
        for (j=2; j<7; j++) {
            printf("%4d",board[i][j]);
        }
        printf("\n");
    }
    if (found==3) exit(1); //３つ見つけたら終了
}

void knighttour(int x, int y)
// 盤面の座標(x,y)にknightがいる状態から次の動作を試行する
{
    int i;
    int nextx, nexty;    //次の座標(nextx,nexty)
    for (i=0; i<8; i++) {
        nextx=x+move[i].x;
        nexty=y+move[i].y;
        if (board[nexty][nextx]==0) {
            //座標(nextx,nexty)は空だったので
            board[nexty][nextx]=++counter;
            if (counter==25) { /*無限呼び出しにならない保障*/
                //最後まで埋まったので
                printBoard();
            } else {
                knighttour(nextx,nexty);
            }
            board[nexty][nextx]=0;
            --counter;
        }
    }
}

void initBoard(void) //盤面の初期化
{
    int i,j;
    for (i=0; i<9; i++) {
        for (j=0; j<9; j++) {
            board[i][j]=-1;
        }
    }
    for (i=2; i<7; i++) {
        for (j=2; j<7; j++) {
            board[i][j]=0;
        }
    }
}

int main()
{
    int x,y;
    initBoard();
    counter=1;
    x=2;
    y=2;
    board[y][x]=counter;
    knighttour(x,y);
    return 0;
}

