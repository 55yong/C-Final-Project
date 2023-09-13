#include "main.h"

#define KEY_D 0x44		// D키의 아스키코드 값을 담은 심볼릭 상수 선언
#define KEY_F 0x46		// F키의 아스키코드 값을 담은 심볼릭 상수 선언
#define KEY_J 0x4A		// J키의 아스키코드 값을 담은 심볼릭 상수 선언
#define KEY_K 0x4B		// K키의 아스키코드 값을 담은 심볼릭 상수 선언

void user_input(int* NOTE_COORD, int* hit, int* point, int* combo) {
	int key = 0;							// 입력받은 키에 대한 정보를 담을 변수 선언
	if (GetAsyncKeyState(KEY_D)) {			// D키가 눌리면 key = 1
		key = 1;
	}
	else if (GetAsyncKeyState(KEY_F)) {		// F키가 눌리면 key = 2
		key = 2;
	}
	else if (GetAsyncKeyState(KEY_J)) {		// J키가 눌리면 key = 3
		key = 3;
	}
	else if (GetAsyncKeyState(KEY_K)) {		// K키가 눌리면 key = 4
		key = 4;
	}
	else {									// 아무 키도 안 눌렸을 경우 key = 0
		key = 0;
	}

	switch (key) {					// 각 키에 대한 이벤트
	case 1:
		if (NOTE_COORD[0] == 1) {
			*hit = 1;				// 히트 판정 O
		}
		else {						// 노트를 치지 못했을 경우
			*hit = 0;				// 히트 판정 X
		}
		break;
	case 2:
		if (NOTE_COORD[1] == 1) {
			*hit = 1;				// 히트 판정 O
		}
		else {						// 노트를 치지 못했을 경우
			*hit = 0;				// 히트 판정 X
		}
		break;
	case 3:
		if (NOTE_COORD[2] == 1) {
			*hit = 1;				// 히트 판정 O
		}
		else {						// 노트를 치지 못했을 경우
			*hit = 0;				// 히트 판정 X
		}
		break;
	case 4:
		if (NOTE_COORD[3] == 1) {
			*hit = 1;				// 히트 판정 O
		}
		else {						// 노트를 치지 못했을 경우
			*hit = 0;				// 히트 판정 X
		}
		break;
	default:
		*hit = 0;
	}
}