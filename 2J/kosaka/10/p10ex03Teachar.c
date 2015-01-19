#include <stdio.h>
#include <stdlib.h>

/******************************************************
�T�~�T�̔Ֆʂł̃`�F�X��knight�̈ړ��ŔՖʂ��ׂẴZ����
�ʉ߂���菇�������ĕ\�����܂��B
�T�~�T�̔z�������C�K�₵�Ă��Ȃ��Ƃ���ɂ͂O�𖄂�
�K�₵���Ƃ���ɂ́C�K�⏇�ԍ��������܂��B
�������Ֆʒ[�̃`�F�b�N���ȒP�ɂ��邽�߁C���͊O���ɂQ��
�����z�������C?�P�𖄂߂Ă����܂��B
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
} move_t; //����̈ړ��ʂ�\���^

int board[5+4][5+4];              //�Ֆʔz��
move_t move[8]={
    {2,1},{1,2},{-1,2},{-2,1},
    {-2,-1},{-1,-2},{1,-2},{2,-1}
};                               //���̈ړ��ʂ̑S���
int counter;                     //�萔�J�E���^

void printBoard(void) //�Ֆʂ̑S�\��
{
    int i,j;
    static int found=0; //������������@�̌�
    printf("Tour #%d is found.\n",++found);
    for (i=2; i<7; i++) {
        for (j=2; j<7; j++) {
            printf("%4d",board[i][j]);
        }
        printf("\n");
    }
    if (found==3) exit(1); //�R��������I��
}

void knighttour(int x, int y)
// �Ֆʂ̍��W(x,y)��knight�������Ԃ��玟�̓�������s����
{
    int i;
    int nextx, nexty;    //���̍��W(nextx,nexty)
    for (i=0; i<8; i++) {
        nextx=x+move[i].x;
        nexty=y+move[i].y;
        if (board[nexty][nextx]==0) {
            //���W(nextx,nexty)�͋󂾂����̂�
            board[nexty][nextx]=++counter;
            if (counter==25) { /*�����Ăяo���ɂȂ�Ȃ��ۏ�*/
                //�Ō�܂Ŗ��܂����̂�
                printBoard();
            } else {
                knighttour(nextx,nexty);
            }
            board[nexty][nextx]=0;
            --counter;
        }
    }
}

void initBoard(void) //�Ֆʂ̏�����
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

