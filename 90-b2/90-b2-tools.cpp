//2151753 ������ �ƿ�
#include<iostream>
#include<iomanip>
#include<string>
#include<time.h>
#include <conio.h>
#include"90-b2.h"
#include"cmd_console_tools.h"

using namespace std;
void line_row(int* p1, int* p2) {
	cct_cls();
	while (1) {
		cout << "����������(7-9)" << endl;
		cin >> *p1;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (*p1 > 6 && *p1< 10)
			break;
	}
	while (1) {
		cout << "����������(7-9)" << endl;
		cin >> *p2;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (*p2> 6 && *p2 < 10)
			break;
	}
	cout << endl;
}
//����-����������

void reset(int s[11][11],int line,int row) {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++)
			s[i][j] = 1;
	}
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= row; j++)
			s[i][j] = 0;
	}
}
//��ʼ�����飬ȫ��Ϊ0

void set(int s[11][11], int line, int row, int number,int num[8]) {
	srand((unsigned)time(NULL));
	for (int i = 1; i <= number; i++) {
		int color = rand() % 7 + 1;
	    num[color]++;
		int x = rand() % row + 1;
		int y = rand() % line + 1;
		if (s[y][x] == 0)
			s[y][x] = color;
		else
			i--;
	}
}
//���������ֵ

void the_enter() {
	cout << endl;
	cout << "���س�����ʾͼ��...";
	int x;
	while (1)
	{
		x = _getch();
		if (x ==13)
			break;
	}
}
//����س���

void clear(int line) {
	cct_setcolor(0);
	cct_gotoxy(0, 2 * line + 2);
	cout << "                                       ";
	cct_gotoxy(0, 2 * line + 2);
}
//�����������
void set_cmd(int line, int x) {
	cct_cls();
	cct_setfontsize("������", 32);
	cct_setconsoleborder(x,line+6);
	cout << "��Ļ��" << 6 + line << "��"<<x<<"��";
}
//���ô��ڴ�С

void reset_cmd() {
	cct_setfontsize("������", 20);
	cct_setconsoleborder(98, 24);
}
//�ָ�ԭʼ״̬

void base(int choose,int line, int row) {
	int s[11][11];
	int color[8]={0,0,0,0,0,0,0,0};
	reset(s,line,row);
	if (choose == 1) {
		set(s, line, row, 5,color);
		choice1(s, line, row);
	}
	if (choose == 2) {
		set(s, line, row, int(line * row * 0.6),color);
		choice2(s, line, row);
	}
	if (choose == 3) {
		set(s, line, row, 5,color);
		choice3(s, line, row);
	}
	if (choose == 4) {
		set(s, line, row, 5,color);
		choice4(s, line, row);
	}
	if (choose == 5) {
		set(s, line, row, 5,color);
		choice5(s, line, row);
	}
	if (choose == 6) {
		set(s, line, row, int(line * row * 0.6),color);
		choice6(s, line, row);
		clear(line);
	}
	if (choose == 7) {
		set(s, line, row, 5,color);
		choice7(s, line, row,color);
		clear(line);
	}
}