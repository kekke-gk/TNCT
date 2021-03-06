#include <3048fone.h>
#include "h8_3048fone.h"

void dump(unsigned long int start, unsigned int num){
	unsigned long int i,ad;
	unsigned int j;
	
	SCI1_printf("memory dump 0x%05lx-0x%05lx\n",start,start+num-1);
	SCI1_printf("     ");
	for(j=0;j<16;j++){
		SCI1_printf(" +%X",j);
	}
	SCI1_printf("\n");
	for(i=start;i<start+num;i+=16){
		SCI1_printf("%05lx",i);
		for(j=0;j<16;j++){
			ad=i+j;
			SCI1_printf(" %02x",*(unsigned char *)ad);
		}
		SCI1_printf("\n");
	}
}

main()
{
	unsigned long int ad;
	initSCI1(); /*SCI-ch1の初期化*/
	
	while(1){
		ad = SCI1_getInt4("start address (0xnnnnn) =");
		dump(ad,256);
	}
}

/* 実行結果
start address (0xnnnnn) =0x400
memory dump 0x00400-0x004ff
      +0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +A +B +C +D +E +F
00400 00 10 0f 86 5e 00 02 46 79 01 00 10 0f f0 5e 00
00410 01 e4 0f f0 5e 00 03 28 7a 17 00 00 00 10 01 00
00420 6d 76 54 70 01 00 6d f6 7a 37 00 00 00 10 0f 86
00430 55 38 79 01 00 10 0f f0 5e 00 02 e2 0f f0 5e 00
00440 03 28 7a 17 00 00 00 10 01 00 6d 76 54 70 6d f6
00450 0c 86 a6 0a 46 04 f8 0d 55 f4 28 b4 73 78 47 fa
00460 36 b3 7f b4 72 70 6d 76 54 70 01 00 6d f6 0f 86
00470 40 06 68 68 55 d8 0b 76 68 68 46 f6 01 00 6d 76
00480 54 70 19 11 40 0a 79 08 10 68 1b 58 46 fc 0b 51
00490 1d 01 45 f2 54 70 19 11 40 0a 79 08 00 04 1b 58
004a0 46 fc 0b 51 1d 01 45 f2 54 70 0c 80 28 c6 e8 f0
004b0 14 08 38 c6 7f c6 70 50 79 00 00 05 55 d8 7f c6
004c0 72 50 79 00 00 28 40 ce 6d f6 0c 8e 11 88 11 88
004d0 11 88 11 88 e8 0f 55 d2 ee 0f 0c e8 55 cc 6d 76
004e0 54 70 6d f6 0c 8e 7f c6 70 40 11 88 11 88 11 88
004f0 11 88 e8 0f 55 b4 ee 0f 0c e8 55 ae 7f c6 72 40
start address (0xnnnnn) =0xffe00
memory dump 0xffe00-0xffeff
      +0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +A +B +C +D +E +F
ffe00 f7 ff ff ff ff df ff 7f ff bf ff ff ff ff ff ff
ffe10 bf ff ff ff be e7 ff ff ff ff ff ff ff bf fd bf
ffe20 ff ff ff ff b3 ff f7 f7 ff fe fc ff ff 7f fd ef
ffe30 f7 fe ff ff ff d7 ff ef ff ff ef ff df ff ff f5
ffe40 9f ff ff bf ef ff ee fd ff fd ff ff fd f7 7f ff
ffe50 fb ff ff fe ff ff ff ff ff ff df ff df ff fb d5
ffe60 ef ff ff ff ff ff ef ff ff ff ff ff fb fe ff ff
ffe70 fe fe fe a4 0a f4 fe a8 fe aa 00 00 02 52 00 0f
ffe80 00 f4 00 00 0a b4 00 0f fe a9 ff fb ff ff fe ff
ffe90 eb 7f ff ff ff ff ff df ff ef ff e5 ff ff 5f 7f
ffea0 66 66 65 66 66 66 65 61 30 33 33 00 00 0f fe f2
ffeb0 fe 0f fe ab 00 00 0e f4 30 00 00 00 02 46 00 2b
ffec0 00 10 00 00 02 2a 00 00 05 ee 00 00 00 00 00 0f
ffed0 00 00 00 0f 00 00 00 0f fe d0 00 00 00 04 00 00
ffee0 00 6a 00 0f fe f2 00 00 00 08 00 00 0d 92 00 00
ffef0 00 ef 00 00 00 00 00 00 00 00 00 00 00 00 00 00
start address (0xnnnnn) =0xfff00
memory dump 0xfff00-0xfffff
      +0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +A +B +C +D +E +F
fff00 00 00 00 00 00 00 00 00 00 00 0d d2 00 00 01 56
fff10 ff ff ff ff ff ff ff ff ff ff ff ff 7f 00 00 00
fff20 ff ff ff ff 09 ff ff 00 ff ff ff ff e5 ff ff 00
fff30 ff ff ff ff 61 ff ff 00 ff ff ff ff a9 ff ff 00
fff40 00 00 00 00 00 00 ff f0 00 ff ff 00 00 00 00 00
fff50 ff 00 ff ff ff ff ff ff ff ff ff ff fe fc 40 0f
fff60 e0 e0 80 c0 80 88 f8 f8 00 00 ff ff ff ff 80 88
fff70 f8 f8 00 00 ff ff ff ff 80 88 f8 f8 00 00 ff ff
fff80 ff ff 80 88 f8 f8 00 00 ff ff ff ff ff ff ff ff
fff90 ff ff 80 88 f8 f8 00 00 ff ff ff ff ff ff ff ff
fffa0 f0 ff 00 00 00 00 ff ff 18 00 ff 3f 02 07 00 ff
fffb0 00 ff 00 ff 84 00 f2 da 00 13 30 30 40 0a f2 ec
fffc0 ff ff ff ff ff ff ff ff ff ff fc fb ff ff ff ff
fffd0 ff ff ff ff ff ff ff ff 00 ff 00 f0 00 00 1f 1f
fffe0 00 00 00 00 00 00 00 00 00 7e ff ff ff ff f3 ff
ffff0 ff c7 0b fe 00 00 0f ff 00 00 ff ff ff ff ff ff
start address (0xnnnnn) =
*/