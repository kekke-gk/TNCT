/* �i�b�v�U�b�N���i���I�v��@�ɂ���@�j */

#include<stdio.h>
#include<stdlib.h>

/* �z��size�Avalue�͂��ꂼ��ו��̑傫���Ɖ��l��\�킵�Ă���
 * �����Y�������m���Ή����Ă���(��F�ו�0�̑傫����size[0]�A���l��value[0]�j�B
 */

/* �ו��̑傫�� */
int size[] = {2, 3, 5, 7, 9, 15};

/* �ו��̉��l */
int value[] = {2, 4, 7, 11, 14, 24};

/* �ו��̎�ނ̐� */
#define AS (sizeof(size)/sizeof(size[0]))

/* �i�b�v�U�b�N�̑傫���̏�� */
#define MAX_M   200

void DynamicProgramming(int N, int Nsize[], int Nvalue[]){
	int i,j;

	/* �����_�Ńi�b�v�U�b�N�ɋl�ߍ��񂾉ו��̉��l�̍��v */
	int total[MAX_M];

	/* �Ō�ɑI�񂾉ו� */
	int choice[MAX_M];

	/* �ו�i����ꂽ���̉��l�̍��v */
	int repack_total;

	/* �z����N���A���Ă��� */
	for(i=0;i<=N;i++){
		total[i] = 0;
		choice[i] = -1;
	}

	/* �ו� i = 0?AS �܂ł��l���ɓ���� */
	for(i=0;i<AS;i++){
		/* �傫��j(=Nsize[i])�̃i�b�v�U�b�N�ɑ΂��āA�ו����l�ߍ���ł݂� */
			/* �����ו�i����ꂽ�Ƃ���ƁA���l�̍��v�͂�����ɂȂ邩���v�Z���āA�ϐ�repack_total�Ɋi�[ */
			/* �ו�i����ꂽ����(����Ȃ����)���l���傫���Ȃ�̂Ȃ�A�ו�i������ */
		/* �z��total�Achoice�̒��g��\������ */

        for(j = 0; j <= N; j++){
			repack_total = 0;
				
			if( j < Nsize[i]) continue;

			repack_total = total[j - Nsize[i]] + Nvalue[i];

			if(total[j] < repack_total){
				total[j] = repack_total;
				choice[j] = i;
			}
		}

		printf("i = %d\n",i);
		printf("total  = ");
		for(j=0;j<=N;j++){
			printf("%2d ",total[j]);
		}
		printf("\n");
		printf("choice = ");
		for(j=0;j<=N;j++){
			printf("%2d ",choice[j]);
		}
		printf("\n");
	}

	/* �ǂ̉ו����i�b�v�U�b�N�ɓ��ꂽ����\������ */
	for(i = N; choice[i] != -1; i -= Nsize[choice[i]]){
		printf("�ו� %d (���l%2d)���l�ߍ���\n", choice[i], Nvalue[choice[i]]);
	}
	printf("���l�̍��v = %d",total[N]);
}

int main(int argc, char *argv[]){
	/* �i�b�v�U�b�N�̑傫�� */
	int m;

	/* �����̐�������Ă��Ȃ����A�i�b�v�U�b�N�̑傫��������𒴂��Ă��Ȃ���
	 * ����i�K�؂Ȉ����̐��A�������͒l���ݒ肳��Ă��Ȃ��ꍇ�A�ēx���͂����߂�j
	 */
	if(argc != 2){
		printf("usage : filename num\n");
		return 0;
	}

	/* �R�}���h��������i�b�v�U�b�N�̑傫���𓾂� */
	m = atoi(argv[1]);

	if(m < 0 || MAX_M <= m){
		printf("Not valid number. Please input 0-199\n");
		return 0;
	}
	printf("Size of knapsack is %d\n",m);

	DynamicProgramming(m,size,value);

	return 0;
}
