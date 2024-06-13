#include<stdio.h>
#define Sol_Num 3		//隊員数
// 構造体の宣言
typedef struct {
	char   Wname[20];	//武器名
	int    bullet;		//弾数
	float  atk;			  //攻撃力
} Weapon;						//構造体をWeaponとして定義
typedef struct {		
	char   name[20];	//隊員名
	int    hp;				//隊員hp
	Weapon wpn;			  //武器構造体変数
} Soldier;					//構造体をSoldierとして定義
// プロトタイプ宣言
void SetInfo(Soldier* s, char* filename);
void Display(Soldier* s);

main()
{
	//構造体配列（要素数：Sol_Num）の宣言
	Soldier sol[Sol_Num];
	//SetInfo関数の呼び出し（第一引数は配列の先頭アドレス,第二引数はファイル名）
	SetInfo(sol, "file03.txt");
	//Display関数の呼び出し（引数は配列の先頭アドレス）
	Display(sol);
}

void SetInfo(Soldier*s,char *filename) {
	//ファイルポインタの宣言
	FILE* fp;
	//ループ用カウンタiの宣言
	int i;
	//ファイルオープン、戻り値NULLならエラー表示
	if (fp = fopen(filename, "r")) {
		//Sol_Numの回数分ループ
		for(i=0;i<Sol_Num;i++){
			//読み取った値をポインタ変数を使って、各メンバに格納
			fscanf(fp, "%s%d%s%d%f", (s + i)->name,
				&(s + i)->hp, (s + i)->wpn.Wname,
				&(s + i)->wpn.bullet, &(s + i)->wpn.
				atk);
		}
		fclose(fp);
	}
	else {
		printf("ファイルの読み込みエラー\n");
	}
}

void Display(Soldier* s) {
	int i;
	//Sol_Numの回数分ループ
	for (i = 0; i < Sol_Num; i++) {
		//ポインタ変数とアロー演算子を使って、各メンバを表示
		printf("%s 体力:%d\n", (s + i)->name, (s + i)->hp);
		printf("武器:%s 　残弾数:%d 　攻撃力:%.2f\n",
			(s + i)->wpn.Wname, (s + i)->wpn.bullet, (s + i)->wpn.atk);
	}
}