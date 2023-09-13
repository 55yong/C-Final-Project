#include "main.h"

void map(int* point, int* combo, int* life) {
	gotoxy(27, 1);
	printf("┌─────┬─────┬─────┬─────┐");	// 5번줄 ~ 19번줄까지 백그라운드 디스플레이를 구성하는 코드

	for (int i = 2; i < 14; i++) {
		gotoxy(27, i);
		printf("│     │     │     │     │");
	}
	gotoxy(27, 14);
	printf("├─────┴─────┴─────┴─────┤");
	gotoxy(27, 15);
	printf("│          HIT          │");
	gotoxy(27, 16);
	printf("├───────────────────────┤");
	gotoxy(27, 17);
	printf("│                       │");
	gotoxy(27, 18);
	printf("└───────────────────────┘");

	gotoxy(55, 7);
	printf("콤보   : %3d", *combo);			// 화면에 콤보 표시
	gotoxy(55, 8);
	printf("점수   : %3d", *point);			// 화면에 점수 표시
	gotoxy(55, 9);
	printf("목숨   : %3d", *life);			// 화면에 목숨 표시
	gotoxy(55, 10);
	printf("조작키 : D F J K");				// 화면에 조작키 표시
}