#include<stdio.h>
enum BitState
{
	Base = 0,          //00000000�F�ʏ���
	Poison = 1 << 0,   //00000001�F�ŏ��
	Sleep = 1 << 1,    //00000010�F�������
	Paralysis = 1 << 2,//00000100�F��჏��
	Burn = 1 << 3,     //00001000�F�Ώ����
	AtkUp = 1 << 4,    //00010000�F�U���̓A�b�v���
	AtkDown = 1 << 5   //00100000�F�U���̓_�E�����
};
//unsigned int��UINT�Ő錾�ł���悤��
typedef unsigned int UINT;
//���݂̃t���O����\��
void DisplayStatus(UINT s);
//�t���O�r�b�g��ON���s��
void ChangeFlag(UINT* s);
//�t���O�r�b�g��OFF���s��
void ClearFlag(UINT* s);
main() {
	//�t���O�Ǘ��p�ϐ���錾���Ēʏ��ԂƂ��ď�����
	UINT MyState = Base;
	//MyState�̃t���O�r�b�g�𗧂Ă�
	ChangeFlag(&MyState);
	//DisplayStatus(MyState);
	//MyState�̃t���O�r�b�g�𗎂Ƃ�
	ClearFlag(&MyState);
	//DisplayStatus(MyState);
}
void DisplayStatus(UINT s) {
	printf("****���݂̏��****\n");
	if (s & Poison) {	//����̃r�b�g�������Ă��邩��AND���Z�Ń`�F�b�N
		printf("��\n");
	}
	if (s & Sleep) {
		printf("����\n");
	}
	if (s & Paralysis) {
		printf("���\n");
	}
	if (s & Burn) {
		printf("�Ώ�\n");
	}
	if (s & AtkUp) {
		printf("�U���̓A�b�v\n");
	}
	if (s & AtkDown) {
		printf("�U���̓_�E��\n");
	}
	if (s == Base) {
		printf("��ԕω��Ȃ�\n");
	}
	printf("******************\n");
}
void ChangeFlag(UINT* s) {
	int a;
	while (1) {
		//���݂̏�Ԃ�\��
		DisplayStatus(*s);
		printf("�ǂ̏�Ԃ�t�^���܂����H\n");
		printf("1:�� 2:���� 3:��� 4:�Ώ� 5:�U���� 6:�U����  0:�I��>");
		//a��0�����͂��ꂽ�疳�����[�v���I��
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		//a�̒l�ɂ�菈���𕪊�
		switch (a) {
		case 1:
			*s |= Poison;	//OR���Z�Ńr�b�g�𗧂Ă�
			break;
		case 2:
			*s |= Sleep;
			break;
		case 3:
			*s |= Paralysis;
			break;
		case 4:
			*s |= Burn;
			break;
		case 5:
			*s |= AtkUp;
			break;
		case 6:
			*s |= AtkDown;
			break;
		default:	//1~6�ȊO�̒l�̂Ƃ�
			break;
		}
	}
}
void ClearFlag(UINT* s) {
	int a;
	while (1) {
		DisplayStatus(*s);
		printf("�ǂ̏�Ԃ��������܂����H\n");
		printf("1:�� 2:���� 3:��� 4:�Ώ� 5:�U���� 6:�U���� 7:�S���� 0:�I��>");
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		switch(a) {
		case 1:
			*s &= ~Poison;	//���]�r�b�g�Ƃ�AND���Z�œ���r�b�g�𗎂Ƃ�
			break;
		case 2:
			*s &= ~Sleep;
			break;
		case 3:
			*s &= ~Paralysis;
			break;
		case 4:
			*s &= ~Burn;
			break;
		case 5:
			*s &= ~AtkUp;
			break;
		case 6:
			*s &= ~AtkDown;
			break;
		case 7:
			*s = Base;
			break;
		default:
			break;
		}
	}
}