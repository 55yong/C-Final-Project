#include "main.h"

void border() {
	for (int i = 0; i < 78; i++) {		// 위아래 테두리를 만드는 반복문
		gotoxy(i, 0);
		printf("■");

		gotoxy(i, 19);
		printf("■");
	}
	for (int i = 0; i < 20; i++) {		// 좌우 테두리를 만드는 반복문
		gotoxy(0, i);
		printf("■");

		gotoxy(78, i);
		printf("■");
	}
}