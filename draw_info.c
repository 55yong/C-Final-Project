#include "main.h"

void draw_info(int POS) {
	switch (POS) {			// menu2���� POS ������ �޾� switch ~ case�� ����
	case 0:					// POS���� 0�� ��� (�뷡 1���� Ŀ���� �ΰ� �ִ� ���) 
		clear_info();
		gotoxy(8, 7);
		printf("����������������");
		gotoxy(8, 8);
		printf("��                          ��");
		gotoxy(8, 9);
		printf("��         BPM : 140        ��");
		gotoxy(8, 10);
		printf("��   Artist : �̼�����̵�  ��");
		gotoxy(8, 11);
		printf("��                          ��");
		gotoxy(8, 12);
		printf("����������������");
		break;
	case 1:					// POS���� 1�� ��� (�뷡 2���� Ŀ���� �ΰ� �ִ� ���) 
		clear_info();
		gotoxy(8, 7);
		printf("����������������");
		gotoxy(8, 8);
		printf("��                          ��");
		gotoxy(8, 9);
		printf("��         BPM : 123        ��");
		gotoxy(8, 10);
		printf("��       Artist : ����      ��");
		gotoxy(8, 11);
		printf("��                          ��");
		gotoxy(8, 12);
		printf("����������������");
		break;
	case 2:					// POS���� 2�� ��� (�뷡 3���� Ŀ���� �ΰ� �ִ� ���) 
		clear_info();
		gotoxy(8, 7);
		printf("����������������");
		gotoxy(8, 8);
		printf("��                          ��");
		gotoxy(8, 9);
		printf("��         BPM :  70        ��");
		gotoxy(8, 10);
		printf("��    Artist : �����ô���   ��");
		gotoxy(8, 11);
		printf("��                          ��");
		gotoxy(8, 12);
		printf("����������������");
		break;
	case 3:					// POS���� 3�� ��� (�뷡 4���� Ŀ���� �ΰ� �ִ� ���) 
		clear_info();
		gotoxy(8, 7);
		printf("����������������");
		gotoxy(8, 8);
		printf("��                          ��");
		gotoxy(8, 9);
		printf("��         BPM : 110        ��");
		gotoxy(8, 10);
		printf("��   Artist : ���� ��â��   ��");
		gotoxy(8, 11);
		printf("��                          ��");
		gotoxy(8, 12);
		printf("����������������");
		break;
	}
}