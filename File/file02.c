#include<stdio.h>
main()
{
	//�t�@�C���|�C���^�̐錾
	FILE* fp;
	//������i�[�p�̕����^�z��
	char str[256];
	int lv, hp;
	//file02.txt�Ƃ����t�@�C����ǂݎ�胂�[�h�ŊJ��
	fp = fopen("file02.txt", "r");
	//�t�@�C�����當�����ǂݍ���
	fscanf(fp, "%s", str);
	//�ǂݎ�����������\��
	printf("�����F%s\n", str);
	fscanf(fp, "%s", str);
	printf("�����F%s\n", str);
	fscanf(fp, "%s", str);
	printf("�����F%s\n", str);
	//�󔒋�؂�̃f�[�^�i�����l�E�����l�E������j��ǂݎ��
	fscanf(fp, "%d%d%s", &lv, &hp, str);
	//�ǂݎ�����l��\��
	printf("lv:%d hp:%d ����:%s\n", lv, hp, str);
	fclose(fp);
}