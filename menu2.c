#include "main.h"

#define col1 5									// 메뉴에서 gotoxy를 사용할 때 값1에 대한 심볼릭 상수
#define col2 8									// 메뉴에서 gotoxy를 사용할 때 값2에 대한 심볼릭 상수
#define col3 11									// 메뉴에서 gotoxy를 사용할 때 값3에 대한 심볼릭 상수
#define col4 14									// 메뉴에서 gotoxy를 사용할 때 값4에 대한 심볼릭 상수

int menu2() {
	Sleep(100);									// 100ms 휴식 후
	system("cls");								// 화면 초기화
	border();									// 테두리 생성

	gotoxy(17, 5);
	printf("선택 : Space");

	int POS = 0;								// 0 - 노래 1번, 1 - 노래 2번, 2 - 노래 3번, 3 - 노래 4번

	while (1) {
		gotoxy(45, col1);						// 22, 9에 노래1번 버튼 생성
		printf("RE:WIND");
		gotoxy(45, col2);						// 35, 9에 노래2번 버튼 생성
		printf("Sweet Dreams, My Dear");
		gotoxy(45, col3);						// 50, 9에 노래3번 버튼 생성
		printf("별빛 등대의 섬");
		gotoxy(45, col4);						// 50, 9에 노래3번 버튼 생성
		printf("멸공의 횃불");

		if (GetAsyncKeyState(VK_UP)) {			// 왼쪽 키를 눌렀을 때
			POS -= 1;							// POS 1 감소
		}
		else if (GetAsyncKeyState(VK_DOWN)) {	// 오른쪽 키를 눌렀을 때
			POS += 1;							// POS 1 증가
		}
		else if (GetAsyncKeyState(VK_SPACE)) { // 엔터를 눌렀을 때
			break;								// while문 종료
		}
		if (POS == -1) {						// 만약 플레이어가 위쪽 키를 너무 많이 눌러서 -1이 되었을 경우
			POS = 0;							// POS값을 0으로 바꿔줌
		}
		else if (POS == 4) {					// 만약 플레이어가 아래쪽 키를 너무 많이 눌러서 4가 되었을 경우
			POS = 3;							// POS 값을 3로 바꿔줌
		}
		switch (POS) {							// POS의 값을 가지고 switch ~ case문 실행
		case 0:									// POS값이 0일 경우 (노래 1번에 커서를 두고 있는 경우)
			draw_info(POS);						// 좌측 중앙에 노래 1에 대한 정보를 표시
			SetColor(11);						// 콘솔의 글꼴 색상값을 하늘색으로 변경
			gotoxy(45, col1);					// 45, col1에 버튼 덮어쓰기
			printf("RE:WIND");
			SetColor(15);						// 다른 버튼들은 흰색으로 유지될 수 있도록 색상 재변경	
			break;
		case 1:									// POS값이 1일 경우 (노래 2번에 커서를 두고 있는 경우)
			draw_info(POS);						// 좌측 중앙에 노래 2에 대한 정보를 표시
			SetColor(11);						// 콘솔의 글꼴 색상값을 하늘색으로 변경
			gotoxy(45, col2);					// 45, col2에 버튼 덮어쓰기
			printf("Sweet Dreams, My Dear");
			SetColor(15);						// 다른 버튼들은 흰색으로 유지될 수 있도록 색상 재변경
			break;
		case 2:									// POS값이 2일 경우 (노래 3번에 커서를 두고 있는 경우)
			draw_info(POS);						// 좌측 중앙에 노래 3에 대한 정보를 표시
			SetColor(11);						// 콘솔의 글꼴 색상값을 하늘색으로 변경
			gotoxy(45, col3);					// 45, col3에 버튼 덮어쓰기
			printf("별빛 등대의 섬");
			SetColor(15);						// 다른 버튼들은 흰색으로 유지될 수 있도록 색상 재변경
			break;
		case 3:									// POS값이 3일 경우 (노래 4번에 커서를 두고 있는 경우)
			draw_info(POS);						// 좌측 중앙에 노래 4에 대한 정보를 표시
			SetColor(11);						// 콘솔의 글꼴 색상값을 하늘색으로 변경
			gotoxy(45, col4);					// 45, col4에 버튼 덮어쓰기
			printf("멸공의 횃불");
			SetColor(15);						// 다른 버튼들은 흰색으로 유지될 수 있도록 색상 재변경
			break;
		}
		Sleep(100);								// POS 값이 변경될 때 너무 빠르게 변경되지 않도록 100ms Sleep
	}
	return POS;									// break문이 작동했을 때 POS값을 return해줌
}