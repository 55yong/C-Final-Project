#include "main.h"

#define row1 14		// �޴����� gotoxy�� ����� �� ��1�� ���� �ɺ��� ���
#define row2 26		// �޴����� gotoxy�� ����� �� ��2�� ���� �ɺ��� ���
#define row3 41		// �޴����� gotoxy�� ����� �� ��3�� ���� �ɺ��� ���
#define row4 55		// �޴����� gotoxy�� ����� �� ��4�� ���� �ɺ��� ���	

int menu1() {
	system("cls");	// ȭ�� �ʱ�ȭ
	border();		// �׵θ� ����

	int POS = 0;	// 0 - �α���(���ӽ���), 1 - ��ŷ ����, 2 - ���� ����

	SetColor(3);
	gotoxy(row1, 9);						// row1, 9�� �α��� ��ư ����
	printf("�� �α���");
	gotoxy(row2, 9);						// row2, 9�� ȸ�� ���� ��ư ����
	printf("�� ȸ�� ����");
	gotoxy(row3, 9);						// row3, 9�� ��ŷ ���� ��ư ����
	printf("�� ��ŷ ����");
	gotoxy(row4, 9);						// row4, 9�� ���� ���� ��ư ����
	printf("�� ���� ����");
	SetColor(15);

	gotoxy(34, 13);
	printf("���� > ");
	scanf("%d", &POS);

	return POS;									// break���� �۵����� �� POS���� return����
}