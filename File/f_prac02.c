#include<stdio.h>
main()
{
	//max_score�F�t�@�C������ǂݎ�����X�R�A���i�[
	int max_score, score = 0;
	//max_name:�t�@�C������ǂݎ�����v���C���[�����i�[
	char max_name[20], ch, name[20];
	FILE* fp;
	//�X�R�A�t�@�C����ǂݎ�胂�[�h�ŊJ��
	if (fp = fopen("score.txt", "r")) {
		fscanf(fp, "%s%d", max_name, &max_score);
		fclose(fp);
		printf("�ō����_�@���O�F%s �X�R�A�F%d\n", max_name, max_score);
	}
	else {
		//�J���t�@�C�����Ȃ��ꍇ�Afp��NULL�ɂȂ�̂ŃG���[��\��
		printf("�t�@�C�����ǂ߂܂���!\n");
		//�����I��
		return;
	}

	printf("�v���C���[������́F");
	scanf("%s", name);
	while (1) {
		printf("���݂̃X�R�A:%d ('e'�ŏI��)\n", score);
		ch = getch();
		if (ch == 'e') {
			break;
		}
		score++;
	}
	if (score > max_score) {
		fp = fopen("score.txt", "w");
		fprintf(fp, "%s\n%d\n", name, score);
		fclose(fp);
		printf("�n�C�X�R�A�X�V�I\n");
	}
}