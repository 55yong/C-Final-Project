#include "main.h"

void exit_to_main(int* point, int value) {
	PlaySound(NULL, 0, 0);							// 노래 종료
	system("cls");									// 화면 초기화
	border();										// 테두리 생성
	gotoxy(33, 8);
	printf("내 점수 : %d", *point);					// 내가 기록한 점수 출력
	if (value == 0) {								// value값이 0일 경우 (게임 오버일 경우)
		gotoxy(34, 9);
		printf("GAME OVER");						// GAME OVER 출력
	}
	else {											// 게임 클리어 했을 경우

		/*DB 연결 후 최고 점수 비교 작업*/
		MYSQL mysql = { 0 };
		MYSQL* conn = NULL;

		char buffer[200] = { 0 };

		mysql_init(&mysql);
		conn = mysql_real_connect(&mysql, HOST, USER, PASS, DB_NAME, PORT, NULL, 0);

		if (conn == NULL) {
			gotoxy(15, 7);
			fprintf(stderr, "DB 오류 : %s\n", mysql_error(&mysql));
			return;
		}
		else {
			sprintf(buffer, "UPDATE users SET best = %d WHERE id = '%s' AND %d > best", *point, &player, *point);

			mysql_query(conn, buffer);
			mysql_close(conn);
			gotoxy(33, 9);
			printf("STAGE CLEAR!");						// STAGE CLEAR 출력
		}
	}
	gotoxy(20, 11);
	printf("메인화면으로 가려면 아무 키나 누르세요...");	// 메인화면으로 돌아갈 수 있는 안내문구 출력
	system("pause > nul");
}