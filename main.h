#pragma once						// 빌드 시 여러 번 사용되지 않게 선언
#define _CRT_SECURE_NO_WARNINGS		// CRT SECURE에 대한 오류 발생 중지
#include <stdio.h>					// 표준 입출력 헤더 파일 선언
#include <stdlib.h>					// 표준 라이브러리 헤더 파일 선언
#include <string.h>					// 문자열 처리 함수를 사용하기 위한 헤더 파일 선언
#include <Windows.h>				// Windows 명령어를 사용할 수 있는 헤더 파일 선언
#include <mysql.h>					// DB 연동을 위한 헤더 파일 선언
#include <mmsystem.h>				// 음악을 사용할 수 있도록 mmsystem 헤더 파일 선언
#pragma comment (lib, "winmm.lib")  // 음악을 사용할 수 있는 별도의 라이브러리인 winmm.lib도 선언

/* 서브시스템 함수 */
void CursorView();		// 화면에서 커서를 숨기는 함수
void gotoxy(int, int);	// 출력 좌표를 변경하는 함수
void SetColor(int);		// 텍스트에 색깔을 입혀주는 함수
void clearBuffer();		// 버퍼 입력 삭제

/* DB 연동 관련 */
#define HOST "localhost"	// DB hostname
#define USER "root"			// DB username
#define PASS "qkfkathfl1@"	// DB password
#define DB_NAME "project"	// DB name
#define PORT 3307			// DB port
char* player;				// DB player name

int login();				// 로그인 처리 함수
void regist();				// 회원가입 처리 함수
void rank();				// 랭킹 출력 함수

/* 디스플레이 함수*/
void border();					// 테두리 생성 함수
void map(int*, int*, int*);		// 인게임 디스플레이 함수
void draw_info(int);			// 노래 선택 시 정보를 알려주는 함수
void clear_info();				// 이전에 선택한 노래의 정보를 화면에서 지우는 함수

/* 메뉴 함수*/
int menu1();	// 메인메뉴 함수
int menu2();	// 노래 선택 메뉴 함수

/* 게임 플레이 함수*/
void user_input(int*, int*, int*, int*);						// 유저 입력 처리 함수
void music_select(int);											// 음악 선택 함수
int music_note(int, int*, int*);								// 음악에 맞는 노트를 가져오는 함수
int note_value_change(int, int, int*, int*, int*, int*, int*);	// 노트 인식 처리 함수
void play(int, int*, int*, int*, int*, int*, int*, int*);		// 게임 플레이 처리 함수

/* 노트 함수 */
void music1(int*, int*);
void music2(int*, int*);
void music3(int*, int*);
void music4(int*, int*);

/* 종료 판단 함수 */
void exit_to_main(int*, int);	// 게임을 클리어하거나 목숨이 다 떨어졌을 때 실행할 함수
void end();						// 프로그램 종료 버튼 선택 시 실행할 함수