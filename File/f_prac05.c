#include<stdio.h>
#define MapNum 3	//�}�b�v�̐�
#define H 5				//�}�b�v�̉������̃}�X��
#define W 10			//�}�b�v�̏c�����̃}�X��

//�}�b�v�f�[�^���Ǘ����邽�߂̍\����
typedef struct {
	int m_map[H][W];
} Map;

//�I�������}�b�v�f�[�^��z��ɃZ�b�g����֐�
void SetMap(char *filename, Map	*m);
//�}�b�v�f�[�^�\������֐�
void DrawMap(Map m);

main()
{
	//�}�b�v�̃f�[�^���Ǘ�����\���̕ϐ��̐錾
	Map MapData; 
	//�}�b�v�f�[�^�t�@�C���̈ꗗ�i�z�񉻁j
	char* MapFileName[MapNum]
		= { "map0.txt","map1.txt","map2.txt" };
	//�\������}�b�v�̔ԍ�
	int select;

	printf("�\������}�b�v��I��(0,1,2):");
	scanf("%d", &select);
	//�}�b�v�ԍ��͈̔̓`�F�b�N
	if (select >= 0 && select <= 2) {
		//�}�b�v�f�[�^�t�@�C������̓ǂݍ���
		SetMap(MapFileName[select], &MapData);
		//�}�b�v�f�[�^�̉�ʕ\��
		DrawMap(MapData);
	}
	else {
		puts("�G���[:0�`2�̒��œ��͂��Ă�������");
	}
}
//�}�b�v�f�[�^�t�@�C������ǂݍ���ō\���̂̃����o�Ƀf�[�^���i�[����
void SetMap(char* filename, Map* m) {
	FILE* fp;
	char ch;
	int i, j;
	//�t�@�C����ǂݎ�胂�[�h�ŊJ��
	if (fp = fopen(filename, "r")) {
		//H�~W�̃f�[�^�����ԂɈꕶ�����ǂݎ���Ă���
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				ch = fgetc(fp);
				//�ǂݎ�����f�[�^�𐔒l�����ă����o�ɑ��
				m->m_map[i][j] = ch-'0';
			}
			//�s���̉��s�R�[�h��ǂݔ�΂�
			fgetc(fp);
		}
		fclose(fp);
	}
}
//�}�b�v�f�[�^�����Ƃɉ�ʂɃ}�b�v��\��
void DrawMap(Map m) {
	int i, j;
	//H�~W�̃}�b�v��\������
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			if (m.m_map[i][j] == 1) {
				printf("�");
			}
			else if (m.m_map[i][j] == 0) {
				printf(" ");
			}
		}
		//�s���ŉ��s
		printf("\n");
	}
}