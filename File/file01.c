#include<stdio.h>
main()
{
	//ファイルポインタの宣言
	FILE* fp;
	int a = 10, b = 20;
	//file01.txtというファイル名で書き込みモードで開く
	fp = fopen("file01.txt", "w");
	//文字列の書き込み
	fprintf(fp, "KOBEDENSHI\n");
	//変換指定子を使った書き込み
	fprintf(fp, "%d+%d=%d\n", a, b, a + b);
	//ファイルを閉じる
	fclose(fp);
}