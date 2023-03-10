//2151753 计科 彭坤宇
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

int menu() {
	printf("1.用I、J、K、L键控制上下左右（大小写均可，边界停止）\n");
	printf("2.用I、J、K、L键控制上下左右（大小写均可，边界回绕）\n");
	printf("3.用箭头键控制上下左右，边界停止\n");
	printf("4.用箭头键控制上下左右，边界回绕\n");
	printf("5.用I、J、K、L键控制上下左右（大小写均可，边界停止）\n");
	printf("6.用I、J、K、L键控制上下左右（大小写均可，边界回绕）\n");
	printf("0.退出\n");
	printf("[请选择0 - 6] ");
	int choose;
	while (1) {
		choose = _getch();
		if (choose == '1' || choose == '2' || choose == '3' || choose == '4' || choose == '0'||choose=='5'||choose=='6')
			return choose;
	}
	if (choose == '0') {
		printf("0\n");
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
				printf(" ");
			}
		}
	}
}

void move_by_ijklno(int choose) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(hout, 35, 9);
	int ch1,ch2=0, x, y;
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
				printf(" ");
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
				printf(" ");
			}
		}
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	int choose;
	choose = menu();
	if (choose == '0') {
		return 0;
	}

	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	/* 此句的作用是调用系统的cls命令清屏 */
	cls(hout);

	/* 显示初始的边框及其中的随机字符 */
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
	//暂停

	gotoxy(hout, 0, 23);
	printf("游戏结束，按回车键返回菜单.");
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
//先通过srand生成伪随机数种子，然后再rand()来生成伪随机数，
//而伪随机数种子的生成过程中可能存在生成相同的可能性，所以可能导致随机数生成相同




