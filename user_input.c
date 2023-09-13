#include "main.h"

#define KEY_D 0x44		// DŰ�� �ƽ�Ű�ڵ� ���� ���� �ɺ��� ��� ����
#define KEY_F 0x46		// FŰ�� �ƽ�Ű�ڵ� ���� ���� �ɺ��� ��� ����
#define KEY_J 0x4A		// JŰ�� �ƽ�Ű�ڵ� ���� ���� �ɺ��� ��� ����
#define KEY_K 0x4B		// KŰ�� �ƽ�Ű�ڵ� ���� ���� �ɺ��� ��� ����

void user_input(int* NOTE_COORD, int* hit, int* point, int* combo) {
	int key = 0;							// �Է¹��� Ű�� ���� ������ ���� ���� ����
	if (GetAsyncKeyState(KEY_D)) {			// DŰ�� ������ key = 1
		key = 1;
	}
	else if (GetAsyncKeyState(KEY_F)) {		// FŰ�� ������ key = 2
		key = 2;
	}
	else if (GetAsyncKeyState(KEY_J)) {		// JŰ�� ������ key = 3
		key = 3;
	}
	else if (GetAsyncKeyState(KEY_K)) {		// KŰ�� ������ key = 4
		key = 4;
	}
	else {									// �ƹ� Ű�� �� ������ ��� key = 0
		key = 0;
	}

	switch (key) {					// �� Ű�� ���� �̺�Ʈ
	case 1:
		if (NOTE_COORD[0] == 1) {
			*hit = 1;				// ��Ʈ ���� O
		}
		else {						// ��Ʈ�� ġ�� ������ ���
			*hit = 0;				// ��Ʈ ���� X
		}
		break;
	case 2:
		if (NOTE_COORD[1] == 1) {
			*hit = 1;				// ��Ʈ ���� O
		}
		else {						// ��Ʈ�� ġ�� ������ ���
			*hit = 0;				// ��Ʈ ���� X
		}
		break;
	case 3:
		if (NOTE_COORD[2] == 1) {
			*hit = 1;				// ��Ʈ ���� O
		}
		else {						// ��Ʈ�� ġ�� ������ ���
			*hit = 0;				// ��Ʈ ���� X
		}
		break;
	case 4:
		if (NOTE_COORD[3] == 1) {
			*hit = 1;				// ��Ʈ ���� O
		}
		else {						// ��Ʈ�� ġ�� ������ ���
			*hit = 0;				// ��Ʈ ���� X
		}
		break;
	default:
		*hit = 0;
	}
}