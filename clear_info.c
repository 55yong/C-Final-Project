#include "main.h"

void clear_info() {	// system("cls") �Լ��� ����ϸ� ȭ���� �����Ÿ��� �߻��� �� ������ gotoxy() �Լ��� printf() �Լ��� �̿��Ͽ� ���ϴ� �κи� �������� �ٲ�
	for (int i = 7; i <= 12; i++) {
		gotoxy(8, i);
		printf("                              ");
	}
}