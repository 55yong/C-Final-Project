#include "main.h"

#define col1 5									// �޴����� gotoxy�� ����� �� ��1�� ���� �ɺ��� ���
#define col2 8									// �޴����� gotoxy�� ����� �� ��2�� ���� �ɺ��� ���
#define col3 11									// �޴����� gotoxy�� ����� �� ��3�� ���� �ɺ��� ���
#define col4 14									// �޴����� gotoxy�� ����� �� ��4�� ���� �ɺ��� ���

int menu2() {
	Sleep(100);									// 100ms �޽� ��
	system("cls");								// ȭ�� �ʱ�ȭ
	border();									// �׵θ� ����

	gotoxy(17, 5);
	printf("���� : Space");

	int POS = 0;								// 0 - �뷡 1��, 1 - �뷡 2��, 2 - �뷡 3��, 3 - �뷡 4��

	while (1) {
		gotoxy(45, col1);						// 22, 9�� �뷡1�� ��ư ����
		printf("RE:WIND");
		gotoxy(45, col2);						// 35, 9�� �뷡2�� ��ư ����
		printf("Sweet Dreams, My Dear");
		gotoxy(45, col3);						// 50, 9�� �뷡3�� ��ư ����
		printf("���� ����� ��");
		gotoxy(45, col4);						// 50, 9�� �뷡3�� ��ư ����
		printf("����� ȶ��");

		if (GetAsyncKeyState(VK_UP)) {			// ���� Ű�� ������ ��
			POS -= 1;							// POS 1 ����
		}
		else if (GetAsyncKeyState(VK_DOWN)) {	// ������ Ű�� ������ ��
			POS += 1;							// POS 1 ����
		}
		else if (GetAsyncKeyState(VK_SPACE)) { // ���͸� ������ ��
			break;								// while�� ����
		}
		if (POS == -1) {						// ���� �÷��̾ ���� Ű�� �ʹ� ���� ������ -1�� �Ǿ��� ���
			POS = 0;							// POS���� 0���� �ٲ���
		}
		else if (POS == 4) {					// ���� �÷��̾ �Ʒ��� Ű�� �ʹ� ���� ������ 4�� �Ǿ��� ���
			POS = 3;							// POS ���� 3�� �ٲ���
		}
		switch (POS) {							// POS�� ���� ������ switch ~ case�� ����
		case 0:									// POS���� 0�� ��� (�뷡 1���� Ŀ���� �ΰ� �ִ� ���)
			draw_info(POS);						// ���� �߾ӿ� �뷡 1�� ���� ������ ǥ��
			SetColor(11);						// �ܼ��� �۲� ������ �ϴû����� ����
			gotoxy(45, col1);					// 45, col1�� ��ư �����
			printf("RE:WIND");
			SetColor(15);						// �ٸ� ��ư���� ������� ������ �� �ֵ��� ���� �纯��	
			break;
		case 1:									// POS���� 1�� ��� (�뷡 2���� Ŀ���� �ΰ� �ִ� ���)
			draw_info(POS);						// ���� �߾ӿ� �뷡 2�� ���� ������ ǥ��
			SetColor(11);						// �ܼ��� �۲� ������ �ϴû����� ����
			gotoxy(45, col2);					// 45, col2�� ��ư �����
			printf("Sweet Dreams, My Dear");
			SetColor(15);						// �ٸ� ��ư���� ������� ������ �� �ֵ��� ���� �纯��
			break;
		case 2:									// POS���� 2�� ��� (�뷡 3���� Ŀ���� �ΰ� �ִ� ���)
			draw_info(POS);						// ���� �߾ӿ� �뷡 3�� ���� ������ ǥ��
			SetColor(11);						// �ܼ��� �۲� ������ �ϴû����� ����
			gotoxy(45, col3);					// 45, col3�� ��ư �����
			printf("���� ����� ��");
			SetColor(15);						// �ٸ� ��ư���� ������� ������ �� �ֵ��� ���� �纯��
			break;
		case 3:									// POS���� 3�� ��� (�뷡 4���� Ŀ���� �ΰ� �ִ� ���)
			draw_info(POS);						// ���� �߾ӿ� �뷡 4�� ���� ������ ǥ��
			SetColor(11);						// �ܼ��� �۲� ������ �ϴû����� ����
			gotoxy(45, col4);					// 45, col4�� ��ư �����
			printf("����� ȶ��");
			SetColor(15);						// �ٸ� ��ư���� ������� ������ �� �ֵ��� ���� �纯��
			break;
		}
		Sleep(100);								// POS ���� ����� �� �ʹ� ������ ������� �ʵ��� 100ms Sleep
	}
	return POS;									// break���� �۵����� �� POS���� return����
}