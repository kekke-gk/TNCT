#include <stdio.h>
#include <string.h>

#define MAX_STATION 10                  /* �ő�̉w�̐� */
#define ERROR    NULL

typedef struct Station {
	char name[20+1];                /* �w���͍ő�S�p10�����܂� */
	int  time;                      /* �O�̉w����̏��v���� */
	struct Station *next_addr;      /* ���̃f�[�^�̃A�h���X */
} STATION;

int station_num = 0;                    /* �t�@�C������ǂݍ��񂾉w�̐� */
STATION station[MAX_STATION];           /* ���l�̓��͗p�z�� */
STATION head;

int get_num(void) {
	int  i;
	int  d = 0;
	int  c = 0;
	rewind(stdin);
	for( i = 0; i < 5 && c != '\n' ; i++ ) { /* 5�P�^�܂� */
		c = getchar();
		if ( c == '\n' ) break;
		if(c < '0' || '9' < c) break;
		d = d * 10 + c - '0';
	}
	rewind(stdin);
	return d;
}

int get_data_num(void){
	STATION *tmp=head.next_addr;
	int cnt;
	for(cnt=1;tmp->next_addr!=NULL;cnt++){
		tmp=tmp->next_addr;
	}
	return cnt;
}

/* �f�[�^�t�@�C���̓ǂݍ��� */
int read_data(void)
{
	FILE *fp;
	int i;
	/* �L�����N�^�f�[�^�ǂݍ��� */
	//fp = station_data.txt�̓ǂݍ���
	fp=fopen("station_data.txt","r");
		if ( fp == NULL ){
			fprintf(stderr,"CANNOT OPEN station_data.txt\n");
			return -1;
		}
	for( i = 0; i < MAX_STATION; i++, station_num++ ) {
		if ( fscanf(fp,"%s\t%d",station[i].name,&station[i].time) != 2 ) break;
		/* �܂��͓ǂݍ��񂾏��Ƀ��X�g���Ȃ� */
		station[i].next_addr = &station[i+1];
	}
	fclose(fp);
	/* ���X�g�̐擪��head.next_addr�ɃZ�b�g */
	head.next_addr = &station[0];
	/* ���X�g�̍Ō��NULL�����Ă��� */
	station[station_num-1].next_addr = NULL;
	return 0;
}

/* �H���f�[�^��\�� */
void station_disp(void)
{
	STATION *current_addr;
	current_addr = head.next_addr;

	while(1){
		printf("|ADDR:%20d|\n",current_addr);
		printf("|NAME:%20s|\n",current_addr->name);
		printf("|TIME:%20d|\n",current_addr->time);
		printf("|NEXT:%20d|\n",current_addr->next_addr);
		printf("\n");
		if(current_addr->next_addr == NULL)
			break;
		/* current_addr���X�V */
		current_addr=current_addr->next_addr;
	}
}

/* ���͂��ꂽ�w�����X�g�ɑ��݂��Ă��邩�ǂ����̃`�F�b�N */
STATION *check(char target[])
{
	/* ���X�g�����ǂ��Ďw�肳�ꂽ�w���܂܂�Ă��邩�ǂ����m�F */
	STATION *current_addr;
	current_addr = head.next_addr;
	while(1){
		if( strcmp(target,current_addr->name)==0 )
			return current_addr;
		if(current_addr->next_addr == NULL)
			break;
		current_addr = current_addr->next_addr;
	}
	return ERROR;
}

/* �f�[�^�̒ǉ� */
void add(void)
{
	STATION *current_addr;
	char stationName[16];
	char targetChar[16];    // �ǉ�����w�̒��O�̉w�����i�[
	int a_point; /* �z��Ƃ��Ă̒ǉ��ʒu */
	int i;    /* �����I�ɂ͍Ō�ɒǉ����� */

	if(get_data_num() == MAX_STATION){
		printf("�w�̐�������ł��D\n");
		return;
	}
	a_point = station_num++;
	//a_point = get_data_num();
	printf("NAME = ");
	//fgets(station[a_point].name,16,stdin);
	fgets(stationName,16,stdin);
	//for( i=0; station[a_point].name[i] != '\n' && i != 15; i++ );
	for( i=0; stationName[i] != '\n' && i != 15; i++ );
	//station[a_point].name[i] = '\0';
   stationName[i]  = '\0';

   if(check(stationName)!=NULL){
	   printf("���łɑ��݂���w���ł��D\n");
	   return;
   }

   strcpy(station[a_point].name,stationName);


	/* �������s�R�[�h���폜���邽�߂̏��� */
	printf("TIME = ");
	station[a_point].time = get_num();
	station_disp();
	do{
		printf("�ǂ̉w�̌�ɒǉ����܂���?\nNAME = ");
		fgets(targetChar,16,stdin);
		for( i=0; targetChar[i] != '\n' && i != 15; i++ );
		targetChar[i] = '\0';
		/* �����s�R�[�h���폜���邽�߂̏��� */
	} while( check(targetChar) == ERROR );
	current_addr=check(targetChar);
	/* �f�[�^�̒ǉ��i���X�g���Ȃ��j */
	station[a_point].next_addr=current_addr->next_addr;
	current_addr->next_addr=&station[a_point];
	station_disp();
}

/* �f�[�^�̍폜 */
void del(void)
{
	int i;
	STATION *forDel=NULL; // �폜�������v�f���i�[����|�C���^
	STATION *current_addr;
	char targetChar[16];

	station_disp();
	if(get_data_num()==1){
		printf("�w�̐�����Ȃ̂ō폜�ł��܂���\n");
		return;
	}
	do{
		printf("�ǂ̉w���폜���܂���?\nNAME = ");
		fgets(targetChar,16,stdin);
		for( i=0; targetChar[i] != '\n' && i != 15; i++ );
		targetChar[i] = '\0';
		/* �����s�R�[�h���폜���邽�߂̏��� */
	} while( check(targetChar) == ERROR );
	current_addr = head.next_addr;
	/* �c��P�������炻��ȏ�����Ȃ� */
	while(1){
		if(strcmp(current_addr->name,targetChar) == 0 && current_addr == head.next_addr){
			/* �擪���폜�������ꍇ */
			head.next_addr = current_addr->next_addr;
			break;
		}

		forDel=current_addr->next_addr;
		if(forDel!=NULL && strcmp(forDel->name,targetChar)==0){
			current_addr->next_addr=forDel->next_addr;
			break;
		}
		/* �擪�ȊO���폜�������ꍇ */

		/* current_addr���X�V */
		current_addr=current_addr->next_addr;
	}
	station_disp();
}

/* ���v���Ԃ̌v�Z */
void calc(void)
{
	int sum=0, i;
	int flag=0;

	STATION *current_addr;
	char targetFrom[16],targetTo[16];


	if(get_data_num()==1){
		printf("�w�̐�����Ȃ̂ŏ��v���Ԃ̌v�Z�͕K�v����܂���D");
		return;
	}

	printf("�ǂ�����ǂ��܂ł̏��v���Ԃ��v�Z���܂����H\n");
	do{
		printf("FROM(Station Name) = ");
		fgets(targetFrom,16,stdin);
		for( i=0; targetFrom[i] != '\n' && i != 15; i++ );
		targetFrom[i] = '\0';
		/* �����s�R�[�h���폜���邽�߂̏��� */
	} while( check(targetFrom) == ERROR );
	do{
		printf("TO(Station Name) = ");
		fgets(targetTo,16,stdin);
		for( i=0; targetTo[i] != '\n' && i != 15; i++ );
		targetTo[i] = '\0';
		/* �����s�R�[�h���폜���邽�߂̏��� */
	} while( check(targetTo) == ERROR );

    if(strcmp(targetFrom,targetTo)==0){
		printf("�o������w�Ɠ�������w�������ł��D\n");
		return;
	}

	printf("%s����",targetFrom);
	printf("%s�܂łł���\n",targetTo);
	/* ���v���Ԃ��v�Z���� */
	
	current_addr=head.next_addr;
	while(current_addr != NULL){
		if(flag==1){
			sum+=current_addr->time;
		}
		if(strcmp(targetFrom,current_addr->name)==0 || strcmp(targetTo,current_addr->name)==0){
			flag++;
			if(flag==2) break;
		}
		current_addr=current_addr->next_addr;
	}

	printf("���v���Ԃ�%d�ł�\n",sum);
}

/* ���j���[ */
int menu(void)
{
	int c;
	while( 1 ){
		printf("1.�\\��\n");   // �\�Ǝ��̊Ԃ�"\"�͂��܂��Ȃ��i�O���Ƃǂ��Ȃ邩�A�����Ă݂Ă��悢
		printf("2.�ǉ�\n");
		printf("3.�폜\n");
		printf("4.���v����\n");
		printf("5.�I��\n");
		c = get_num();
		if( c >= 1 && c <= 5 )
			break;
		else
			printf("1?5�܂ł̐�������͂��Ă�������\n");
	}
	switch( c ){
		case 1:
			station_disp();
			break;
		case 2:
			add();
			break;
		case 3:
			del();
			break;
		case 4:
			calc();
			break;
		case 5:
			return 1;
	}
	return 0;
}

int main(void)
{
	int end = 0;
	end = read_data();
	while( !end ){
		end = menu();
	}
	return 0;
}
