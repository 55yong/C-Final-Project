#include "main.h"

int note_value_change(int x, int y, int* NOTE_COORD, int* hit, int* point, int* combo, int* life) {
	// 29 35 41 47
	switch (y) {				// y ��ǥ�� �̿��� switch ~ case ����
	case 15:					// y ��ǥ�� 15�� ��� ����
		if (x == 29) {
			NOTE_COORD[0] = 1;
		}
		else if (x == 35) {
			NOTE_COORD[1] = 1;
		}
		else if (x == 41) {
			NOTE_COORD[2] = 1;
		}
		else if (x == 47) {
			NOTE_COORD[3] = 1;
		}
		break;
	case 16:					// y ��ǥ�� 16�� ��� ����
		NOTE_COORD = 0;
		if (*hit == 0) {		// �� �۾� ���� �� ���� �÷��̾ ��Ʈ�� ġ�� ������ ���
			*life -= 1;			// ��� 1 ����
			*combo = 0;			// �޺� �ʱ�ȭ
		}
		else {
			*point += 1;		// ����Ʈ + 1
			*combo += 1;		// �޺� + 1
			return 1;			// ��Ʈ ������ ���� ��� 1�� return
		}
		break;
	}
	return 0;					// �⺻������ 0�� return
}