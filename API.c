#include "main.h"

void CursorView() {
    CONSOLE_CURSOR_INFO cursorInfo = { 0 };
    cursorInfo.dwSize = 1;          // Ä¿¼­ ±½±â
    cursorInfo.bVisible = FALSE;    //Ä¿¼­ Visible TRUE(º¸ÀÓ) FALSE(¼û±è)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
 
void SetColor(int color)  { 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearBuffer() {
    while (getchar() != '\n');
}