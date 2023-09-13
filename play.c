#include "main.h"

void play(int music, int* NOTE_COORD, int* NOTE, int* DELAY, int* hit, int* point, int* combo, int* life) {
	system("cls");										// 화면 초기화
	music_select(music);								// 매개변수로 받은 music 변수를 music_select 함수로 보내 음악을 선택하게 함
	int note_size = music_note(music, NOTE, DELAY);		// 매개변수로 받은 music 변수와 NOTE 배열을 music_note 함수로 보내 음악에 맞는 노트를 가져오게 함

	for (int i = 0; i < note_size; i++) {
		if (*life == 0) {								// 목숨이 0이 되면
			exit_to_main(point, 0);						// exit_to_main 함수 호출
			return;										// play 함수 종료
		}

		for (int y = 2; y < 17; y++) {					// y좌표가 2 ~ 17보다 작을 때 동안 루프
			int x = NOTE[i];
			map(point, combo, life);					// map() 함수를 호출하여 맵 생성
			user_input(NOTE_COORD, hit, point, combo);	// 유저 입력을 처리할 수 있는 함수 호출
			gotoxy(x, y);
			printf("■■");								// 노트 출력
			gotoxy(x, y - 1);
			printf("  ");								// 그전에 출력한 노트 삭제

			switch (y) {
			case 15:
				note_value_change(x, y, NOTE_COORD, hit, point, combo, life);
				break;
			case 16:
				if (note_value_change(x, y, NOTE_COORD, hit, point, combo, life) == 1) break;
				break;
			}
			Sleep(DELAY[i]);							// DELAY[i]에 담긴 정수만큼 휴식 후 다시 코드 실행
		}
		if (*life != 0 && i == note_size - 1) {			// 만약 목숨이 0이 되기 전에 모든 노트를 쳤으면
			exit_to_main(point, 1);						// exit_to_main 함수 호출
			return;										// play 함수 종료
		}
	}
}
