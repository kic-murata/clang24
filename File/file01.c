#include<stdio.h>
main()
{
	//�t�@�C���|�C���^�̐錾
	FILE* fp;
	int a = 10, b = 20;
	//file01.txt�Ƃ����t�@�C�����ŏ������݃��[�h�ŊJ��
	fp = fopen("file01.txt", "w");
	//������̏�������
	fprintf(fp, "KOBEDENSHI\n");
	//�ϊ��w��q���g������������
	fprintf(fp, "%d+%d=%d\n", a, b, a + b);
	//�t�@�C�������
	fclose(fp);
}