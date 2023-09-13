#include "main.h"

int login() {
    MYSQL mysql = { 0 };        // �⺻ ���� ����
    MYSQL* conn = NULL;         // ���� ���� ����
    MYSQL_RES* result = NULL;   // ���̺� ��ü�� ���� ����ü ������
    MYSQL_ROW* row = NULL;      // ���̺��� �迭 ������ ���� ����ü ������

    int login_success = 0;      // ���������� �α����� �ƴ��� Ȯ���ϴ� ����
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

        // SQL������ ���ۿ� ���� (���� �Է��� id�� ��й�ȣ�� DB�� �ִ� id, ��й�ȣ ������ �������� Ȯ��
        sprintf(buffer, "SELECT id, pass FROM users WHERE id = '%s' AND pass ='%s'", id, pass);
        mysql_query(conn, buffer); // ���� ����

        result = mysql_store_result(conn);  // ���� ����� result�� ����
        while ((row = mysql_fetch_row(result)) != NULL) {   // ���̺� ������ while���� ������
            if (strcmp(row[0], id) == 0 && strcmp(row[1], pass) == 0) { // ���� �Է��� id�� pass�� �������� Ȯ��
                login_success = 1;  // ������ ��� login_success�� 1�� ����
                strcpy(&player, id);
            }
        }
        mysql_close(conn);  // DB ���� ����

        if (login_success == 1) {   // ���������� �α����� �ƴٸ�
            gotoxy(15, 10);         // �α��� ���� ���� ���
            printf("�α��� ����! ������ �����Ϸ��� Enter�� ��������...");
            clearBuffer();
        }
        else {              // �α��� ���� ��
            gotoxy(15, 9);  //�α��� ���� ���� ���
            printf("�α��� ����! ����ȭ������ ������ Enter�� ��������...");
            clearBuffer();
        }
    }
    return login_success;   // login_success �� ��ȯ
}