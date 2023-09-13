#include "main.h"

void exit_to_main(int* point, int value) {
	PlaySound(NULL, 0, 0);							// �뷡 ����
	system("cls");									// ȭ�� �ʱ�ȭ
	border();										// �׵θ� ����
	gotoxy(33, 8);
	printf("�� ���� : %d", *point);					// ���� ����� ���� ���
	if (value == 0) {								// value���� 0�� ��� (���� ������ ���)
		gotoxy(34, 9);
		printf("GAME OVER");						// GAME OVER ���
	}
	else {											// ���� Ŭ���� ���� ���

		/*DB ���� �� �ְ� ���� �� �۾�*/
		MYSQL mysql = { 0 };
		MYSQL* conn = NULL;

		char buffer[200] = { 0 };

		mysql_init(&mysql);
		conn = mysql_real_connect(&mysql, HOST, USER, PASS, DB_NAME, PORT, NULL, 0);

		if (conn == NULL) {
			gotoxy(15, 7);
			fprintf(stderr, "DB ���� : %s\n", mysql_error(&mysql));
			return;
		}
		else {
			sprintf(buffer, "UPDATE users SET best = %d WHERE id = '%s' AND %d > best", *point, &player, *point);

			mysql_query(conn, buffer);
			mysql_close(conn);
			gotoxy(33, 9);
			printf("STAGE CLEAR!");						// STAGE CLEAR ���
		}
	}
	gotoxy(20, 11);
	printf("����ȭ������ ������ �ƹ� Ű�� ��������...");	// ����ȭ������ ���ư� �� �ִ� �ȳ����� ���
	system("pause > nul");
}