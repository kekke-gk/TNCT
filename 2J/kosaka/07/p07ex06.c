/***  p07ex06.c  ***/
/***  s12083  1320  五味京祐  ***/

#include <stdio.h>
#include <string.h>

typedef struct{
	int count;
	char s[50];
}str_t;

int main()
{
	FILE *fin,*fout;
	char inname[100],outname[100],ch[100],tmp[50];
//inwは直前に読み込んだ文字がどうだっかか記憶しておく変数
	int inw=1,i=0,count=0,j,k,check=0,check2=0;
	str_t str[50];
	
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			str[i].s[j]=0;
		}
		str[i].count=0;
	}
	i=0;
	
	printf("入力ファイル名を入力してください。");
	gets(inname);
	printf("出力ファイル名を入力してください。");
	gets(outname);
	
	fin=fopen(inname,"r");
	if(fin==NULL){
		printf("can't open %s\n",inname);
		exit(1);
	}
	fout=fopen(outname,"w");

	while(1){
		ch[i]=fgetc(fin);
		if(ch[i]==EOF) break;
//直前に有効な文字を読み込んでいて，読み込んだ文字がアンバーバーまたは英数字
//直前に有効な文字を読み込んでいないで，今読み込んだ文字がローマ字だったら
		if( ((isalnum(ch[i])!=0 || ch[i]=='_')&&inw==0) || (isalnum(ch[i])!=0 && inw==1 && (ch[i]<'0' || '9'<ch[i])) ){
			inw=0;
			i++;
		}else{
//inwが０で上の条件にあてはまらなかったということは，有効な文字の直後に有効ではない文字が入力されたということだから
			if(inw==0){
				for(j=0;j<count;j++){
					if(!str[j].s[0]) break;
					check=0;
					for(k=0;k<i;k++){
						if(str[j].s[k] != ch[k]){
							check=1;
							break;
						}
					}
					if(!check){
						str[j].count++;
						break;
					}
				}
				
				if(check){
					strcpy(str[count].s,ch);
					count++;
				}
			}
			inw=1;
			i=0;
		}
		//i++;
	}
	
	for(i=0;i<count;i++){
		printf("%s %d\n",str[i].s,str[i].count);
		//fprintf(fout,"%s %d\n",str[i].s,str[i].count);
	}
	
	return 0;
}

/**************** 実行結果 *****************


*******************************************/
