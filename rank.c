#include "main.h"

void rank() {
	MYSQL mysql = { 0 };        // 기본 정보 관리
	MYSQL* conn = NULL;         // 연결 정보 관리
	MYSQL_RES* result = NULL;   // 테이블 전체를 담을 구조체 포인터
	MYSQL_ROW* row = NULL;      // 테이블을 배열 구조로 담을 구조체 포인터

	int i = 0;					// 인덱스 번호로 사용할 변수
	char buffer[200] = { 0 };   // sql문을 담을 배열
	
	mysql_init(&mysql);         // 초기화
	conn = mysql_real_connect(&mysql, HOST, USER, PASS, DB_NAME, PORT, NULL, 0);    // 연결

	getchar();      // 엔터키 씹힘 방지
	system("cls");  // 화면 초기화
	border();       // 테두리 생성

	if (conn == NULL) { // DB 연결이 제대로 됐는지 확인
		gotoxy(3, 9);
		fprintf(stderr, "DB 오류 : %s\n", mysql_error(&mysql));   // 연결이 안 됐다면 오류 문구 출력
		system("pause > nul");
	}
	else {      // 연결이 됐으면 아래 구문 실행
		// users 테이블에서 best 값이 0이 아닌 칼럼의 id, best 값을 최고 점수 내림차순 기준으로 5개만 출력
		sprintf(buffer, "SELECT id, best FROM users WHERE best != 0 ORDER BY best DESC LIMIT 5");
		mysql_query(conn, buffer);
		result = mysql_store_result(conn);

		// 순위 출력 구문
		gotoxy(28, 5);
		printf("순위 |    이름    | 점수");
		while ((row = mysql_fetch_row(result)) != NULL) {
			gotoxy(28, 6+i);
			printf("%2d위 | %-10s | %4s", i + 1, row[0], row[1]);
			i++;
		}
		mysql_close(conn);
		gotoxy(22, 17);
		printf("메인화면으로 가려면 Enter를 누르세요...\n");
		clearBuffer();
	}
}