#include "main.h"

void regist() {
    MYSQL mysql = { 0 };        // �⺻ ���� ����
    MYSQL* conn = NULL;         // ���� ���� ����
    MYSQL_RES* result = NULL;   // ���̺� ��ü�� ���� ����ü ������

    int regist_success = 1;     // ���������� ȸ�������� �ƴ��� Ȯ���ϴ� ����
    char id[15] = { 0 };        // id�� ���� �迭
    char pass[15] = { 0 };      // ��й�ȣ�� ���� �迭
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
        gotoxy(25, 7);
        printf("���̵� �Է� : ");     // ���̵� gets�� �Է¹���
        gets(id);
        gotoxy(25, 8);
        printf("�н����� �Է� : ");   // ��й�ȣ�� gets�� �Է¹���
        gets(pass);

        // SQL������ ���ۿ� ���� (���� �Է��� ID�� ������ ID�� ���̺� �����ϴ���)
        sprintf(buffer, "SELECT id FROM users WHERE id = '%s'", id);

        // ���� ���� �� result�� ����� ���
        mysql_query(conn, buffer);
        result = mysql_store_result(conn);

        // ���� ����� NULL�� �ƴ� ��� (�ߺ��Ǵ� ���)
        if (mysql_fetch_row(result) != NULL) {
            regist_success = 0; // regist_success�� 0���� ����
        }

        // ���� �ߺ����� ���� ��� (regist_success�� 1�� ���)
        if (regist_success) {
            // DB�� ID, ��й�ȣ ���� ���
            sprintf(buffer, "INSERT INTO users VALUES(0, '%s', '%s', 0)", id, pass);
            mysql_query(conn, buffer);
            gotoxy(15, 10);
            printf("ȸ������ ����! ����ȭ������ ������ Enter�� ��������...");
        }
        else {
            // ���� �߻� ���� ���
            gotoxy(15, 10);
            printf("ȸ������ �� ���� �߻� : ���̵� �ߺ��˴ϴ�!\n");
        }
        mysql_close(conn);
        clearBuffer();
    }
}