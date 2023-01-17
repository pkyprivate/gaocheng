//2151753 彭坤宇 计科
#include<iostream>
#include<iomanip>
#include<string>
#include <conio.h>
#include <windows.h>
#include"90-b2.h"
#include"cmd_console_tools.h"

using namespace std;

int menu() {
	char x;
	cout << setfill('-') << setw(33) << "-" << endl;
	cout << "1.内部数组，随机生成初始5个球" << endl;
	cout << "2.内部数组，随机生成60%的球，寻找移动路径" << endl;
	cout << "3.内部数组，完整版" << endl;
	cout << "4.画出n*n的框架(无分割线)，随机显示5个球" << endl;
	cout << "5.画出n*n的框架(有分割线)，随机显示5个球" << endl;
	cout << "6.n*n的框架，60%的球，支持鼠标，完成一次移动" << endl;
	cout << "7.cmd图像界面完整版" << endl;
	cout << "0.退出" << endl;
	cout << setfill('-') << setw(33) << "-" << endl;
	cout << setfill(' ');
	cout << "[请选择:] ";
	while (1)
	{
		x = _getch();
		if (x >= 48 && x <= 55) {
			cout << int(x - 48) << endl;
			Sleep(150);
			return int(x - 48);
		}
	}
}
//主菜单函数

void atoA(char* s) {
	for (int i = 0; s[i] != 0; i++) {
		if (s[i] <= 'z' && s[i] >= 'a')
			s[i] = s[i] - 32;
	}
}
//小写转大写
void the_end() {
	cout << "本小题结束，请输入End继续...";
	int x, y;
	cct_getxy(x, y);
	while (1) {
		char s[100];
		cin.getline(s,100);
		atoA(s);
		if(!strcmp(s,"END"))
			break;
		else {
			cct_gotoxy(x, y);
			cout << "            ";
			cct_gotoxy(x, y);
		}
	}
	cct_cls();
}

int main()
{
	int line, row;
	while (1) {
		int choose = menu();
		if (choose == 0)
			return 0;
		else
			line_row(&line, &row);
		base(choose, line, row);
		the_end();
		reset_cmd();
	}
}