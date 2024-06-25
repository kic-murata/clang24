#include<stdio.h>
#define MapNum 3	 //�}�b�v�̐�
#define H 5	       //�}�b�v�̉������̃}�X��
#define W 10	     //�}�b�v�̏c�����̃}�X��

//�}�b�v�f�[�^���Ǘ����邽�߂̍\����
//�����o�͔z���H�sW��̐����^�z��
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
	/*�}�b�v�f�[�^�t�@�C���̈ꗗ�i�z�񉻁j
	  MapFileName[0]�ɂ�"map0.txt"�̕�����̐擪�A�h���X
	  MapFileName[1]�ɂ�"map1.txt"�̕�����̐擪�A�h���X
	  MapFileName[2]�ɂ�"map2.txt"�̕�����̐擪�A�h���X*/
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
/*void SetMap(char* filename, Map* m)
* �}�b�v�f�[�^�t�@�C������ǂݍ���ō\���̂̃����o�Ƀf�[�^���i�[����
* ��1�����F�}�b�v�f�[�^�t�@�C����
* ��2�����FMap�^�\���̕ϐ��̃A�h���X */
void SetMap(char* filename, Map* m) {
	FILE* fp;	//�t�@�C���|�C���^
	char ch;	//�ǂݎ��������'1'��'0'���i�[����ϐ�
	int i, j;	//��d���[�v�̂��߂̃J�E���^�ϐ�
	//�t�@�C����ǂݎ�胂�[�h�ŊJ��
	if (fp = fopen(filename, "r")) {
		//H�~W�̃f�[�^�����ԂɈꕶ�����ǂݎ���Ă���
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				/*fgetc�Ńt�@�C������1�����ǂݍ���ŕ����R�[�h��ch�Ɋi�[����B
				  fgetc�͐��䕶���i���s�A�^�u���j��1�����Ƃ��ēǂݍ���ł��܂�
				  ���߁A��Uch�Ɋi�[����ch�̓��e���`�F�b�N����K�v������*/
				ch = fgetc(fp);
				if (ch >= '0' && ch <= '9') {
					//�ǂݎ�����f�[�^�𐔒l�����ă����o�ɑ��
					m->m_map[i][j] = ch - '0';
				}
			}
			//�s���̉��s�R�[�h��ǂݔ�΂�
			fgetc(fp);
		}
		fclose(fp);
	}
}
/*void DrawMap(Map m)
* �}�b�v�f�[�^�����Ƃɉ�ʂɃ}�b�v��\��
* ��1�����FMap�^�\���̕ϐ� */
void DrawMap(Map m) {
	int i, j;	//��d���[�v�̂��߂̃J�E���^�ϐ�
	//H�~W�̃}�b�v��\������
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			//m_map�̗v�f��1�̂Ƃ��͕ǂ�\��
			if (m.m_map[i][j] == 1) {
				printf("��");
			}
			//m_map�̗v�f��0�̂Ƃ��͋󔒁i���p�j��\��
			else if (m.m_map[i][j] == 0) {
				printf(" ");
			}
		}
		//�s���ŉ��s
		printf("\n");
	}
}