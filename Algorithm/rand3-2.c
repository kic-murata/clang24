#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int k, atk; //k=1�`100 atk=-5�`+5
	int i= 1, hp = 200;
	srand(time(0));
	while (hp >= 0) {
		printf("�^�[��%d:", i++);
		k = rand() % 100 + 1;
		atk = 20 + (rand() % 11 - 5);
		if (k <= 30) {
			printf("��������̈ꌂ!\n");
			printf("�_���[�W�F%d", 2 * atk);
			hp -= atk * 2;
		}
		else {
			printf("�ʏ�U��\n");
			printf("�_���[�W�F%d", atk);
			hp -= atk;
		}
		printf("(�c��hp:%d)\n\n", hp);
	}
	printf("�G��|�����I\n");
}