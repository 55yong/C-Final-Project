#include "main.h"

int main() {
	system("title RHYTHM GAME");				// 프로그램 시작 시 왼쪽 위 타이틀 변경
	system("mode con: cols=80 lines=20");		// cmd 창 크기를 칼럼 80 라인 20으로 설정
	system("COLOR 0F");							// 콘솔 글꼴 색상을 흰색으로 변경
	CursorView();								// 프로그램 실행 시 깜빡이는 커서 제거

	while (1) {	
		int NOTE_COORD[4] = { 0 };				// 노트 인식을 처리할 변수
		int NOTE[700] = { 0 };					// 노트 출력을 담을 배열
		int DELAY[700] = { 0 };					// 노트 출력 후 딜레이를 몇으로 할 것인지 지정하는 배열
		int hit = 0;							// 노트를 쳤는지 인식할 변수
		int point = 0;							// 점수를 담을 변수
		int combo = 0;							// 콤보를 담을 변수
		int life = 10;					 		// 목숨을 담을 변수

		int menu_select = menu1();				// menu1을 불러오고 POS값을 return받아 select 변수에 저장

		if (menu_select == 1) {					// menu_select값이 1일 경우
			int login_success = login();		// 로그인 함수 호출 후 login_success 값을 return 받음
			if (!login_success) {				// 로그인에 실패했을 경우
				continue;						// 다시 메인화면으로 복귀
			}
			else {								// 로그인에 성공했을 경우
				int music = menu2();			// menu2를 호출 후 POS값을 return받아 music 변수에 저장
				play(music, NOTE_COORD, NOTE, DELAY, &hit, &point, &combo, &life);	// play함수 호출(music 변수를 매개변수로 사용)
			}
		}
		else if (menu_select == 2) {			// menu_select값이 2일 경우
			regist();							// 회원 가입 함수 호출
		}
		else if (menu_select == 3) {			// menu_select값이 3일 경우
			rank();								// 랭크 출력 함수 호출
		}
		else if (menu_select == 4) {			// menu_select값이 4일 경우
			end();
		}
	}
	return 0;
}