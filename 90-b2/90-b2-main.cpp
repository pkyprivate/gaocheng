//2151753 ������ �ƿ�
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
	cout << "1.�ڲ����飬������ɳ�ʼ5����" << endl;
	cout << "2.�ڲ����飬�������60%����Ѱ���ƶ�·��" << endl;
	cout << "3.�ڲ����飬������" << endl;
	cout << "4.����n*n�Ŀ��(�޷ָ���)�������ʾ5����" << endl;
	cout << "5.����n*n�Ŀ��(�зָ���)�������ʾ5����" << endl;
	cout << "6.n*n�Ŀ�ܣ�60%����֧����꣬���һ���ƶ�" << endl;
	cout << "7.cmdͼ�����������" << endl;
	cout << "0.�˳�" << endl;
	cout << setfill('-') << setw(33) << "-" << endl;
	cout << setfill(' ');
	cout << "[��ѡ��:] ";
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
//���˵�����

void atoA(char* s) {
	for (int i = 0; s[i] != 0; i++) {
		if (s[i] <= 'z' && s[i] >= 'a')
			s[i] = s[i] - 32;
	}
}
//Сдת��д
void the_end() {
	cout << "��С�������������End����...";
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