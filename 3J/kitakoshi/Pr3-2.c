#include <stdio.h>
#include <string.h>
#define BF 1
#define KMP 1
#define BM 1
#define TEXT_LENGTH 64
#define PATN_LENGTH 256
int next[PATN_LENGTH];
/* �e�L�X�g�ƃp�^�[���̕s��v�����������Ƃ��ɂǂꂾ�����炷���������\ */
int skip[PATN_LENGTH];

#define uchar unsigned char
#define max(a,b) ((a)>(b)?a:b) /* ��̐�a,b�̂����傫������Ԃ��}�N�� */

/* ������text���當����pattern����������(�͂܂����@) */
int brute_force_search(char text[], char pattern[])
{
	int i=0,j=0;
	int i1,cnt=0;
	int text_len,patn_len;
	text_len=strlen(text);
	patn_len=strlen(pattern);
	while(i<text_len && j<patn_len){
		printf("%c",pattern[j]);
		if(text[i] == pattern[j]){
			i++;
			j++;
		}else{
			printf(" ...failure\n");
			cnt++;
			for(i1=0;i1<cnt;i1++) printf(" ");
			i=i-j+1;
			j=0;
		}
	}
	if(j==patn_len){
		printf(" ...success\n");
		return i-j;
	}else{
		return -1;
	}
}

/* ���炵�\���쐬���� */
void init_next(char pattern[])
{
	int j,k,m;
	int patn_len=strlen(pattern);
	for ( j = 0; j < patn_len; j++ ) {
		if ( j < 1 )
			next[j] = 1;
		else {
			for ( k = 1; k < j; k++ ) {
				for ( m = k; m < j && pattern[m] == pattern[m-k]; m++ ) ;
				if ( m == j )
					break;
			}
			next[j] = k;
		}
	}
	for(j=0;j<patn_len;j++){
		printf("%c: next[ %d] =  %d\n",pattern[j],j,next[j]);
	}
}

/* ������text���當����pattern����������(KMP�@) */
int kmp_search(char text[], char pattern[])
{
	int i=0,j=0;
	int i1;
	int cnt=0;
	int text_len,patn_len;
	text_len=strlen(text);
	patn_len=strlen(pattern);
	while(i<text_len && j< patn_len){
		printf("%c",pattern[j]);
		if(text[i] == pattern[j]){
			i++;
			j++;
		}else{
			printf(" ...failure\n");
			cnt++;
			
			j-=next[j];
			if(j<0){
				i++;
				j++;
			}
			for(i1=0;i1<i;i1++){
				printf(" ");
			}
		}
	}
	if(j==patn_len){
		printf(" ...success\n");
		return i-j;
	}else{
		return -1;
	}
}



/* BM�@�p�̂��炵�\���쐬���� */
void init_skip(uchar pattern[])
{
	int i,patn_len=strlen(pattern);

	for( i = 0; i < 256; i++ )
		skip[i] = patn_len;
	for( i = 0; i < patn_len; i++ )
		skip[pattern[i]] = patn_len - i - 1;
}


/* ������text���當����pattern����������(BM�@) */
int bm_search(uchar text[], uchar pattern[]) 
{
	int i; /* ���ڂ��Ă���e�L�X�g�̈ʒu */
	int j; /* ���ڂ��Ă���p�^�[���̈ʒu */
	int k;
	int text_len, patn_len;

	int aaa=0;

	text_len = strlen(text);    /* �e�L�X�g�̒������Z�b�g */
	patn_len = strlen(pattern); /* �p�^�[���̒������Z�b�g */

	//i�Ƀe�L�X�g�̍ŏ��̒��ڈʒu���Z�b�g
	i=patn_len-1;

	while( i < text_len ) {
		//j�Ƀp�^�[���̍ŏ��̒��ڈʒu���Z�b�g
		j=patn_len-1;
		for(k=0;k<i;k++){
			printf(">");
		}
		printf("%c",pattern[j]);
		//while( �e�L�X�g�ƃp�^�[�����P������r ) {
		while(text[i] == pattern[j]){
			//���ׂĂ̕�������v������
			//   �p�^�[�������������ʒu��Ԃ�
			//�e�L�X�g�̈ʒu���P�����߂�
			//�p�^�[���̈ʒu���P�����߂�
			if(j==0){
				printf(" ...success\n");
				return i;
			}
			i--;
			j--;
			printf("\n");
			for(k=0;k<i;k++) printf(" ");
			printf("%c",pattern[j]);
			aaa=1;
		}
		printf(" ...failure\n");
		//�e�L�X�g�̒��ړ_(i)���C�s��v�ɂȂ��������ɉ��������ʂ������炷
//		if(aaa==1){
//		i+=(skip[pattern[j]]>1)?skip[pattern[j]]+1:1;
/*		aaa=0;
		}else{
		i+=skip[pattern[j-1]]+1;
		}
		
*/
		i+= skip[text[i]]<patn_len-j ? patn_len-j : skip[text[i]];

	}
	//-1��Ԃ�
	return -1;


	}


	int main(void)
	{
		uchar text[TEXT_LENGTH+1];
		uchar pattern[PATN_LENGTH+1];
		int position;
		int i;
		strcpy(text,"aabbabcabc");
		strcpy(pattern,"abcab");

#if BF
		printf("--- B F ---\n");
		printf("%s\n",text);
		position = brute_force_search(text, pattern);
		printf("position=%d\n",position);
#endif

#if KMP
		printf("--- KMP ---\n");
		init_next(pattern);
		printf("%s\n",text);
		position = kmp_search(text, pattern);
		printf("position=%d\n",position);
#endif


#if BM
		printf("--- B M ---\n");
		init_skip(pattern);
		for(i=0;i<strlen(pattern);i++){
			printf("%c: skip[%3d] = %d\n",pattern[i],pattern[i],skip[pattern[i]]);
		}
		printf("%s\n",text);
		position = bm_search(text, pattern);
		printf("position=%d\n",position);
#endif

		strcpy(text,"pyokopyokomipyokopyokomepyokopyokopyokopyokomupyokopyoko");
		strcpy(pattern,"pyokopyokomu");

#if BF
		printf("--- B F ---\n");
		printf("%s\n",text);
		position = brute_force_search(text, pattern);
		printf("position=%d\n",position);
#endif

#if KMP
		printf("--- KMP ---\n");
		init_next(pattern);
		printf("%s\n",text);
		position = kmp_search(text, pattern);
		printf("position=%d\n",position);
#endif


#if BM
		printf("--- B M ---\n");
		init_skip(pattern);
		for(i=0;i<strlen(pattern);i++){
			printf("%c: skip[%3d] = %d\n",pattern[i],pattern[i],skip[pattern[i]]);
		}
		printf("%s\n",text);
		position = bm_search(text, pattern);
		printf("position=%d\n",position);
#endif


		return 0;
	}