#include "main.h"

void music_select(int music) {
	switch (music) {	// music ������ switch ~ case ���ǹ� ����
	case 0:				// music == 0�� ���
		PlaySound(TEXT("./music/REWIND.wav"), NULL, SND_ASYNC);	// 'RE:WIND' ���� ��� (04:31)
		break;
	case 1:				// music == 1�� ���
		PlaySound(TEXT("./music/sweetdreamsmydear.wav"), NULL, SND_ASYNC);	// 'Sweet Dreams, My Dear' ���� ��� (03:13)
		break;
	case 2:				// music == 2�� ���
		PlaySound(TEXT("./music/starlightisland.wav"), NULL, SND_ASYNC);	// '���� ����� ��' ���� ��� (03:27)
		break;
	case 3:
		PlaySound(TEXT("./music/torch.wav"), NULL, SND_ASYNC);	// '����� ȶ��' ���� ��� (03:08)
		break;
	}
}