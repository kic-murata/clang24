#include<stdio.h>
main()
{
	int b[5][5] = { {3,6,9,12,15},{18,21,24,27,30}
				,{33,36,39,42,45},{48,51,54,57,60}
				,{63,66,69,72,75} };
	int c[5][5], i;
	for (i = 0 ; i < 25 ; i++) {
		c[i/5][i%5] = b[i/5][i%5];
		printf("%3d", c[i/5][i%5]);
		if (i % 5 == 4) {
			printf("\n");
		}
	}
}