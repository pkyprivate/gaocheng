//2151753 ������ �ƿ�
#include<iostream>
#include<iomanip>
#include<queue>
#include<string>
#include <conio.h>
#include"90-b2.h"
#include"cmd_console_tools.h"
using namespace std;
void print(int s[11][11], int line, int row,int choose) {
	for (int i = 0; i <= row; i++) {
		if (i == 0)
			cout << setw(3) << "|";
		else
			cout << setw(3) << i;
	}
	cout<<endl << "--+" << setfill('-') << setw(3 * row + 1) << "-" << setfill(' ') << endl;
	for (int i = 1; i <= line; i++) {
		for (int j = 0; j <= row; j++) {
			if (j == 0)
				cout << char('A' + i - 1) << " |";
			else {
				if (s[i][j] != 0) {
					if (choose == 1) {
						cout << "  ";
						cct_setcolor(14, s[i][j]);
						cout << s[i][j];
						cct_setcolor(0);
					}
					if (choose == 2) {
						cout << setw(3) << "*";
					}
					if (choose == 3) {
						if (s[i][j] <0) {
							if (s[i][j] == -10)
								s[i][j] = 0;
							else
								s[i][j] = -s[i][j];
							cout << "  ";
							cct_setcolor(14, 3);
							cout << s[i][j];
							cct_setcolor(0);
						}
						else
							cout << setw(3) << s[i][j];
					}
				}
				else 
					cout << setw(3) << s[i][j];
			}
		}
		cout << endl;
	}
}
//���ͼ��
void nextthree(int *next) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 3; i++) {
		next[i] = rand() % 7 + 1;
	}
}
//Ԥ��ʣ����������
void start_input(int s[11][11],int line,int row, char t[3]) {
	cout << "��������+��ĸ����ʽ[����c2]����Ҫ�ƶ���ľ�������:";
	int x, y;
	cct_getxy(x, y);
	while (1) {
		cin.getline(t, 3, '\n');
		atoA(t);
		if (t[0] >= 'A' && t[0] < 'A' + line && t[1]>'0' && t[1] <= row+'0') {
			if (s[t[0] - 'A' + 1][t[1]-'0'] != 0)
				break;
			else {
				cout << "��ʼλ��Ϊ�գ�����������" << endl;
				cct_gotoxy(x, y);
				cout << "              ";
				cct_gotoxy(x, y);
			}
		}
		else {
			cout << "�����������������" << endl;
			cct_gotoxy(x, y);
			cout << "                     ";
			cct_gotoxy(x, y);
		}
	}
	cout << "����Ϊ" << t[0] << "��" << t[1] << "��            " << endl;
}
//�������
void end_input(int s[11][11], int line, int row,char t[3])
{
	cout << "��������+��ĸ����ʽ[����c2]����Ҫ�ƶ����Ŀ������:";
	int x, y;
	cct_getxy(x, y);
	while (1) {
		cin.getline(t, 3,'\n');
		atoA(t);
		if (t[0] >= 'A' && t[0] < 'A' + line && t[1]>'0' && t[1] <= row + '0') {
			if (s[t[0] - 'A' + 1][t[1]-'0'] == 0)
				break;
			else {
				cout << "Ŀ��λ�÷ǿգ�����������" << endl;
				cct_gotoxy(x, y);
				cout << "              ";
				cct_gotoxy(x, y);
			}
		}
		else {
			cout << "�����������������" << endl;
			cct_gotoxy(x, y);
			cout << "              ";
			cct_gotoxy(x, y);
		}
	}
	cout << "����Ϊ" << t[0] << "��" << t[1] << "��           " << endl;
}
//�յ�����
int  DFS(int start_x,int start_y,int end_x,int end_y,int s1[11][11],int s2[11][11],int line,int row) {
	if (start_x - 1 > 0 && s1[start_x - 1][start_y ] == 0) {
		s1[start_x - 1][start_y] = -10;
		s2[start_x - 1][start_y ] = 1;
		if (start_x-1 == end_x && start_y == end_y)
			return 1;
		else {
			int check=DFS(start_x - 1, start_y, end_x, end_y, s1, s2,line,row);
			if (!check) {
				s2[start_x - 1][start_y] = 0;
				s1[start_x - 1][start_y] = 0;
			}
			else
				return 1;
		}
	}
	if (start_x +1<=line && s1[start_x + 1][start_y ] == 0) {
		s1[start_x + 1][start_y] = -10;
		s2[start_x + 1][start_y ] = 1;
		if (start_x+1 == end_x && start_y == end_y)
			return 1;
		else {
			int check = DFS(start_x + 1, start_y, end_x, end_y, s1, s2, line, row);
			if (!check) {
				s1[start_x + 1][start_y] = 0;
				s2[start_x + 1][start_y] = 0;
			}
			else
				return 1;
		}
	}
	if (start_y+1<=row&&s1[start_x ][start_y +1 ] == 0) {
		s1[start_x][start_y + 1] = -10;
		s2[start_x ][start_y +1] = 1;
		if (start_x == end_x && start_y+1 == end_y)
			return 1;
		else {
			int check= DFS(start_x, start_y + 1, end_x, end_y, s1, s2, line, row);
			if (!check) {
				s2[start_x][start_y + 1] = 0;
				s1[start_x][start_y + 1] = 0;
			}
			else
				return 1;
		}
	}
	if (start_y-1>0&&s1[start_x ][start_y - 1] == 0) {
		s1[start_x][start_y - 1] = -10;
		s2[start_x ][start_y - 1] = 1;
		if (start_x == end_x && start_y-1 == end_y)
			return 1;
		else {
			int check=DFS(start_x, start_y - 1, end_x, end_y, s1, s2, line, row);
			if (!check) {
				s1[start_x][start_y - 1] = 0;
				s2[start_x][start_y - 1] = 0;
			}
			else
				return 1;
		}
	}
	return 0;
}
//̽���Ƿ���·��
void goback(int s[11][11]) {
	for (int i = 0; i < 11; i++) {
		for (int j = 1; j < 11; j++)
			if (s[i][j] == -10)
				s[i][j] = 0;
	}
}
//��·�����ƻ�ʱ���лָ�
int findway(int s1[11][11],char start[3], char end[3],int line,int row,int choose) {
	int s2[11][11];
	reset(s2, line, row);
	s2[start[0] - 'A' + 1][start[1] - '0'] = 1;
	int flag = DFS(start[0] - 'A' + 1, start[1] - '0', end[0] - 'A' + 1, end[1] - '0', s1, s2,line,row);
	if (flag == 1&&choose==2) {
		cout << "���ҽ������" << endl;
		print(s2, line, row, 2);
		cout << endl;
		cout << "�ƶ�·��<��ͬɫ���>" << endl;
		s1[start[0] - 'A' + 1][start[1] - '0'] = -s1[start[0] - 'A' + 1][start[1] - '0'];
		print(s1, line, row, 3);
		return 1;
	}
	if (flag == 1 && (choose == 3||choose==4))
		return 1;
	else { 
		if(flag!=4)
			cout << "�޷��ҵ��ƶ�·��" << endl;
		return 0;
	}
}
//·����ص����
int judge(int s[11][11],int line,int row,int move_x,int move_y,int *p) {
	int score = 0;
	int color = s[move_x][move_y];
	int judge11 = 0, judge12 = 0, judge21 = 0, judge22 = 0;
	int judge31 = 0, judge32=0,judge41 = 0,judge42=0;
	for (int i = 1;; i++) {
		if (move_x - i > 0 && move_y - i > 0 && s[move_x - i][move_y - i] == color)
			judge11++;
		else
			break;
	}
	for (int i = 1;; i++) {
		if (move_x + i <=line && move_y + i <= row && s[move_x + i][move_y + i] == color)
			judge12++;
		else
			break;
	}
	if (judge11 + judge12 > 3) {
		score += (judge11 + judge12 ) * (judge11 + judge12 - 1);
		for (int i = 1; i <= judge11; i++) {
			s[move_x - i][move_y - i] = 0;
		}
		for (int i = 1; i <= judge12; i++) {
			s[move_x + i][move_y + i] = 0;
		}
		*p -= judge11 + judge12;
	}

	for (int i = 1;; i++) {
		if (move_x - i > 0 && move_y + i <= row && s[move_x - i][move_y + i] == color)
			judge21++;
		else
			break;
	}
	for (int i = 1;; i++) {
		if (move_x + i <= line &&move_y-i>0  && s[move_x + i][move_y - i] == color)
			judge22++;
		else
			break;
	}
	if (judge21 + judge22 > 3) {
		score += (judge21 + judge22) * (judge21 + judge22 - 1);
		for (int i = 1; i <= judge21; i++) {
			s[move_x - i][move_y + i] = 0;
		}
		for (int i = 1; i <= judge22; i++) {
			s[move_x + i][move_y - i] = 0;
		}
		*p -= judge21 + judge22;
	}

	for (int i = 1;; i++) {
		if ( move_y + i <= row && s[move_x ][move_y + i] == color)
			judge31++;
		else
			break;
	}
	for (int i = 1;; i++) {
		if (move_y - i > 0 && s[move_x][move_y - i] == color)
			judge32++;
		else
			break;
	}
	if (judge31 + judge32 > 3) {
		score += (judge31 + judge32 - 1) * (judge31 + judge32);
		for (int i = 1; i <= judge31; i++) {
			s[move_x][move_y + i] = 0;
		}
		for (int i = 1; i <= judge32; i++) {
			s[move_x][move_y - i] = 0;
		}
		*p -= judge31 + judge32;
	}

	for (int i = 1;; i++) {
		if (move_x - i > 0&& s[move_x - i][move_y] == color)
			judge41++;
		else
			break;
	}
	for (int i = 1;; i++) {
		if (move_x + i <= line &&s[move_x + i][move_y] == color)
			judge42++;
		else
			break;
	}
	if (judge41 + judge42 > 3) {
		score += (judge41 + judge42 - 1) * (judge41 + judge42);
		for (int i = 1; i <= judge41; i++) {
			s[move_x-i][move_y] = 0;
		}
		for (int i = 1; i <= judge42; i++) {
			s[move_x+i][move_y ] = 0;
		}
		*p -= judge41 + judge42;
	}
	if (score > 0) {
		s[move_x][move_y] = 0;
		(* p)--;
	}
	else
		*p += 3;
	return score;
}
//�ж��Ƿ��������������ֱ�ߺ�б�ߡ�
void addthree(int s[11][11], int next[3],int line,int row) {
	srand((unsigned)time(NULL));
	for (int i = 0; i <= 2; i++) {
		int x = rand() % line + 1;
		int y = rand() % row + 1;
		if (s[x][y] != 0)
			i--;
		else
			s[x][y] = next[i];
	}
}
//������ӽ�ȥ
void choice1(int s[11][11], int line, int row) {
	cout << "��ʼ����" << endl;
	print(s, line, row,1);
	cout << endl;
}
//��ӡ�����
void choice2(int s[11][11], int line, int row) {
	cout << "��ǰ����" << endl;
	print(s, line, row,1);
	cout << endl;
	int next[3];
	//������������
	nextthree(next);
	char start[3], end[3];
    start_input(s, line, row,start);
    end_input(s, line, row,end);
	cout << endl;
	findway(s,start, end,line,row,2);
	cout << endl;
}
//��ӡ60%�ĵ�
void choice3(int s[11][11], int line, int row) {
	int next[3];
	//������������
	int do_nextthree = 1;
	int score = 0;
	int all = 5;
	while (1) {
		cout << "��ǰ����" << endl;
		print(s, line, row, 1);
		cout << endl;
		if(do_nextthree)
		nextthree(next);
		cout << "�������������ɫ�ֱ���:" << " " << next[0] << " " << next[1] << " " << next[2] << endl;
		char start[3], end[3];
		start_input(s, line, row, start);
		end_input(s, line, row, end);
		cout << endl;
		int flag = findway(s, start, end, line, row, 3);
		goback(s);
		if (flag == 1) {
			s[end[0] - 'A' + 1][end[1] - '0'] = s[start[0] - 'A' + 1][start[1] - '0'];
			s[start[0] - 'A' + 1][start[1] - '0'] = 0;
			int add=judge(s,line,row, end[0] - 'A' + 1, end[1] - '0',&all);
			score += add;
			if (add == 0) {
				addthree(s, next, line, row);
				do_nextthree = 1;
			}
			else {
				do_nextthree = 0;
			}
			cout << "�ƶ��������<��ͬɫ��ʶ>" << endl;
			print(s, line, row, 1);
			cout << "���ε÷�:" << add << "  " << "�ܵ÷�:" << score << endl << endl;
		}
		if (all == line * row) {
			cout << "��Ϸ��������ĵ÷�Ϊ��" << score << endl;
			break;
		}
	}
}
//�������ڲ�����С��Ϸ


