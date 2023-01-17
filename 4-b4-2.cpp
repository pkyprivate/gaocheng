//2151753 �ƿ� ������
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�
/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
int menu() {
	cout << "1.��I��J��K��L�������������ң���Сд���ɣ��߽�ֹͣ��" << endl;
	cout << "2.��I��J��K��L�������������ң���Сд���ɣ��߽���ƣ�" << endl;
	cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
	cout << "4.�ü�ͷ�������������ң��߽����" << endl;
	cout << "5.��I��J��K��L�������������ң���Сд���ɣ��߽�ֹͣ��" << endl;
	cout << "6.��I��J��K��L�������������ң���Сд���ɣ��߽���ƣ�" << endl;
	cout << "0.�˳�" << endl;
	cout << "[��ѡ��0 - 6] ";
	int choose;
	while (1) {
		choose = _getch();
		if (choose == '1' || choose == '2' || choose == '3' || choose == '4' || choose == '0'||choose=='5'||choose=='6')
			return choose;
	}
	if (choose == '0') {
		cout << 0 << endl;
		return choose;
	}
}
void move_by_ijkl(int choose) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(hout, 35, 9);
	int ch, x, y;
	x = 35, y = 9;
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 73 || ch == 105) {
				if (choose == '1') {
					if (y > 1) {
						y -= 1;
					}
				}
				if (choose == '2') {
					y -= 1;
					if (y == 0) {
						y = 17;
					}
				}
				gotoxy(hout, x, y);
			}
			if (ch == 74 || ch == 106) {
				if (choose == '1') {
					if (x > 1) {
						x -= 1;
					}
				}
				if (choose == '2') {
					x -= 1;
					if (x == 0) {
						x = 69;
					}
				}
				gotoxy(hout, x, y);
			}
			if (ch == 75 || ch == 107) {
				if (choose == '1') {
					if (y < 17) {
						y += 1;
					}
				}
				if (choose == '2') {
					y += 1;
					if (y == 18) {
						y = 1;
					}
				}
				gotoxy(hout, x, y);
			}
			if (ch == 76 || ch == 108) {
				if (choose == '1') {
					if (x < 69) {
						x += 1;
					}
				}
				if (choose == '2') {
					x += 1;
					if (x == 70) {
						x = 1;
					}
				}
				gotoxy(hout, x, y);
			}
			if (ch == 113 || ch == 81)
				break;
			if (ch == 32) {
				cout << " ";
			}
		}
	}
}

void move_by_ijklno(int choose) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(hout, 35, 9);
	int ch1, ch2 = 0, x, y;
	x = 35, y = 9;
	while (1) {
		if (_kbhit()) {
			ch1 = _getch();
			if (ch1 == 224) {
				ch2 = _getch();
			}
			if (ch1 == 73 || ch1 == 105) {
				if (choose == '5') {
					if (y > 1) {
						y -= 1;
					}
				}
				if (choose == '6') {
					y -= 1;
					if (y == 0) {
						y = 17;
					}
				}
				gotoxy(hout, x, y);
			}
			if (ch1 == 74 || ch1 == 106) {
				if (choose == '5') {
					if (x > 1) {
						x -= 1;
					}
				}
				if (choose == '6') {
					x -= 1;
					if (x == 0) {
						x = 69;
					}
				}
				gotoxy(hout, x, y);
			}
			if (ch1 == 75 || ch1 == 107) {
				if (choose == '5') {
					if (y < 17) {
						y += 1;
					}
				}
				if (choose == '6') {
					y += 1;
					if (y == 18) {
						y = 1;
					}
				}
				gotoxy(hout, x, y);
			}
			if (ch1 == 76 || ch1 == 108) {
				if (choose == '5') {
					if (x < 69) {
						x += 1;
					}
				}
				if (choose == '6') {
					x += 1;
					if (x == 70) {
						x = 1;
					}
				}
				gotoxy(hout, x, y);
			}
			if (ch1 == 113 || ch1 == 81)
				break;
			if (ch1 == 32) {
				cout<<" ";
			}
		}
	}
}
void move_by_arrow(int choose) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(hout, 35, 9);
	int ch, ch1, x, y;
	x = 35, y = 9;
	while (1) {
		if (_kbhit()) {
			ch1 = _getch();
			if (ch1 == 224) {
				ch = _getch();
				if (ch == 72) {
					if (choose == '3') {
						if (y > 1) {
							y -= 1;
						}

					}
					if (choose == '4') {
						y -= 1;
						if (y == 0) {
							y = 17;
						}
					}
					gotoxy(hout, x, y);
				}
				if (ch == 75) {
					if (choose == '3') {
						if (x > 1) {
							x -= 1;
						}
					}
					if (choose == '4') {
						x -= 1;
						if (x == 0) {
							x = 69;
						}
					}
					gotoxy(hout, x, y);
				}
				if (ch == 80) {
					if (choose == '3') {
						if (y < 17) {
							y += 1;
						}
					}
					if (choose == '4') {
						y += 1;
						if (y == 18) {
							y = 1;
						}
					}
					gotoxy(hout, x, y);
				}
				if (ch == 77) {
					if (choose == '3') {
						if (x < 69) {
							x += 1;
						}
					}
					if (choose == '4') {
						x += 1;
						if (x == 70) {
							x = 1;
						}
					}
					gotoxy(hout, x, y);
				}
			}
			if (ch1 == 113 || ch1 == 81)
				break;
			if (ch1 == 32) {
				cout << " ";
			}
		}
	}
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	int choose;
	choose = menu();
	if (choose == '0') {
		return 0;
	}

	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));

	/* �˾�������ǵ���ϵͳ��cls�������� */
	cls(hout);

	/* ��ʾ��ʼ�ı߿����е�����ַ� */
	init_border(hout);
	if (choose == '1' || choose == '2') {
		move_by_ijkl(choose);
	}
	if (choose == '3' || choose == '4') {
		move_by_arrow(choose);
	}
	if (choose == '5' || choose == '6') {
		move_by_ijklno(choose);
	}
	//��ͣ

	gotoxy(hout, 0, 23);
	cout << "��Ϸ���������س������ز˵�.";
	int ch;
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 13) {
				cls(hout);
				main();
				break;
			}
		}

	}
	return 0;
}
//��ͨ��srand����α��������ӣ�Ȼ����rand()������α�������
//��α��������ӵ����ɹ����п��ܴ���������ͬ�Ŀ����ԣ����Կ��ܵ��������������ͬ




