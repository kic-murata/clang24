#include<stdio.h>
#define MapNum 3	 //マップの数
#define H 5	       //マップの横方向のマス数
#define W 10	     //マップの縦方向のマス数

//マップデータを管理するための構造体
//メンバは配列でH行W列の整数型配列
typedef struct {
	int m_map[H][W];
} Map;

//選択したマップデータを配列にセットする関数
void SetMap(char *filename, Map	*m);
//マップデータ表示する関数
void DrawMap(Map m);

main()
{
	//マップのデータを管理する構造体変数の宣言
	Map MapData; 
	/*マップデータファイルの一覧（配列化）
	  MapFileName[0]には"map0.txt"の文字列の先頭アドレス
	  MapFileName[1]には"map1.txt"の文字列の先頭アドレス
	  MapFileName[2]には"map2.txt"の文字列の先頭アドレス*/
	char* MapFileName[MapNum]
		= { "map0.txt","map1.txt","map2.txt" };
	//表示するマップの番号
	int select;

	printf("表示するマップを選択(0,1,2):");
	scanf("%d", &select);
	//マップ番号の範囲チェック
	if (select >= 0 && select <= 2) {
		//マップデータファイルからの読み込み
		SetMap(MapFileName[select], &MapData);
		//マップデータの画面表示
		DrawMap(MapData);
	}
	else {
		puts("エラー:0～2の中で入力してください");
	}
}
/*void SetMap(char* filename, Map* m)
* マップデータファイルから読み込んで構造体のメンバにデータを格納する
* 第1引数：マップデータファイル名
* 第2引数：Map型構造体変数のアドレス */
void SetMap(char* filename, Map* m) {
	FILE* fp;	//ファイルポインタ
	char ch;	//読み取った文字'1'や'0'を格納する変数
	int i, j;	//二重ループのためのカウンタ変数
	//ファイルを読み取りモードで開く
	if (fp = fopen(filename, "r")) {
		//H×W個のデータを順番に一文字ずつ読み取っていく
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				/*fgetcでファイルから1文字読み込んで文字コードをchに格納する。
				  fgetcは制御文字（改行、タブ等）も1文字として読み込んでしまう
				  ため、一旦chに格納してchの内容をチェックする必要がある*/
				ch = fgetc(fp);
				if (ch >= '0' && ch <= '9') {
					//読み取ったデータを数値化してメンバに代入
					m->m_map[i][j] = ch - '0';
				}
			}
			//行末の改行コードを読み飛ばす
			fgetc(fp);
		}
		fclose(fp);
	}
}
/*void DrawMap(Map m)
* マップデータをもとに画面にマップを表示
* 第1引数：Map型構造体変数 */
void DrawMap(Map m) {
	int i, j;	//二重ループのためのカウンタ変数
	//H×Wのマップを表示する
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			//m_mapの要素が1のときは壁を表示
			if (m.m_map[i][j] == 1) {
				printf("■");
			}
			//m_mapの要素が0のときは空白（半角）を表示
			else if (m.m_map[i][j] == 0) {
				printf(" ");
			}
		}
		//行末で改行
		printf("\n");
	}
}