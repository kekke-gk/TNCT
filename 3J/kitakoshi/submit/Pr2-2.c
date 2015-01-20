#include <stdio.h>
#include <string.h>
#define BF 1
#define KMP 1
#define TEXT_LENGTH 64
#define PATN_LENGTH 16
int next[PATN_LENGTH];

void printBlank(int count) {
	int i;
	for (i = 0; i < count; i++) {
		printf(" ");
	}
}

void printNext(char pattern[], int patn_len) {
	int i;
	for (i = 0; i < patn_len; i++) {
		printf("%c: next[%2d] =  %d\n", pattern[i], i, next[i]);
	}
}

/* 文字列textから文字列patternを検索する(力まかせ法) */
int brute_force_search(char text[], char pattern[])
{
	int i = 0  /* 注目しているテキストの位置 */
	  , j = 0  /* 注目しているパターンの位置 */
	;
	int text_len
	  , patn_len
	;
	text_len = strlen(text);    /* テキストの長さをセット */
	patn_len = strlen(pattern); /* パターンの長さをセット */
	while ( i < text_len && j < patn_len ) {
		if ( text[i] == pattern[j] ) {
			printf("%c", pattern[j]);
			i++;
			j++;
		} else {
			printf("%c ...failure\n", pattern[j]);
			i = i - j+1;
			j = 0;
			printBlank(i);
		}
	}
	if ( j == patn_len ) {
		printf(" ...success\n");
		return i - patn_len;
	}
	else
		return -1;
}

/* ずらし表を作成する */
void init_next(char pattern[])
{
	int patn_len
	  , j
	  , k
	  , m
	;
	patn_len = strlen(pattern); /* パターンの長さをセット */
	for ( j = 0; j < patn_len; j++ ) {
		if ( j < 1 )
			next[j] = 1;
		else {
			for ( k = 1; k < j; k++ ) {
				for ( m = k; m < j && pattern[m] == pattern[m-k]; m++ );
				if ( m == j )
					break;
			}
			next[j] = k;
		}
	}
}

/* 文字列textから文字列patternを検索する(KMP法) */
int kmp_search(char text[], char pattern[])
{
	int i = 0  /* 注目しているテキストの位置 */
	  , j = 0  /* 注目しているパターンの位置 */
	;
	int text_len
	  , patn_len
	;
	text_len = strlen(text);    /* テキストの長さをセット */
	patn_len = strlen(pattern); /* パターンの長さをセット */
	
	/* テキストの最後尾に行き当たるか、パターンが見つかるまで繰り返す */
	while ( i < text_len && j < patn_len ) {
		if ( text[i] == pattern[j] ) {
			printf("%c", pattern[j]);
			i++;
			j++;
		} else {
			printf("%c ...failure\n", pattern[j]);
			j -= next[j];
			if ( j < 0 ) {
				i++;
				j++;
			}
			printBlank(i);
		}
	}
	if ( j == patn_len ) {
		printf(" ...success\n");
		return i - patn_len;
	}
	else
		return -1;
}

void callTextSearch(char text[], char pattern[]) {
	int position
	  , patn_len
	;

	patn_len = strlen(pattern); /* パターンの長さをセット */

#if BF
	printf("--- B F ---\n");
	printf("%s\n",text);
	position = brute_force_search(text, pattern);
	printf("position=%d\n",position);
#endif

#if KMP
	printf("--- KMP ---\n");
	init_next(pattern);
	printNext(pattern, patn_len);
	printf("%s\n",text);
	position = kmp_search(text, pattern);
	printf("position=%d\n",position);
#endif

}

int main(void)
{
	char text[TEXT_LENGTH+1];
	char pattern[PATN_LENGTH+1];

	strcpy(text,"xxxtartartayx");
	strcpy(pattern,"tartay");
	callTextSearch(text, pattern);

	strcpy(text,"pyokopyokomipyokopyokomepyokopyokopyokopyokomupyokopyoko");
	strcpy(pattern,"pyokopyokomu");
	callTextSearch(text, pattern);

	return 0;
}