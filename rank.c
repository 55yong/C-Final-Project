#include "main.h"

void rank() {
	MYSQL mysql = { 0 };        // �⺻ ���� ����
	MYSQL* conn = NULL;         // ���� ���� ����
	MYSQL_RES* result = NULL;   // ���̺� ��ü�� ���� ����ü ������
	MYSQL_ROW* row = NULL;      // ���̺��� �迭 ������ ���� ����ü ������

	int i = 0;					// �ε��� ��ȣ�� ����� ����
	char buffer[200] = { 0 };   // sql���� ���� �迭
	
	mysql_init(&mysql);         // �ʱ�ȭ
	conn = mysql_real_connect(&mysql, HOST, USER, PASS, DB_NAME, PORT, NULL, 0);    // ����

	getchar();      // ����Ű ���� ����
	system("cls");  // ȭ�� �ʱ�ȭ
	border();       // �׵θ� ����

	if (conn == NULL) { // DB ������ ����� �ƴ��� Ȯ��
		gotoxy(3, 9);
		fprintf(stderr, "DB ���� : %s\n", mysql_error(&mysql));   // ������ �� �ƴٸ� ���� ���� ���
		system("pause > nul");
	}
	else {      // ������ ������ �Ʒ� ���� ����
		// users ���̺��� best ���� 0�� �ƴ� Į���� id, best ���� �ְ� ���� �������� �������� 5���� ���
		sprintf(buffer, "SELECT id, best FROM users WHERE best != 0 ORDER BY best DESC LIMIT 5");
		mysql_query(conn, buffer);
		result = mysql_store_result(conn);

		// ���� ��� ����
		gotoxy(28, 5);
		printf("���� |    �̸�    | ����");
		while ((row = mysql_fetch_row(result)) != NULL) {
			gotoxy(28, 6+i);
			printf("%2d�� | %-10s | %4s", i + 1, row[0], row[1]);
			i++;
		}
		mysql_close(conn);
		gotoxy(22, 17);
		printf("����ȭ������ ������ Enter�� ��������...\n");
		clearBuffer();
	}
}