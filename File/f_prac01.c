#include<stdio.h>
main()
{
	//�ϐ��錾
	int score = 0;
	char ch, name[20];
	FILE* fp;
	//�v���C���[���̓���
	printf("�v���C���[�̖��O�F");
	scanf("%s", name);
	//�X�R�A���Z�����i�������[�v�j
	while (1) {
		printf("���݂̃X�R�A:%d ('e'�ŏI��)\n", score);
		//�L�[���͑҂�
		ch = getch();
		//'e'�̃L�[�����͂��ꂽ�Ƃ����[�v���甲����
		if (ch == 'e') {
			break;
		}
		//�X�R�A���Z
		score++;
	}
	// �t�@�C���������ݏ���
	//�@�t�@�C���̃I�[�v��
	if (fp = fopen("score.txt", "w")) {
		//�A�t�@�C���ւ�name��score�̏�������
		fprintf(fp, "%s\n%d\n", name, score);
		//�B�t�@�C���̃N���[�Y
		fclose(fp);
	}
	else {
		//�t�@�C�����J���Ȃ��Ƃ���fp��NULL�ɂȂ�̂ŃG���[��\��
		printf("�t�@�C���I�[�v���G���[\n");
		//�����I��
		return;
	}
}