#include<stdio.h>
main()
{
	float box[3], sum = 0;
	int i;
	for (i = 0; i < 3; i++) {
		printf("���������:");
		scanf("%f", &box[i]);
		sum += box[i];
	}
	printf("���v�F%.2f\n ���ρF%.2f\n"
						, sum, sum / 3);

}