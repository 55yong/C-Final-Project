#include "main.h"

int login() {
    MYSQL mysql = { 0 };        // 기본 정보 관리
    MYSQL* conn = NULL;         // 연결 정보 관리
    MYSQL_RES* result = NULL;   // 테이블 전체를 담을 구조체 포인터
    MYSQL_ROW* row = NULL;      // 테이블을 배열 구조로 담을 구조체 포인터

    int login_success = 0;      // 정상적으로 로그인이 됐는지 확인하는 변수
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

        // SQL구문을 버퍼에 담음 (내가 입력한 id와 비밀번호가 DB에 있는 id, 비밀번호 정보와 동일한지 확인
        sprintf(buffer, "SELECT id, pass FROM users WHERE id = '%s' AND pass ='%s'", id, pass);
        mysql_query(conn, buffer); // 쿼리 전송

        result = mysql_store_result(conn);  // 쿼리 결과를 result에 담음
        while ((row = mysql_fetch_row(result)) != NULL) {   // 테이블 끝까지 while문을 돌리기
            if (strcmp(row[0], id) == 0 && strcmp(row[1], pass) == 0) { // 내가 입력한 id와 pass가 동일한지 확인
                login_success = 1;  // 동일할 경우 login_success를 1로 변경
                strcpy(&player, id);
            }
        }
        mysql_close(conn);  // DB 연결 해제

        if (login_success == 1) {   // 정상적으로 로그인이 됐다면
            gotoxy(15, 10);         // 로그인 성공 문구 출력
            printf("로그인 성공! 게임을 시작하려면 Enter를 누르세요...");
            clearBuffer();
        }
        else {              // 로그인 실패 시
            gotoxy(15, 9);  //로그인 실패 문구 출력
            printf("로그인 실패! 메인화면으로 가려면 Enter를 누르세요...");
            clearBuffer();
        }
    }
    return login_success;   // login_success 값 반환
}