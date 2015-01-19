/***  p08ex03.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>

typedef struct{
	char name[64]; //名前
	int height;    //身長
	int weight;    //体重
	int year;      //生まれた年
}tableTennis_t;

tableTennis_t player[]={
	{ "Kishikawa Seiya", 168, 68, 1987},
	{ "Matsushita Koji", 171, 65, 1967},
	{     "Fukuhara Ai", 155, 46, 1988},
	{"Matsudaira Kenta", 167, 57, 1991},
	{    "Mizutani Jun", 172, 68, 1989},
	{ "Ishikawa Kasumi", 157, 49, 1993},
	{   "Hirano Sayaka", 158, 53, 1985},
	{       "Timo Boll", 181, 74, 1981},
	{          "Ma Lin", 173, 75, 1980},
	{    "Michael Maze", 185, 77, 1981},
	{         "Ma Lont", 176, 70, 1988}
};

void sortName(tableTennis_t palyer[],int number)
{
	int i,j;
	tableTennis_t tmp;
	for(i=0;i<number-1;i++){
		for(j=i+1;j<number;j++){
			if(0< strcmp(player[i].name,player[j].name)){
				tmp=player[i];
				player[i]=player[j];
				player[j]=tmp;
			}
		}
	}
}

void sortHeight(tableTennis_t palyer[],int number)
{
	int i,j;
	tableTennis_t tmp;
	for(i=0;i<number-1;i++){
		for(j=i+1;j<number;j++){
			if(player[i].height<player[j].height){
				tmp=player[i];
				player[i]=player[j];
				player[j]=tmp;
			}
		}
	}
}

void sortWeight(tableTennis_t palyer[],int number)
{
	int i,j;
	tableTennis_t tmp;
	for(i=0;i<number-1;i++){
		for(j=i+1;j<number;j++){
			if(player[i].weight<player[j].weight){
				tmp=player[i];
				player[i]=player[j];
				player[j]=tmp;
			}
		}
	}
}

void sortYear(tableTennis_t palyer[],int number)
{
	int i,j;
	tableTennis_t tmp;
	for(i=0;i<number-1;i++){
		for(j=i+1;j<number;j++){
			if(player[i].year<player[j].year){
				tmp=player[i];
				player[i]=player[j];
				player[j]=tmp;
			}
		}
	}
}

void printPlayer(tableTennis_t player[],int number)
{
	int i;
	for(i=0;i<number;i++){
		printf("%-28s %5d %5d %5d\n",
			player[i].name,
			player[i].height,
			player[i].weight,
			player[i].year);
	}
}

int main()
{
	int numberOfPlayer=sizeof(player)/sizeof(tableTennis_t);
	
	printf("     Original data\n");
	printPlayer(player,numberOfPlayer);

	sortName(player,numberOfPlayer);
	printf("\n     Title order\n");
	printPlayer(player,numberOfPlayer);

	sortHeight(player,numberOfPlayer);
	printf("\n     Height order\n");
	printPlayer(player,numberOfPlayer);

	sortWeight(player,numberOfPlayer);
	printf("\n     Weight order\n");
	printPlayer(player,numberOfPlayer);

	sortYear(player,numberOfPlayer);
	printf("\n     Year order\n");
	printPlayer(player,numberOfPlayer);
	return 0;
}


/**************** 実行結果 *****************
     Original data
Kishikawa Seiya                168    68  1987
Matsushita Koji                171    65  1967
Fukuhara Ai                    155    46  1988
Matsudaira Kenta               167    57  1991
Mizutani Jun                   172    68  1989
Ishikawa Kasumi                157    49  1993
Hirano Sayaka                  158    53  1985
Timo Boll                      181    74  1981
Ma Lin                         173    75  1980
Michael Maze                   185    77  1981
Ma Lont                        176    70  1988

     Title order
Fukuhara Ai                    155    46  1988
Hirano Sayaka                  158    53  1985
Ishikawa Kasumi                157    49  1993
Kishikawa Seiya                168    68  1987
Ma Lin                         173    75  1980
Ma Lont                        176    70  1988
Matsudaira Kenta               167    57  1991
Matsushita Koji                171    65  1967
Michael Maze                   185    77  1981
Mizutani Jun                   172    68  1989
Timo Boll                      181    74  1981

     Height order
Michael Maze                   185    77  1981
Timo Boll                      181    74  1981
Ma Lont                        176    70  1988
Ma Lin                         173    75  1980
Mizutani Jun                   172    68  1989
Matsushita Koji                171    65  1967
Kishikawa Seiya                168    68  1987
Matsudaira Kenta               167    57  1991
Hirano Sayaka                  158    53  1985
Ishikawa Kasumi                157    49  1993
Fukuhara Ai                    155    46  1988

     Weight order
Michael Maze                   185    77  1981
Ma Lin                         173    75  1980
Timo Boll                      181    74  1981
Ma Lont                        176    70  1988
Mizutani Jun                   172    68  1989
Kishikawa Seiya                168    68  1987
Matsushita Koji                171    65  1967
Matsudaira Kenta               167    57  1991
Hirano Sayaka                  158    53  1985
Ishikawa Kasumi                157    49  1993
Fukuhara Ai                    155    46  1988

     Year order
Ishikawa Kasumi                157    49  1993
Matsudaira Kenta               167    57  1991
Mizutani Jun                   172    68  1989
Ma Lont                        176    70  1988
Fukuhara Ai                    155    46  1988
Kishikawa Seiya                168    68  1987
Hirano Sayaka                  158    53  1985
Timo Boll                      181    74  1981
Michael Maze                   185    77  1981
Ma Lin                         173    75  1980
Matsushita Koji                171    65  1967

*******************************************/
