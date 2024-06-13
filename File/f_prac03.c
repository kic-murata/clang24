#include<stdio.h>
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
void Display(Soldier s);

main()
{
	//�\���̕ϐ��̐錾
	Soldier sol;
	//SetInfo�֐��̌Ăяo���i�������͍\���̕ϐ��̃A�h���X,�������̓t�@�C�����j
	SetInfo(&sol, "file03.txt");
	//Display�֐��̌Ăяo���i�������͍\���̕ϐ��j
	Display(sol);
}

void SetInfo(Soldier*s,char *filename) {
	//�t�@�C���|�C���^�̐錾
	FILE* fp;
	//�t�@�C���I�[�v���A�߂�lNULL�Ȃ�G���[�\��
	if (fp = fopen(filename, "r")) {
		//�t�@�C������ǂݎ�����l���\���̂̃����o�Ƃ��đ��
		//*s�̓|�C���^�ϐ��Ȃ̂Ń����o�̓A���[���Z�q�Ŏw��
		//wpn�͍\���̕ϐ��Ȃ̂Ń����o�̓h�b�g��t���Ďw��
		fscanf(fp, "%s%d%s%d%f", s->name,
			&s->hp, s->wpn.Wname,
			&s->wpn.bullet, &s->wpn.atk);
		fclose(fp);
	}
	else {
		printf("�t�@�C���̓ǂݍ��݃G���[\n");
	}
}

void Display(Soldier s) {
	//s�͕ϐ��Ȃ̂ŁA�h�b�g(.)�Ń����o���w��
	printf("%s �̗�:%d\n", s.name, s.hp);
	printf("����:%s �@�c�e��:%d �@�U����:%.2f\n",
		s.wpn.Wname, s.wpn.bullet, s.wpn.atk);
}