#include "main.h"

void clear_info() {	// system("cls") 함수를 사용하면 화면의 깜빡거림이 발생할 수 있으니 gotoxy() 함수와 printf() 함수를 이용하여 원하는 부분만 공백으로 바꿈
	for (int i = 7; i <= 12; i++) {
		gotoxy(8, i);
		printf("                              ");
	}
}