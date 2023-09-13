#include "main.h"

#define row1 14		// 메뉴에서 gotoxy를 사용할 때 값1에 대한 심볼릭 상수
#define row2 26		// 메뉴에서 gotoxy를 사용할 때 값2에 대한 심볼릭 상수
#define row3 41		// 메뉴에서 gotoxy를 사용할 때 값3에 대한 심볼릭 상수
#define row4 55		// 메뉴에서 gotoxy를 사용할 때 값4에 대한 심볼릭 상수	

int menu1() {
	system("cls");	// 화면 초기화
	border();		// 테두리 생성

	int POS = 0;	// 0 - 로그인(게임시작), 1 - 랭킹 보기, 2 - 게임 종료

	SetColor(3);
	gotoxy(row1, 9);						// row1, 9에 로그인 버튼 생성
	printf("① 로그인");
	gotoxy(row2, 9);						// row2, 9에 회원 가입 버튼 생성
	printf("② 회원 가입");
	gotoxy(row3, 9);						// row3, 9에 랭킹 보기 버튼 생성
	printf("③ 랭킹 보기");
	gotoxy(row4, 9);						// row4, 9에 게임 종료 버튼 생성
	printf("④ 게임 종료");
	SetColor(15);

	gotoxy(34, 13);
	printf("선택 > ");
	scanf("%d", &POS);

	return POS;									// break문이 작동했을 때 POS값을 return해줌
}