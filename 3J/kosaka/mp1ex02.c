/*  マザーボード上のLEDの1秒ごとのON-OFFを行う  */

#include <3048fone.h>
#include "h8_3048fone.h"
/*
int countOnes(short int value){
	int num=1;
	int count=0;
	while(value>=num*2) num*=2;
	while(1){
		if(value>=num){
			value-=num;
			count++;
			if(value==0) break;
		}
		if(num==1) break;
		num/=2;
	}
	return count;
}
*/

int countOnes(short int value){
	int count=0;
	while(value!=0){
		count+=1-(value&0);
		value=((unsigned short int)value)>>1;
	}
	return count;
}

int countZeros(short int value)
{
    int count=0;
    while (value!=0) {
        count+=1-(value&1);
        value=((unsigned short int)value)>>1;
    }
    return count;
}

main()
{
	short int i;
	int no0,no1,error=0;
	initSCI1();
	for(i=-20;i<=20;i++){
		no0=countZeros(i);
		no1=countOnes(i);
		if(no0+no1!=16){
			SCI1_printf("%d %d\n",no0,no1);
		}
		error++;
	}
	SCI1_printf("%d\n",error);
} 

