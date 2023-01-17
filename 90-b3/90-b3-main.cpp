//2151753 彭坤宇 计科

#include<iostream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include"90-b3.h"
#include"cmd_console_tools.h"
using namespace std;

int menu() {
	cout << setw(30) << setfill('-') << '-' << endl;
	cout << "1.显示关卡" << endl;
	cout << "0.退出" << endl;
	cout << setw(30) << setfill('-') << '-' << endl;
	cout << "请选择[0-1] ";
	char x;
	while (1) {
		x = _getch();
		if (x == '0' || x == '1') {
			cout << x;
			Sleep(300);
			break;
		}
	}
	return x - '0';
}

void atoA(char* s) {
	for (int i = 0; s[i] != 0; i++) {
		if (s[i] <= 'z' && s[i] >= 'a')
			s[i] = s[i] - 32;
	}
}
//小写转大写
void the_end() {
	cct_setcolor(0);
	cct_gotoxy(0, 45);
	cout << "本小题结束，请输入End继续...";
	int x, y;
	cct_getxy(x, y);
	while (1) {
		char s[100];
		cin.getline(s, 100);
		atoA(s);
		if (!strcmp(s, "END"))
			break;
		else {
			cct_gotoxy(x, y);
			cout << "            ";
			cct_gotoxy(x, y);
		}
	}
	cct_cls();
}
//输入end
void the_c() {
	cct_setcolor(0);
	cct_gotoxy(0, 45);
	cout << "关卡显示完成，按C/c继续...";
	while (1) {
		char  x;
		x = _getch();
		if (x == 'c' || x == 'C') {
			cout << x;
			break;
		}
	}
	cct_cls();
}
//输入c
int main()
{
	cct_setconsoleborder(130,48);
	while (1) {
		int choose = menu();
		if (choose == 0)
			return 0;
		else {
			cct_cls();
			while (1) {
				char *s;
				s = the_popmenu();
				if (s ==NULL) {
					the_end();
					break;
				}
				char map[20][20];
				int line = 0;
				select_txt(s, map,line);
				print_stage(map,line);
				the_c();
			}
		}
	}
	return 0;
}