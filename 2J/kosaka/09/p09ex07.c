/***  p09ex07.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>

typedef struct{
	int hour;
	int min;
	int sec;
}hmstime_t;

hmstime_t addTime(hmstime_t *t1,hmstime_t *t2);

int main()
{
	hmstime_t t1={2,46,27};
	hmstime_t t2={1,34,34};
	hmstime_t t3;
	hmstime_t t4={2,46,27};
	hmstime_t t5={1,13,34};
	hmstime_t t6;
	t3=addTime(&t1,&t2);
	t6=addTime(&t4,&t5);
	printf("%2d:%2d:%2d\n",t3.hour,t3.min,t3.sec);
	printf("%2d:%2d:%2d\n",t6.hour,t6.min,t6.sec);
	return 0;
}

hmstime_t addTime(hmstime_t *t1,hmstime_t *t2)
{
	hmstime_t t3={0,0,0};

	/*
	アロー演算子 ->
		構造体ポインタ -> メンバ名
	という形で利用する。
		構造体変数名.メンバ名
	この式と同じことである。
	*/
	t3.sec+=t1->sec + t2->sec;
	if(t3.sec>=60){
		t3.sec-=60;
		t3.min+=1;
	}

	t3.min+=t1->min + t2->min;
	if(t3.min>=60){
		t3.min-=60;
		t3.hour+=1;
	}
	
	t3.hour+=t1->hour + t2->hour;
	
	return t3;
}
/**************** 実行結果 *****************
 4:21: 1
 4: 0: 1
  *******************************************/
