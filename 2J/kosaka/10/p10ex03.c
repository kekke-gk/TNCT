/***  p10ex03.c  ***/
/***  s12083  2J18  ŒÜ–¡‹—S  ***/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}move_t;

int size;
int **board;
int *board_b;
int found=0;
int count=1;

move_t move[8]={
	{2,1},{1,2},{-1,2},{-2,1},
	{-2,-1},{-1,-2},{1,-2},{2,-1}
};

void printBoard();
void initBoard();
int knighttour(int,int);
void openBoard();

int main()
{
	int x,y,i,j;
	printf("”Õ–Ê‚Ì‘å‚«‚³‚ªx‚©‚çy‚É‚Â‚¢‚Ä’T‚µ‚Ü‚·B(x<=y)\nx‚Æy‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\nx,y = ");
	scanf("%d,%d",&x,&y);
	
	for(i=x;i<=y;i++){
		size=i;
		count=1;
		openBoard();
		initBoard();

		board[2][2]=1;
		knighttour(2,2);
		free(board);
	}
	return 0;
}


void printBoard()
{
	int i,j;
	printf("Tour #%d is found.\n",++found);
	for(i=2;i<size+2;i++){
		for(j=2;j<size+2;j++){
			printf("%4d",board[i][j]);
		}
		printf("\n");
	}
	return;
}

void initBoard()
{
	int i,j;
	for(i=0;i<size+4;i++){
		for(j=0;j<size+4;j++){
			board[i][j]=-1;
		}
	}

	for(i=2;i<size+2;i++){
		for(j=2;j<size+2;j++){
			board[i][j]=0;
		}
	}
}


int knighttour(int x,int y)
{
	int nextx,nexty,i;

	for(i=0;i<8;i++){
		nextx=x+move[i].x;
		nexty=y+move[i].y;
		if(board[nexty][nextx]==0){
			board[nexty][nextx]=++count;
			if(count==size*size){
				printBoard();
				if(found==3){
					printf("%d~%d is finished\n\n",size,size);
					found=0;
					return 1;
				}
			}else{
				if(knighttour(nextx,nexty)==1) return 1;
			}
			board[nexty][nextx]=0;
			--count;
		}
	}
	return 0;
}

void openBoard()
{
	int i,j;
	
	board=(int **)malloc(sizeof(int *) * (size+4));
	board_b=(int *)malloc(sizeof(int) * (size+4) * (size+4));
	for(i=0;i<size+4;i++){
		board[i]=board_b+i*(size+4);
	}
}

/**************** ÀsŒ‹‰Ê *****************


*******************************************/
