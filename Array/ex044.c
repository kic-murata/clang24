#include<stdio.h>
main()
{
	char moji1[40], moji2[40],w[40];
	int i;
	printf("������P����́F");
	scanf("%s", &moji1[0]);
	printf("������Q����́F");
	scanf("%s", &moji2[0]);
	printf("moji1=%s  moji2=%s\n", moji1, moji2);
	//moji1�̔z��v�f��w�ɃR�s�[����
	for (i = 0; w[i] = moji1[i]; i++);
	//i = 0;
	//while (moji1[i] != '\0') {
	//	w[i] = moji1[i];
	//	i++;
	//}
	//w[i] = '\0';
	//moji2�̔z��v�f��moji1�ɃR�s�[����
	for (i = 0; i < 40; i++) {
		moji1[i] = moji2[i];
	}	
	//w�̔z��v�f��moji2�ɃR�s�[����
	i = 0;
	while (1) {
		if (!(moji2[i] = w[i])) break;
//		if (w[i] == '\0') break;
//		moji2[i] = w[i];
		i++;
	}
	moji2[i] = '\0';
	printf("����ւ����\n");
	printf("moji1=%s  moji2=%s\n", moji1, moji2);
}