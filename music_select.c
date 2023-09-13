#include "main.h"

void music_select(int music) {
	switch (music) {	// music 변수로 switch ~ case 조건문 실행
	case 0:				// music == 0일 경우
		PlaySound(TEXT("./music/REWIND.wav"), NULL, SND_ASYNC);	// 'RE:WIND' 음악 재생 (04:31)
		break;
	case 1:				// music == 1일 경우
		PlaySound(TEXT("./music/sweetdreamsmydear.wav"), NULL, SND_ASYNC);	// 'Sweet Dreams, My Dear' 음악 재생 (03:13)
		break;
	case 2:				// music == 2일 경우
		PlaySound(TEXT("./music/starlightisland.wav"), NULL, SND_ASYNC);	// '별빛 등대의 섬' 음악 재생 (03:27)
		break;
	case 3:
		PlaySound(TEXT("./music/torch.wav"), NULL, SND_ASYNC);	// '멸공의 횃불' 음악 재생 (03:08)
		break;
	}
}