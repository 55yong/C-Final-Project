#include "main.h"

void border() {
	for (int i = 0; i < 78; i++) {		// ���Ʒ� �׵θ��� ����� �ݺ���
		gotoxy(i, 0);
		printf("��");

		gotoxy(i, 19);
		printf("��");
	}
	for (int i = 0; i < 20; i++) {		// �¿� �׵θ��� ����� �ݺ���
		gotoxy(0, i);
		printf("��");

		gotoxy(78, i);
		printf("��");
	}
}