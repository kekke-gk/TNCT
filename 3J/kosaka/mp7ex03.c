#include <3048fone.h>
#include "h8_3048fone.h"

main()
{
	unsigned long int i,ad;
	unsigned int j;
	initSCI1(); /*SCI-ch1の初期化*/
	initPushSW(); /*押しボタンスイッチの初期化*/
	
	SCI1_printf("memory dump 0x00000-0x001ff\n");
	SCI1_printf("     ");
	for(j=0;j<16;j++){
		SCI1_printf(" +%X",j);
	}
	SCI1_printf("\n");
	for(i=0;i<=496;i+=16){
		SCI1_printf("%05lx",i);
		for(j=0;j<16;j++){
			ad=i+j;
			SCI1_printf(" %02x",*(unsigned char *)ad);
		}
		SCI1_printf("\n");
	}
}

/* 実行結果
memory dump 0x00000-0x001ff
      +0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +A +B +C +D +E +F
00000 00 00 01 00 ff ff ff ff ff ff ff ff ff ff ff ff
00010 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
00020 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
00030 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
00040 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
00050 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
00060 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
00070 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
00080 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
00090 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
000a0 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
000b0 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
000c0 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
000d0 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
000e0 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
000f0 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff
00100 7a 07 00 0f ff 10 01 00 6b 20 00 00 0e 4a 01 00
00110 6b 21 00 00 0e 4e 01 00 6b 22 00 00 0e 52 01 f0
00120 64 22 5a 00 01 2e 6c 03 68 93 0b 71 1b 72 46 f6
00130 01 00 6b 21 00 00 0e 56 01 00 6b 22 00 00 0e 5a
00140 f3 00 01 f0 64 22 5a 00 01 50 68 93 0b 71 1b 72
00150 46 f8 5e 00 0c f4 40 fe 06 7f 54 70 04 80 54 70
00160 18 88 38 ba 38 b8 f8 13 38 b9 19 00 0b 50 79 20
00170 03 e8 4d f8 f8 30 38 ba 54 70 29 bc 17 51 0d 10
00180 79 60 00 38 47 16 7f bc 72 60 7f bc 72 50 7f bc
00190 72 40 7f bc 72 30 79 00 ff fe 54 70 73 69 47 da
001a0 7f bc 72 60 29 bd 17 51 0d 10 54 70 29 bc 17 51
001b0 0d 10 79 60 00 38 47 16 7f bc 72 60 7f bc 72 50
001c0 7f bc 72 40 7f bc 72 30 79 00 ff fe 54 70 73 69
001d0 47 0c 29 bd 17 51 7f bc 72 60 0d 10 54 70 79 00
001e0 ff ff 54 70 5e 00 0e 0c 0f 86 0d 1d 19 55 1b 5d
001f0 0d d4 40 26 55 84 0d 0d 68 e8 a8 0d 47 20 0d dd
*/