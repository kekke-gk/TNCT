/***  p05ex01.c  ***/
/***  s12083  2J18  �ܖ����S  ***/

#include <stdio.h>
#include <math.h>

int main()
{
	double pai=3.14159265358979;
	//�u�΂̒l�� 3.14159265358973 ���g���B�v�Ə����Ă���܂������C
	//�������́C 3.14159265358979 �ł��B
	int i;
	
	printf("deg	sin		cos\n");
	for(i=0;i<91;i++){
		printf(" %2d   %.8f   %.8f\n",i,sin(i*pai/180),cos(i*pai/180));
	}
	return 0;
}


/**************** ���s���� *****************
deg     sin             cos
  0   0.00000000   1.00000000
  1   0.01745241   0.99984770
  2   0.03489950   0.99939083
  3   0.05233596   0.99862953
  4   0.06975647   0.99756405
  5   0.08715574   0.99619470
  6   0.10452846   0.99452190
  7   0.12186934   0.99254615
  8   0.13917310   0.99026807
  9   0.15643447   0.98768834
 10   0.17364818   0.98480775
 11   0.19080900   0.98162718
 12   0.20791169   0.97814760
 13   0.22495105   0.97437006
 14   0.24192190   0.97029573
 15   0.25881905   0.96592583
 16   0.27563736   0.96126170
 17   0.29237170   0.95630476
 18   0.30901699   0.95105652
 19   0.32556815   0.94551858
 20   0.34202014   0.93969262
 21   0.35836795   0.93358043
 22   0.37460659   0.92718385
 23   0.39073113   0.92050485
 24   0.40673664   0.91354546
 25   0.42261826   0.90630779
 26   0.43837115   0.89879405
 27   0.45399050   0.89100652
 28   0.46947156   0.88294759
 29   0.48480962   0.87461971
 30   0.50000000   0.86602540
 31   0.51503807   0.85716730
 32   0.52991926   0.84804810
 33   0.54463904   0.83867057
 34   0.55919290   0.82903757
 35   0.57357644   0.81915204
 36   0.58778525   0.80901699
 37   0.60181502   0.79863551
 38   0.61566148   0.78801075
 39   0.62932039   0.77714596
 40   0.64278761   0.76604444
 41   0.65605903   0.75470958
 42   0.66913061   0.74314483
 43   0.68199836   0.73135370
 44   0.69465837   0.71933980
 45   0.70710678   0.70710678
 46   0.71933980   0.69465837
 47   0.73135370   0.68199836
 48   0.74314483   0.66913061
 49   0.75470958   0.65605903
 50   0.76604444   0.64278761
 51   0.77714596   0.62932039
 52   0.78801075   0.61566148
 53   0.79863551   0.60181502
 54   0.80901699   0.58778525
 55   0.81915204   0.57357644
 56   0.82903757   0.55919290
 57   0.83867057   0.54463904
 58   0.84804810   0.52991926
 59   0.85716730   0.51503807
 60   0.86602540   0.50000000
 61   0.87461971   0.48480962
 62   0.88294759   0.46947156
 63   0.89100652   0.45399050
 64   0.89879405   0.43837115
 65   0.90630779   0.42261826
 66   0.91354546   0.40673664
 67   0.92050485   0.39073113
 68   0.92718385   0.37460659
 69   0.93358043   0.35836795
 70   0.93969262   0.34202014
 71   0.94551858   0.32556815
 72   0.95105652   0.30901699
 73   0.95630476   0.29237170
 74   0.96126170   0.27563736
 75   0.96592583   0.25881905
 76   0.97029573   0.24192190
 77   0.97437006   0.22495105
 78   0.97814760   0.20791169
 79   0.98162718   0.19080900
 80   0.98480775   0.17364818
 81   0.98768834   0.15643447
 82   0.99026807   0.13917310
 83   0.99254615   0.12186934
 84   0.99452190   0.10452846
 85   0.99619470   0.08715574
 86   0.99756405   0.06975647
 87   0.99862953   0.05233596
 88   0.99939083   0.03489950
 89   0.99984770   0.01745241
 90   1.00000000   0.00000000
*******************************************/