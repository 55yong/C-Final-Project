#include "main.h"

int note_value_change(int x, int y, int* NOTE_COORD, int* hit, int* point, int* combo, int* life) {
	// 29 35 41 47
	switch (y) {				// y 좌표를 이용한 switch ~ case 구문
	case 15:					// y 좌표가 15일 경우 실행
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
	case 16:					// y 좌표가 16일 경우 실행
		NOTE_COORD = 0;
		if (*hit == 0) {		// 위 작업 수행 후 만약 플레이어가 노트를 치지 못했을 경우
			*life -= 1;			// 목숨 1 감소
			*combo = 0;			// 콤보 초기화
		}
		else {
			*point += 1;		// 포인트 + 1
			*combo += 1;		// 콤보 + 1
			return 1;			// 히트 판정이 났을 경우 1을 return
		}
		break;
	}
	return 0;					// 기본적으로 0을 return
}