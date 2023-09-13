#include "main.h"

void draw_info(int POS) {
	switch (POS) {			// menu2에서 POS 정보를 받아 switch ~ case문 실행
	case 0:					// POS값이 0일 경우 (노래 1번에 커서를 두고 있는 경우) 
		clear_info();
		gotoxy(8, 7);
		printf("■■■■■■■■■■■■■■■");
		gotoxy(8, 8);
		printf("■                          ■");
		gotoxy(8, 9);
		printf("■         BPM : 140        ■");
		gotoxy(8, 10);
		printf("■   Artist : 이세계아이돌  ■");
		gotoxy(8, 11);
		printf("■                          ■");
		gotoxy(8, 12);
		printf("■■■■■■■■■■■■■■■");
		break;
	case 1:					// POS값이 1일 경우 (노래 2번에 커서를 두고 있는 경우) 
		clear_info();
		gotoxy(8, 7);
		printf("■■■■■■■■■■■■■■■");
		gotoxy(8, 8);
		printf("■                          ■");
		gotoxy(8, 9);
		printf("■         BPM : 123        ■");
		gotoxy(8, 10);
		printf("■       Artist : 소향      ■");
		gotoxy(8, 11);
		printf("■                          ■");
		gotoxy(8, 12);
		printf("■■■■■■■■■■■■■■■");
		break;
	case 2:					// POS값이 2일 경우 (노래 3번에 커서를 두고 있는 경우) 
		clear_info();
		gotoxy(8, 7);
		printf("■■■■■■■■■■■■■■■");
		gotoxy(8, 8);
		printf("■                          ■");
		gotoxy(8, 9);
		printf("■         BPM :  70        ■");
		gotoxy(8, 10);
		printf("■    Artist : 누구시더라   ■");
		gotoxy(8, 11);
		printf("■                          ■");
		gotoxy(8, 12);
		printf("■■■■■■■■■■■■■■■");
		break;
	case 3:					// POS값이 3일 경우 (노래 4번에 커서를 두고 있는 경우) 
		clear_info();
		gotoxy(8, 7);
		printf("■■■■■■■■■■■■■■■");
		gotoxy(8, 8);
		printf("■                          ■");
		gotoxy(8, 9);
		printf("■         BPM : 110        ■");
		gotoxy(8, 10);
		printf("■   Artist : 군가 합창단   ■");
		gotoxy(8, 11);
		printf("■                          ■");
		gotoxy(8, 12);
		printf("■■■■■■■■■■■■■■■");
		break;
	}
}