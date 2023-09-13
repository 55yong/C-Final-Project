#include "main.h"

int main() {
	system("title RHYTHM GAME");				// ���α׷� ���� �� ���� �� Ÿ��Ʋ ����
	system("mode con: cols=80 lines=20");		// cmd â ũ�⸦ Į�� 80 ���� 20���� ����
	system("COLOR 0F");							// �ܼ� �۲� ������ ������� ����
	CursorView();								// ���α׷� ���� �� �����̴� Ŀ�� ����

	while (1) {	
		int NOTE_COORD[4] = { 0 };				// ��Ʈ �ν��� ó���� ����
		int NOTE[700] = { 0 };					// ��Ʈ ����� ���� �迭
		int DELAY[700] = { 0 };					// ��Ʈ ��� �� �����̸� ������ �� ������ �����ϴ� �迭
		int hit = 0;							// ��Ʈ�� �ƴ��� �ν��� ����
		int point = 0;							// ������ ���� ����
		int combo = 0;							// �޺��� ���� ����
		int life = 10;					 		// ����� ���� ����

		int menu_select = menu1();				// menu1�� �ҷ����� POS���� return�޾� select ������ ����

		if (menu_select == 1) {					// menu_select���� 1�� ���
			int login_success = login();		// �α��� �Լ� ȣ�� �� login_success ���� return ����
			if (!login_success) {				// �α��ο� �������� ���
				continue;						// �ٽ� ����ȭ������ ����
			}
			else {								// �α��ο� �������� ���
				int music = menu2();			// menu2�� ȣ�� �� POS���� return�޾� music ������ ����
				play(music, NOTE_COORD, NOTE, DELAY, &hit, &point, &combo, &life);	// play�Լ� ȣ��(music ������ �Ű������� ���)
			}
		}
		else if (menu_select == 2) {			// menu_select���� 2�� ���
			regist();							// ȸ�� ���� �Լ� ȣ��
		}
		else if (menu_select == 3) {			// menu_select���� 3�� ���
			rank();								// ��ũ ��� �Լ� ȣ��
		}
		else if (menu_select == 4) {			// menu_select���� 4�� ���
			end();
		}
	}
	return 0;
}