/**********************************************************
SCI1へ出力，WINDOWSのHyperTerminalなどで受信できる。
ただし，設定は　38400baud, Async, 8bit , NoParity, stop1
**********************************************************/
#include <3048fone.h>
#include "h8_3048fone.h"

void func1(void)
{
	unsigned char sw,previous;
	SCI1_printf("Printing 8-bitSW status...\n");
	SCI1_printf("Change 8-bitSW and new status will appear.\n");
	SCI1_printf("If any key on the keyboard, this test will quit.\n");
	previous=sw=get8BitSW();
	SCI1_printf("8-bitSW status= %2x[%08b]\n",sw,sw);
	do {
		sw=get8BitSW();
		if (sw!=previous) {
			SCI1_printf("8-bitSW status= %2x[%08b]\n",sw,sw);
			previous=sw;
		}
	} while (SCI1_chkgetChar()<0);
}

void func2(void)
{
	unsigned char sw,previous;
	SCI1_printf("Printing PushSW status...\n");
	SCI1_printf("Change PushSW and new status will appear.\n");
	SCI1_printf("If any key on the keyboard, this test will quit.\n");
	previous=sw=getPushSW();
	SCI1_printf("PushSW status= %2x[%08b]\n",sw,sw);
	do {
		sw=getPushSW();
		if (sw!=previous) {
			SCI1_printf("PushSW status= %2x[%08b]\n",sw,sw);
			previous=sw;
		}
	} while (SCI1_chkgetChar()<0);
}

void func3(void)
{
	short int x;
	long int y;
	x=SCI1_getInt("Key in a decimal number >>>");
	SCI1_printf("The number you keyed in is %d %x\n",x,x);
	x=SCI1_getInt("Key in a hexdecimal number (ex. 0x23ff) >>>");
	SCI1_printf("The number you keyed in is %d %x\n",x,x);
	y=SCI1_getInt4("Key in a decimal big number (ex. 12345678)>>>");
	SCI1_printf("The number you keyed in is %ld %lx\n",y,y);
	y=SCI1_getInt4("Key in a hexdecimal big number (ex. 0x23ff0000) >>>");
	SCI1_printf("The number you keyed in is %ld %lx\n",y,y);
}

main()
{
	int menu;
	initSCI1(); /*SCI-ch1の初期化*/
	initPushSW(); /*押しボタンスイッチの初期化*/
	init8BitSW(); /*8ビットスイッチの初期化*/
	SCI1_printf("Hello. How are you?\n");
	while (1) {
		SCI1_printf("***************menu**********\n");
		SCI1_printf("1:   get 8-bit SW and print \n");
		SCI1_printf("2:   get Push SW and print \n");
		SCI1_printf("3:   get integer from SCI1 and print \n");
		do {
			menu=SCI1_getChar(); /*menuには'1','2','3'が入るはず*/
		} while (menu<'1'||'3'<menu);
		SCI1_printf("\n");
		switch (menu) {
		case '1':
			func1();
			break;
		case '2':
			func2();
			break;
		case '3':
			func3();
			break;
		default:
			break;
		}
	}
}