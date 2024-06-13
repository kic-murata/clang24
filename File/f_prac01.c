#include<stdio.h>
main()
{
	//変数宣言
	int score = 0;
	char ch, name[20];
	FILE* fp;
	//プレイヤー名の入力
	printf("プレイヤーの名前：");
	scanf("%s", name);
	//スコア加算処理（無限ループ）
	while (1) {
		printf("現在のスコア:%d ('e'で終了)\n", score);
		//キー入力待ち
		ch = getch();
		//'e'のキーが入力されたときループから抜ける
		if (ch == 'e') {
			break;
		}
		//スコア加算
		score++;
	}
	// ファイル書き込み処理
	//①ファイルのオープン
	if (fp = fopen("score.txt", "w")) {
		//②ファイルへのnameとscoreの書き込み
		fprintf(fp, "%s\n%d\n", name, score);
		//③ファイルのクローズ
		fclose(fp);
	}
	else {
		//ファイルが開けないときはfpはNULLになるのでエラーを表示
		printf("ファイルオープンエラー\n");
		//強制終了
		return;
	}
}