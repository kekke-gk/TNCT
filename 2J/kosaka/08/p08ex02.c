/***  p08ex02.c  ***/
/***  s12083  2J18  ŒÜ–¡‹ž—S  ***/

#include <stdio.h>

typedef struct{
	int numerator;//•ªŽq
	int denominator;//•ª•ê
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
	
	//•ªŽq‚Æ•ª•ê‚ÌÅ‘åŒö–ñ”‚ð‹‚ßC‚»‚ê‚ÅŠ„‚é‚±‚Æ‚É‚æ‚Á‚Ä–ñ•ª‚µ‚Ä‚¢‚éB
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
	printf("ˆê‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");
	scanf("%d %d",&fraction1.numerator,&fraction1.denominator);
	printf("“ñ‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");
	scanf("%d %d",&fraction2.numerator,&fraction2.denominator);
	
	printf("‘«‚µŽZ      %2d/%d\n",addFraction(fraction1,fraction2));
	printf("ˆø‚«ŽZ(1-2) %2d/%d\n",subtractFraction(fraction1,fraction2));
	printf("ˆø‚«ŽZ(2-1) %2d/%d\n",subtractFraction(fraction2,fraction1));
	printf("Š|‚¯ŽZ      %2d/%d\n",multiplyFraction(fraction1,fraction2));
	printf("Š„‚èŽZ(1/2) %2d/%d\n",divideFraction(fraction1,fraction2));
	printf("Š„‚èŽZ(2/1) %2d/%d\n",divideFraction(fraction2,fraction1));
	
	
	return 0;
}


/**************** ŽÀsŒ‹‰Ê *****************
ˆê‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
1 6
“ñ‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
1 3
‘«‚µŽZ       1/2
ˆø‚«ŽZ(1-2) -1/6
ˆø‚«ŽZ(2-1)  1/6
Š|‚¯ŽZ       1/18
Š„‚èŽZ(1/2)  1/2
Š„‚èŽZ(2/1)  2/1

ˆê‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
1 6
“ñ‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
-1 3
‘«‚µŽZ      -1/6
ˆø‚«ŽZ(1-2)  1/2
ˆø‚«ŽZ(2-1) -1/2
Š|‚¯ŽZ      -1/18
Š„‚èŽZ(1/2) -1/2
Š„‚èŽZ(2/1) -2/1

ˆê‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
-1 6
“ñ‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
1 3
‘«‚µŽZ       1/6
ˆø‚«ŽZ(1-2) -1/2
ˆø‚«ŽZ(2-1)  1/2
Š|‚¯ŽZ      -1/18
Š„‚èŽZ(1/2) -1/2
Š„‚èŽZ(2/1) -2/1

ˆê‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
-1 6
“ñ‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
-1 3
‘«‚µŽZ      -1/2
ˆø‚«ŽZ(1-2)  1/6
ˆø‚«ŽZ(2-1) -1/6
Š|‚¯ŽZ       1/18
Š„‚èŽZ(1/2)  1/2
Š„‚èŽZ(2/1)  2/1

ˆê‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
3 4
“ñ‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
16 3
‘«‚µŽZ      73/12
ˆø‚«ŽZ(1-2) -55/12
ˆø‚«ŽZ(2-1) 55/12
Š|‚¯ŽZ       4/1
Š„‚èŽZ(1/2)  9/64
Š„‚èŽZ(2/1) 64/9

ˆê‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
3 4
“ñ‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
-16 3
‘«‚µŽZ      -55/12
ˆø‚«ŽZ(1-2) 73/12
ˆø‚«ŽZ(2-1) -73/12
Š|‚¯ŽZ      -4/1
Š„‚èŽZ(1/2) -9/64
Š„‚èŽZ(2/1) -64/9

ˆê‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
-3 4
“ñ‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
16 3
‘«‚µŽZ      55/12
ˆø‚«ŽZ(1-2) -73/12
ˆø‚«ŽZ(2-1) 73/12
Š|‚¯ŽZ      -4/1
Š„‚èŽZ(1/2) -9/64
Š„‚èŽZ(2/1) -64/9

ˆê‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
-3 4
“ñ‚Â–Ú‚Ì•ª”‚Ì•ªŽqA•ª•ê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B
-16 3
‘«‚µŽZ      -73/12
ˆø‚«ŽZ(1-2) 55/12
ˆø‚«ŽZ(2-1) -55/12
Š|‚¯ŽZ       4/1
Š„‚èŽZ(1/2)  9/64
Š„‚èŽZ(2/1) 64/9
*******************************************/