#include <stdio.h>
#include <string.h>
#define BF 1
#define KMP 1
#define TEXT_LENGTH 64
#define PATN_LENGTH 16
int next[PATN_LENGTH];

/* •¶š—ñtext‚©‚ç•¶š—ñpattern‚ğŒŸõ‚·‚é(—Í‚Ü‚©‚¹–@) */
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

/* ‚¸‚ç‚µ•\‚ğì¬‚·‚é */
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

/* •¶š—ñtext‚©‚ç•¶š—ñpattern‚ğŒŸõ‚·‚é(KMP–@) */
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

int main(void)
{
	int i;
	char text[TEXT_LENGTH+1];
	char pattern[PATN_LENGTH+1];
	int position;
	strcpy(text,"xxxtartartayx");
	strcpy(pattern,"tartay");

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

	printf("\n");

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

	return 0;
}
