#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int k;
	srand(time(0));
	k = rand() % (100 - 1 + 1) + 1;
	if (k <= 30) {
		printf("��������̂�������!%d\n",k);
	}
	else {
		printf("�ʏ�U��\n");
	}
}