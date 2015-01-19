#include <3048fone.h>
#include "h8_3048fone.h"

main()
{
	int cnt[4]={0},buf[4]={0};
	int i,sw;
	initSCI1(); /*SCI-ch1の初期化*/
	initPushSW(); /*押しボタンスイッチの初期化*/
	SCI1_printf("Hello. How are you?\n");
	
	while (1) {
		sw = getPushSW();
	
		for(i=3;i>=0;i--){
			if( (sw&(1<<i)) == (1<<i) ){
				if(buf[i]==0){
					cnt[i]++;
					buf[i]=1;
				}
			}else if(buf[i]!=0){
				buf[i]=0;
			}
			SCI1_printf("SW%d:%2d回  ",i,cnt[i]);
		}
		SCI1_printf("\n");
	}
}