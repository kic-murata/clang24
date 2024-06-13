#include<stdio.h>
main()
{
	//max_score：ファイルから読み取ったスコアを格納
	int max_score, score = 0;
	//max_name:ファイルから読み取ったプレイヤー名を格納
	char max_name[20], ch, name[20];
	FILE* fp;
	//スコアファイルを読み取りモードで開く
	if (fp = fopen("score.txt", "r")) {
		fscanf(fp, "%s%d", max_name, &max_score);
		fclose(fp);
		printf("最高得点　名前：%s スコア：%d\n", max_name, max_score);
	}
	else {
		//開くファイルがない場合、fpはNULLになるのでエラーを表示
		printf("ファイルが読めません!\n");
		//強制終了
		return;
	}

	printf("プレイヤー名を入力：");
	scanf("%s", name);
	while (1) {
		printf("現在のスコア:%d ('e'で終了)\n", score);
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
		printf("ハイスコア更新！\n");
	}
}