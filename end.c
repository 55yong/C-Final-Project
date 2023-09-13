#include "main.h"

void end() {
	system("cls");						// 화면을 초기화 시키고
	border();							// 테두리 생성
	gotoxy(35, 9);
	printf("GOOD BYE\n");				// GOOD BYE 출력 후
	exit(0);
}