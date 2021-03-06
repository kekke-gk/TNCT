/***  p08ex02.c  ***/
/***  s12083  2J18  五味京祐  ***/

#include <stdio.h>

typedef struct{
	int numerator;//分子
	int denominator;//分母
}fraction_t;

fraction_t reduceFraction(fraction_t fraction)
{
	int x=fraction.numerator;
	int y=fraction.denominator;
	int r,z=0;
	
	if(x<0){
		x*=-1;
		z=1;
	}
	
	//分子と分母の最大公約数を求め，それで割ることによって約分している。
	r=x%y;
	while(r!=0){
		x=y; y=r;
		r=x%y;
	}
	
	if(z==1) x*=-1;
	
	fraction.numerator/=y;
	fraction.denominator/=y;
	
	if(fraction.denominator<0){
		fraction.denominator*=-1;
		fraction.numerator*=-1;
	}
	return fraction;
}

fraction_t addFraction(fraction_t a,fraction_t b)
{
	fraction_t c;
	c.denominator=a.denominator * b.denominator;
	c.numerator=a.numerator*b.denominator + b.numerator*a.denominator;
	
	c=reduceFraction(c);
	return c;
}

fraction_t subtractFraction(fraction_t a,fraction_t b)
{
	fraction_t c;
	c.denominator=a.denominator * b.denominator;
	c.numerator=a.numerator*b.denominator - b.numerator*a.denominator;
	
	c=reduceFraction(c);
	return c;
}

fraction_t multiplyFraction(fraction_t a,fraction_t b)
{
	fraction_t c;
	c.numerator=a.numerator*b.numerator;
	c.denominator=a.denominator*b.denominator;
	c=reduceFraction(c);
	
	return c;
}

fraction_t divideFraction(fraction_t a,fraction_t b)
{
	fraction_t c;
	if(b.numerator==0){
		c.numerator=10000000;
		c.denominator=1;
		return c;
	}
	
	c.numerator=a.numerator * b.denominator;
	c.denominator=a.denominator * b.numerator;
	
	c=reduceFraction(c);
	
	return c;
}

int main()
{
	int a;
	fraction_t fraction1,fraction2;
	printf("一つ目の分数の分子、分母を入力してください。\n");
	scanf("%d %d",&fraction1.numerator,&fraction1.denominator);
	printf("二つ目の分数の分子、分母を入力してください。\n");
	scanf("%d %d",&fraction2.numerator,&fraction2.denominator);
	
	printf("足し算      %2d/%d\n",addFraction(fraction1,fraction2));
	printf("引き算(1-2) %2d/%d\n",subtractFraction(fraction1,fraction2));
	printf("引き算(2-1) %2d/%d\n",subtractFraction(fraction2,fraction1));
	printf("掛け算      %2d/%d\n",multiplyFraction(fraction1,fraction2));
	printf("割り算(1/2) %2d/%d\n",divideFraction(fraction1,fraction2));
	printf("割り算(2/1) %2d/%d\n",divideFraction(fraction2,fraction1));
	
	
	return 0;
}


/**************** 実行結果 *****************
一つ目の分数の分子、分母を入力してください。
1 6
二つ目の分数の分子、分母を入力してください。
1 3
足し算       1/2
引き算(1-2) -1/6
引き算(2-1)  1/6
掛け算       1/18
割り算(1/2)  1/2
割り算(2/1)  2/1

一つ目の分数の分子、分母を入力してください。
1 6
二つ目の分数の分子、分母を入力してください。
-1 3
足し算      -1/6
引き算(1-2)  1/2
引き算(2-1) -1/2
掛け算      -1/18
割り算(1/2) -1/2
割り算(2/1) -2/1

一つ目の分数の分子、分母を入力してください。
-1 6
二つ目の分数の分子、分母を入力してください。
1 3
足し算       1/6
引き算(1-2) -1/2
引き算(2-1)  1/2
掛け算      -1/18
割り算(1/2) -1/2
割り算(2/1) -2/1

一つ目の分数の分子、分母を入力してください。
-1 6
二つ目の分数の分子、分母を入力してください。
-1 3
足し算      -1/2
引き算(1-2)  1/6
引き算(2-1) -1/6
掛け算       1/18
割り算(1/2)  1/2
割り算(2/1)  2/1

一つ目の分数の分子、分母を入力してください。
3 4
二つ目の分数の分子、分母を入力してください。
16 3
足し算      73/12
引き算(1-2) -55/12
引き算(2-1) 55/12
掛け算       4/1
割り算(1/2)  9/64
割り算(2/1) 64/9

一つ目の分数の分子、分母を入力してください。
3 4
二つ目の分数の分子、分母を入力してください。
-16 3
足し算      -55/12
引き算(1-2) 73/12
引き算(2-1) -73/12
掛け算      -4/1
割り算(1/2) -9/64
割り算(2/1) -64/9

一つ目の分数の分子、分母を入力してください。
-3 4
二つ目の分数の分子、分母を入力してください。
16 3
足し算      55/12
引き算(1-2) -73/12
引き算(2-1) 73/12
掛け算      -4/1
割り算(1/2) -9/64
割り算(2/1) -64/9

一つ目の分数の分子、分母を入力してください。
-3 4
二つ目の分数の分子、分母を入力してください。
-16 3
足し算      -73/12
引き算(1-2) 55/12
引き算(2-1) -55/12
掛け算       4/1
割り算(1/2)  9/64
割り算(2/1) 64/9
*******************************************/