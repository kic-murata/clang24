#include<stdio.h>
enum BitState
{
	Base = 0,          //00000000：通常状態
	Poison = 1 << 0,   //00000001：毒状態
	Sleep = 1 << 1,    //00000010：睡眠状態
	Paralysis = 1 << 2,//00000100：麻痺状態
	Burn = 1 << 3,     //00001000：火傷状態
	AtkUp = 1 << 4,    //00010000：攻撃力アップ状態
	AtkDown = 1 << 5   //00100000：攻撃力ダウン状態
};
//unsigned intをUINTで宣言できるように
typedef unsigned int UINT;
//現在のフラグ情報を表示
void DisplayStatus(UINT s);
//フラグビットのONを行う
void ChangeFlag(UINT* s);
//フラグビットのOFFを行う
void ClearFlag(UINT* s);
main() {
	//フラグ管理用変数を宣言して通常状態として初期化
	UINT MyState = Base;
	//MyStateのフラグビットを立てる
	ChangeFlag(&MyState);
	//DisplayStatus(MyState);
	//MyStateのフラグビットを落とす
	ClearFlag(&MyState);
	//DisplayStatus(MyState);
}
void DisplayStatus(UINT s) {
	printf("****現在の状態****\n");
	if (s & Poison) {	//特定のビットが立っているかのAND演算でチェック
		printf("毒\n");
	}
	if (s & Sleep) {
		printf("眠り\n");
	}
	if (s & Paralysis) {
		printf("麻痺\n");
	}
	if (s & Burn) {
		printf("火傷\n");
	}
	if (s & AtkUp) {
		printf("攻撃力アップ\n");
	}
	if (s & AtkDown) {
		printf("攻撃力ダウン\n");
	}
	if (s == Base) {
		printf("状態変化なし\n");
	}
	printf("******************\n");
}
void ChangeFlag(UINT* s) {
	int a;
	while (1) {
		//現在の状態を表示
		DisplayStatus(*s);
		printf("どの状態を付与しますか？\n");
		printf("1:毒 2:睡眠 3:麻痺 4:火傷 5:攻撃↑ 6:攻撃↓  0:終了>");
		//aに0が入力されたら無限ループを終了
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		//aの値により処理を分岐
		switch (a) {
		case 1:
			*s |= Poison;	//OR演算でビットを立てる
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
		default:	//1~6以外の値のとき
			break;
		}
	}
}
void ClearFlag(UINT* s) {
	int a;
	while (1) {
		DisplayStatus(*s);
		printf("どの状態を解除しますか？\n");
		printf("1:毒 2:睡眠 3:麻痺 4:火傷 5:攻撃↑ 6:攻撃↓ 7:全解除 0:終了>");
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		switch(a) {
		case 1:
			*s &= ~Poison;	//反転ビットとのAND演算で特定ビットを落とす
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