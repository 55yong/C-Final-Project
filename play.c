#include "main.h"

void play(int music, int* NOTE_COORD, int* NOTE, int* DELAY, int* hit, int* point, int* combo, int* life) {
	system("cls");										// ȭ�� �ʱ�ȭ
	music_select(music);								// �Ű������� ���� music ������ music_select �Լ��� ���� ������ �����ϰ� ��
	int note_size = music_note(music, NOTE, DELAY);		// �Ű������� ���� music ������ NOTE �迭�� music_note �Լ��� ���� ���ǿ� �´� ��Ʈ�� �������� ��

	for (int i = 0; i < note_size; i++) {
		if (*life == 0) {								// ����� 0�� �Ǹ�
			exit_to_main(point, 0);						// exit_to_main �Լ� ȣ��
			return;										// play �Լ� ����
		}

		for (int y = 2; y < 17; y++) {					// y��ǥ�� 2 ~ 17���� ���� �� ���� ����
			int x = NOTE[i];
			map(point, combo, life);					// map() �Լ��� ȣ���Ͽ� �� ����
			user_input(NOTE_COORD, hit, point, combo);	// ���� �Է��� ó���� �� �ִ� �Լ� ȣ��
			gotoxy(x, y);
			printf("���");								// ��Ʈ ���
			gotoxy(x, y - 1);
			printf("  ");								// ������ ����� ��Ʈ ����

			switch (y) {
			case 15:
				note_value_change(x, y, NOTE_COORD, hit, point, combo, life);
				break;
			case 16:
				if (note_value_change(x, y, NOTE_COORD, hit, point, combo, life) == 1) break;
				break;
			}
			Sleep(DELAY[i]);							// DELAY[i]�� ��� ������ŭ �޽� �� �ٽ� �ڵ� ����
		}
		if (*life != 0 && i == note_size - 1) {			// ���� ����� 0�� �Ǳ� ���� ��� ��Ʈ�� ������
			exit_to_main(point, 1);						// exit_to_main �Լ� ȣ��
			return;										// play �Լ� ����
		}
	}
}
