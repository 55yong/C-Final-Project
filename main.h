#pragma once						// ���� �� ���� �� ������ �ʰ� ����
#define _CRT_SECURE_NO_WARNINGS		// CRT SECURE�� ���� ���� �߻� ����
#include <stdio.h>					// ǥ�� ����� ��� ���� ����
#include <stdlib.h>					// ǥ�� ���̺귯�� ��� ���� ����
#include <string.h>					// ���ڿ� ó�� �Լ��� ����ϱ� ���� ��� ���� ����
#include <Windows.h>				// Windows ��ɾ ����� �� �ִ� ��� ���� ����
#include <mysql.h>					// DB ������ ���� ��� ���� ����
#include <mmsystem.h>				// ������ ����� �� �ֵ��� mmsystem ��� ���� ����
#pragma comment (lib, "winmm.lib")  // ������ ����� �� �ִ� ������ ���̺귯���� winmm.lib�� ����

/* ����ý��� �Լ� */
void CursorView();		// ȭ�鿡�� Ŀ���� ����� �Լ�
void gotoxy(int, int);	// ��� ��ǥ�� �����ϴ� �Լ�
void SetColor(int);		// �ؽ�Ʈ�� ������ �����ִ� �Լ�
void clearBuffer();		// ���� �Է� ����

/* DB ���� ���� */
#define HOST "localhost"	// DB hostname
#define USER "root"			// DB username
#define PASS "qkfkathfl1@"	// DB password
#define DB_NAME "project"	// DB name
#define PORT 3307			// DB port
char* player;				// DB player name

int login();				// �α��� ó�� �Լ�
void regist();				// ȸ������ ó�� �Լ�
void rank();				// ��ŷ ��� �Լ�

/* ���÷��� �Լ�*/
void border();					// �׵θ� ���� �Լ�
void map(int*, int*, int*);		// �ΰ��� ���÷��� �Լ�
void draw_info(int);			// �뷡 ���� �� ������ �˷��ִ� �Լ�
void clear_info();				// ������ ������ �뷡�� ������ ȭ�鿡�� ����� �Լ�

/* �޴� �Լ�*/
int menu1();	// ���θ޴� �Լ�
int menu2();	// �뷡 ���� �޴� �Լ�

/* ���� �÷��� �Լ�*/
void user_input(int*, int*, int*, int*);						// ���� �Է� ó�� �Լ�
void music_select(int);											// ���� ���� �Լ�
int music_note(int, int*, int*);								// ���ǿ� �´� ��Ʈ�� �������� �Լ�
int note_value_change(int, int, int*, int*, int*, int*, int*);	// ��Ʈ �ν� ó�� �Լ�
void play(int, int*, int*, int*, int*, int*, int*, int*);		// ���� �÷��� ó�� �Լ�

/* ��Ʈ �Լ� */
void music1(int*, int*);
void music2(int*, int*);
void music3(int*, int*);
void music4(int*, int*);

/* ���� �Ǵ� �Լ� */
void exit_to_main(int*, int);	// ������ Ŭ�����ϰų� ����� �� �������� �� ������ �Լ�
void end();						// ���α׷� ���� ��ư ���� �� ������ �Լ�