#include<stdio.h>
main()
{
	//ファイルポインタの宣言
	FILE* fp;
	//文字列格納用の文字型配列
	char str[256];
	int lv, hp;
	//file02.txtというファイルを読み取りモードで開く
	fp = fopen("file02.txt", "r");
	//ファイルから文字列を読み込む
	fscanf(fp, "%s", str);
	//読み取った文字列を表示
	printf("装備：%s\n", str);
	fscanf(fp, "%s", str);
	printf("装備：%s\n", str);
	fscanf(fp, "%s", str);
	printf("装備：%s\n", str);
	//空白区切りのデータ（整数値・整数値・文字列）を読み取る
	fscanf(fp, "%d%d%s", &lv, &hp, str);
	//読み取った値を表示
	printf("lv:%d hp:%d 装備:%s\n", lv, hp, str);
	fclose(fp);
}