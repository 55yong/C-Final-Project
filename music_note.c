#include "main.h"

int music_note(int music, int* NOTE, int* DELAY) {

	switch (music) {
	case 0:
		music1(NOTE, DELAY);
		return 625;
		break;
	case 1:
		music2(NOTE, DELAY);
		return 625;
		break;
	case 2:
		music3(NOTE, DELAY);
		return 625;
		break;
	case 3:
		music4(NOTE, DELAY);
		return 625;
		break;
	}
	return 0;
}
