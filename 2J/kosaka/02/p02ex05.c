/***  p02ex05.c  ***/
/***  s12083  2J18  �ܖ����S  ***/

#include <stdio.h>

int main()
{
	int x,y1,y2,y3;
	printf("x y1 y2 y3\n");
	for(x=0;x<100;x++){
		y1=x/2;
		y2=x/3;
		y3=x/4;
		printf("%3d %3d %3d %3d\n",x,y1,y2,y3);
	}

	return 0;
}


/**************** ���s���� *****************
x y1 y2 y3
  0   0   0   0
  1   0   0   0
  2   1   0   0
  3   1   1   0
  4   2   1   1
  5   2   1   1
  6   3   2   1
  7   3   2   1
  8   4   2   2
  9   4   3   2
 10   5   3   2
 11   5   3   2
 12   6   4   3
 13   6   4   3
 14   7   4   3
 15   7   5   3
 16   8   5   4
 17   8   5   4
 18   9   6   4
 19   9   6   4
 20  10   6   5
 21  10   7   5
 22  11   7   5
 23  11   7   5
 24  12   8   6
 25  12   8   6
 26  13   8   6
 27  13   9   6
 28  14   9   7
 29  14   9   7
 30  15  10   7
 31  15  10   7
 32  16  10   8
 33  16  11   8
 34  17  11   8
 35  17  11   8
 36  18  12   9
 37  18  12   9
 38  19  12   9
 39  19  13   9
 40  20  13  10
 41  20  13  10
 42  21  14  10
 43  21  14  10
 44  22  14  11
 45  22  15  11
 46  23  15  11
 47  23  15  11
 48  24  16  12
 49  24  16  12
 50  25  16  12
 51  25  17  12
 52  26  17  13
 53  26  17  13
 54  27  18  13
 55  27  18  13
 56  28  18  14
 57  28  19  14
 58  29  19  14
 59  29  19  14
 60  30  20  15
 61  30  20  15
 62  31  20  15
 63  31  21  15
 64  32  21  16
 65  32  21  16
 66  33  22  16
 67  33  22  16
 68  34  22  17
 69  34  23  17
 70  35  23  17
 71  35  23  17
 72  36  24  18
 73  36  24  18
 74  37  24  18
 75  37  25  18
 76  38  25  19
 77  38  25  19
 78  39  26  19
 79  39  26  19
 80  40  26  20
 81  40  27  20
 82  41  27  20
 83  41  27  20
 84  42  28  21
 85  42  28  21
 86  43  28  21
 87  43  29  21
 88  44  29  22
 89  44  29  22
 90  45  30  22
 91  45  30  22
 92  46  30  23
 93  46  31  23
 94  47  31  23
 95  47  31  23
 96  48  32  24
 97  48  32  24
 98  49  32  24
 99  49  33  24

*******************************************/