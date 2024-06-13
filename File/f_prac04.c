#include<stdio.h>
#define Sol_Num 3		//������
// �\���̂̐錾
typedef struct {
	char   Wname[20];	//���햼
	int    bullet;		//�e��
	float  atk;			  //�U����
} Weapon;						//�\���̂�Weapon�Ƃ��Ē�`
typedef struct {		
	char   name[20];	//������
	int    hp;				//����hp
	Weapon wpn;			  //����\���̕ϐ�
} Soldier;					//�\���̂�Soldier�Ƃ��Ē�`
// �v���g�^�C�v�錾
void SetInfo(Soldier* s, char* filename);
void Display(Soldier* s);

main()
{
	//�\���̔z��i�v�f���FSol_Num�j�̐錾
	Soldier sol[Sol_Num];
	//SetInfo�֐��̌Ăяo���i�������͔z��̐擪�A�h���X,�������̓t�@�C�����j
	SetInfo(sol, "file03.txt");
	//Display�֐��̌Ăяo���i�����͔z��̐擪�A�h���X�j
	Display(sol);
}

void SetInfo(Soldier*s,char *filename) {
	//�t�@�C���|�C���^�̐錾
	FILE* fp;
	//���[�v�p�J�E���^i�̐錾
	int i;
	//�t�@�C���I�[�v���A�߂�lNULL�Ȃ�G���[�\��
	if (fp = fopen(filename, "r")) {
		//Sol_Num�̉񐔕����[�v
		for(i=0;i<Sol_Num;i++){
			//�ǂݎ�����l���|�C���^�ϐ����g���āA�e�����o�Ɋi�[
			fscanf(fp, "%s%d%s%d%f", (s + i)->name,
				&(s + i)->hp, (s + i)->wpn.Wname,
				&(s + i)->wpn.bullet, &(s + i)->wpn.
				atk);
		}
		fclose(fp);
	}
	else {
		printf("�t�@�C���̓ǂݍ��݃G���[\n");
	}
}

void Display(Soldier* s) {
	int i;
	//Sol_Num�̉񐔕����[�v
	for (i = 0; i < Sol_Num; i++) {
		//�|�C���^�ϐ��ƃA���[���Z�q���g���āA�e�����o��\��
		printf("%s �̗�:%d\n", (s + i)->name, (s + i)->hp);
		printf("����:%s �@�c�e��:%d �@�U����:%.2f\n",
			(s + i)->wpn.Wname, (s + i)->wpn.bullet, (s + i)->wpn.atk);
	}
}