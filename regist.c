#include "main.h"

void regist() {
    MYSQL mysql = { 0 };        // 기본 정보 관리
    MYSQL* conn = NULL;         // 연결 정보 관리
    MYSQL_RES* result = NULL;   // 테이블 전체를 담을 구조체 포인터

    int regist_success = 1;     // 정상적으로 회원가입이 됐는지 확인하는 변수
    char id[15] = { 0 };        // id를 담을 배열
    char pass[15] = { 0 };      // 비밀번호를 담을 배열
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
        gotoxy(25, 7);
        printf("아이디 입력 : ");     // 아이디를 gets로 입력받음
        gets(id);
        gotoxy(25, 8);
        printf("패스워드 입력 : ");   // 비밀번호를 gets로 입력받음
        gets(pass);

        // SQL구문을 버퍼에 담음 (내가 입력한 ID와 동일한 ID가 테이블에 존재하는지)
        sprintf(buffer, "SELECT id FROM users WHERE id = '%s'", id);

        // 쿼리 전송 후 result에 결과값 담기
        mysql_query(conn, buffer);
        result = mysql_store_result(conn);

        // 만약 결과가 NULL이 아닐 경우 (중복되는 경우)
        if (mysql_fetch_row(result) != NULL) {
            regist_success = 0; // regist_success를 0으로 변경
        }

        // 만약 중복값이 없는 경우 (regist_success가 1일 경우)
        if (regist_success) {
            // DB에 ID, 비밀번호 정보 등록
            sprintf(buffer, "INSERT INTO users VALUES(0, '%s', '%s', 0)", id, pass);
            mysql_query(conn, buffer);
            gotoxy(15, 10);
            printf("회원가입 성공! 메인화면으로 가려면 Enter를 누르세요...");
        }
        else {
            // 오류 발생 이유 출력
            gotoxy(15, 10);
            printf("회원가입 중 오류 발생 : 아이디가 중복됩니다!\n");
        }
        mysql_close(conn);
        clearBuffer();
    }
}