//2151753 彭坤宇 计科
#include<iostream>
#include<iomanip>
#include<string>
#include <conio.h>
#include<Windows.h>
#include"90-b2.h"
#include"cmd_console_tools.h"
#define speed 100
using namespace std;

void print_graph_easy(int s[11][11], int line, int row) {
	cct_setcolor(15, 0);
	cout << "╔";
	for (int i = 1; i <= row; i++)
		cout << "═"; 
	cout<< "╗" << endl;
	for (int i = 1; i <= line; i++) {
		for (int j = 0; j <= row+1; j++) {
			if (j == row + 1|| j == 0)
				cout << "║";
			else {
				if (s[i][j] == 0)
					cout << "  ";
				else {
					cct_setcolor(s[i][j], s[i][j]-2);
					cout << "○";
					cct_setcolor(15, 0);
				}
			}
		}
		cout << endl;
	}
	cout<< "╚";
	for (int i = 1; i <= row; i++)
		cout << "═";
	cout << "╝" << endl;
	cct_setcolor(0);
}
//打印图形化界面（无中间线版)
void print_graph_diffcult(int s[11][11], int line, int row) {
	cct_gotoxy(0, 1);
	cct_setcolor(15, 0);
	cout << "╔";
	for (int i = 1; i <= row-1; i++)
		cout << "═╦";
	cout << "═╗" << endl;
	for (int i = 1; i <= line; i++) {
		for (int j = 0; j <= row; j++) {
			if ( j == 0)
				cout << "║";
			else {
				if (s[i][j] == 0)
					cout << "  ║";
				else {
					cct_setcolor(s[i][j], s[i][j] - 2);
					cout << "○";
					cct_setcolor(15, 0);
					cout << "║";
				}
			}
		}
		cout << endl;
		if (i != line) {
			for (int j = 0; j <= 2 * row; j++) {
				if (j == 0)
					cout << "╠";
				else if (j == 2 * row)
					cout << "╣";
				else if (j % 2 == 0) {
					cout << "╬";
				}
				else
					cout << "═";
			}
			cout << endl;
		}
	}
	cout << "╚";
	for (int i = 1; i <= row-1; i++)
		cout << "═╩";
	cout << "═╝" << endl;
	cct_setcolor(0);
}
//打印图形化界面（有中间线版)
void print_up(int x,int y,int color) {
	cct_showstr(y, x, "  ", 15, 0);
	cct_showstr(y, x-1, "○", color, color - 2);
	Sleep(speed);
	cct_showstr(y, x-1, "═", 15, 0);
	cct_showstr(y, x - 2, "○", color, color - 2);
	Sleep(speed);
	cct_setcolor(0);
}
//向上移动
void print_down(int x, int y, int color) {
	cct_showstr(y, x, "  ", 15, 0);
	cct_showstr(y, x + 1, "○", color, color - 2);
	Sleep(speed);
	cct_showstr(y, x + 1, "═", 15, 0);
	cct_showstr(y, x + 2, "○", color, color - 2);
	Sleep(speed);
	cct_setcolor(0);
}
//向下移动
void print_left(int x, int y, int color) {
	cct_showstr(y, x, "  ", 15, 0);
	cct_showstr(y-2, x , "○", color, color - 2);
	Sleep(speed);
	cct_showstr(y-2, x, "║", 15, 0);
	cct_showstr(y-4, x, "○", color, color - 2);
	Sleep(speed);
	cct_setcolor(0);
}
//向左移动
void print_right(int x, int y, int color) {
	cct_showstr(y, x, "  ", 15, 0);
	cct_showstr(y+ 2, x, "○", color, color - 2);
	Sleep(speed);
	cct_showstr(y + 2, x, "║", 15, 0);
	cct_showstr(y + 4, x, "○", color, color - 2);
	Sleep(speed);
	cct_setcolor(0);
}
//向右移动
void find_next_step(int s[11][11], int x, int y, int line,int row) {
	int start_x = int(x / 2);
	int start_y = int((y + 3) / 4);
	int color = s[start_x][start_y];
	while (1) {
		int flag = 1;
		if(start_x-1>0&&s[start_x - 1][start_y]==-10){
			print_up(x, y,color);
			s[--start_x][start_y] = 0;
			x -= 2;
			flag = 0;
			continue;
		}
		if (start_x +1<=line && s[start_x +1][start_y] == -10){
			print_down(x, y, color);
			s[++start_x][start_y] = 0;
			x += 2;
			flag = 0;
			continue;
		}
		if (start_y- 1 > 0 && s[start_x ][start_y-1] == -10){
			print_left(x, y, color);
			s[start_x ][--start_y] = 0;
			y -= 4;
			flag = 0;
			continue;
		}
		if (start_y+1<=row && s[start_x][start_y+1] == -10){
			print_right(x, y, color);
			s[start_x ][++start_y] = 0;
			y += 4;
			continue;
			flag = 0;
		}
		if (flag)
			break;
	}
}
//寻找移动的路径
int show_position_move(int s[11][11],int line, int row,int &move_x,int &move_y) {
	int now_x, now_y;
	int mouse, key;
	cct_setcursor(3);
	int begin_x=1,begin_y=1;
	int check = 1;
	while (1) {
		cct_read_keyboard_and_mouse(now_x, now_y, mouse, key, key);
		if (now_x < 4* row + 1 && now_x>1 && now_y > 1 && now_y < 2 * line + 1) {
			clear(line);
			cout << "[当前光标] " << char(int(now_y / 2) - 1 + 'A') 
			<< "行" << int((now_x + 3) / 4) << "列";
		}
		if (mouse == 0x0008) {
			cout << endl;
			break;
		}
		if (mouse == 0x0002 && s[int(now_y / 2)][int((now_x + 3) / 4)] != 0){
			if(check==2)
				cct_showstr(begin_x, begin_y, "○", s[int(begin_y / 2)][int((begin_x + 3) / 4)], s[int(begin_y / 2)][int((begin_x + 3) / 4)] - 2);
			if (check == 1)
				check++;
			if(now_x%4==1)
				begin_x = now_x + 1;
			if (now_x % 4 == 3)
				begin_x = now_x -1;
			if (now_x % 4 == 0)
				begin_x = now_x -2;
			if (now_x % 4 == 2)
				begin_x = now_x;
			begin_y = now_y;
			cct_showstr(begin_x, begin_y, "●", s[int(begin_y / 2)][int((begin_x + 3) / 4)], s[int(begin_y / 2)][int((begin_x + 3) / 4)] - 2);
		}
		if (mouse == 0x0002 && s[int(now_y / 2)][int((now_x + 3) / 4)] == 0 && check == 2) {
			char start[3] = { char(int(begin_y / 2) - 1 + 'A') ,char(int((begin_x+3) / 4) + '0'),'\n' };
			char end[3] = { char(int(now_y / 2) - 1 + 'A') ,char(int((now_x + 3) / 4) + '0'),'\n' };
			int flag=findway(s, start, end, line, row, 4);
			if (flag == 0) {
				clear(line);
				cout << "无法从[" << char(int(begin_y / 2) - 1 + 'A') << int((begin_x + 3) / 4) << "]移动到";
				cout << "[" << char(int(now_y / 2) - 1 + 'A') << int((now_x + 3) / 4) <<"]" << endl;
				check = 1;
				continue;
			}
			if (flag == 1) {
				clear(line);
				cout << "可以从[" << char(int(begin_y / 2) - 1 + 'A') << int((begin_x + 3) / 4) << "]移动到";
				cout << "[" << char(int(now_y / 2) - 1 + 'A') << int((now_x + 3) / 4) <<"]" << endl;
				find_next_step(s, begin_y, begin_x,line,row);
				s[int(now_y / 2) ][int((now_x + 3) / 4)] = s[int(begin_y / 2)][int((begin_x + 3) / 4)];
				s[int(begin_y / 2) ][int((begin_x + 3) / 4)]=0;
				move_x = int(now_y / 2);
				move_y = int((now_x + 3) / 4);
				break;
				}
			}
		}
	cct_setcursor(2);
	return mouse;
}
//展示鼠标位置
void set_board() {
	cct_gotoxy(40, 1);
	cct_showstr(40, 1, "╔═════╗", 15, 0 );
	cct_showstr(40, 2, "║得分：    ║", 15, 0);
	cct_showstr(40, 3, "╚═════╝", 15, 0);
	cct_showstr(40, 5, "╔═════╗", 15, 0);
	cct_showstr(40, 6, "║  ║  ║  ║", 15, 0);
	cct_showstr(40, 7, "╚═════╝", 15, 0);
	 cct_showstr(40, 9, "╔═══════════╗", 15, 0);
	cct_showstr(40, 10, "║                      ║", 15, 0);
	cct_showstr(40, 11, "║                      ║", 15, 0);
	cct_showstr(40, 12, "║                      ║", 15, 0);
	cct_showstr(40, 13, "║                      ║", 15, 0);
	cct_showstr(40, 14, "║                      ║", 15, 0);
	cct_showstr(40, 15, "║                      ║", 15, 0);
	cct_showstr(40, 16, "║                      ║", 15, 0);
	cct_showstr(40, 17, "║                      ║", 15, 0);
	cct_showstr(40, 18, "╚═══════════╝", 15, 0);

}
//边界设置
void record_next(int next[3]) {
	for(int i=0;i<3;i++)
	cct_showstr(42+4*i, 6, "○", next[i], next[i] - 2);
	cct_setcolor(0);
}
//图像展示三个
void record_score(int score) {
	cct_showint(48, 2, score, 15, 0);
	cct_setcolor(0);
}
//展示分数
void record_color(int num[8],int del[8], int line, int row) {
	cct_showstr(42, 10, "  ", 15, 0);
	cct_setcolor(15, 0);
	for (int i = 0; i < 8; i++) {
		if(i==0)
			cct_showstr(42, 10 + i, "  ", i, i - 2);
		else
		cct_showstr(42 , 10+i, "○", i, i - 2);
		cct_setcolor(15, 0);
		cout << ":";
		if (num[i] < 10)
			cout << 0;
		cout << num[i] << "/(";
		if ((num[i] * 100) / (line * row) < 10)
			cout << 0;
		cout<<fixed << setprecision(2)<< double( num[i] * 100 )/ (line * row) << "%) 消除-" << del[i];
	}
}
//展示颜色相关
void choice4(int s[11][11], int line, int row) {
	cout << "初始数组" << endl;
	print(s, line, row, 1);
	int ret = getchar();
	the_enter();
	set_cmd(line, 35);
	cout << endl;
	print_graph_easy(s, line, row);
	cout << endl;
}
//选择四
void choice5(int s[11][11], int line, int row) {
	cout << "初始数组" << endl;
	print(s, line, row, 1);
	int ret = getchar();
	the_enter();
	if(row==9)
		set_cmd(2 * line - 1, 39);
	else
		set_cmd(2 * line - 1, 35);
	cout << endl;
	print_graph_diffcult(s, line, row);
	cout << endl;
}
//选择五
void choice6(int s[11][11], int line, int row) {
	if (row == 9)
		set_cmd(2 * line - 1, 39);
	else
		set_cmd(2 * line - 1, 35);
	cout<<"(右键退出)" << endl;
	print_graph_diffcult(s, line, row);
	cct_enable_mouse();
	int x, y;
	show_position_move(s,line, row,x,y);
}
//选择六
void choice7(int s[11][11], int line, int row,int num[8]) {
	int all = 5;
	num[0] = line * row - 5;
	int score = 0;
	int next[3];
	int score_add = 0;
	int del[8] = { 0,0,0,0,0,0,0,0 };
	set_cmd(17,70);
	cout << "(右键退出)" << endl;
	cct_enable_mouse();
	while (1) {
		int move_x, move_y;
		print_graph_diffcult(s, line, row);
		if (!score_add) {
			nextthree(next);
		}
		set_board();
		record_next(next);
		record_score(score);
		record_color(num,del,line,row);
		if (all <= line * row && all >= line * row - 2) {
			clear(line);
			cout << "游戏结束" << endl;
			Sleep(300);
			break;
		}
		int check=show_position_move(s, line, row,move_x,move_y);
		goback(s);
		if (check == 0x0008)
			break;
		int all_before = all;
		int color = s[move_x][move_y];
		score_add = judge(s, line, row, move_x, move_y, &all);
		if (score_add == 0) {
			addthree(s, next, line, row);
			for (int i = 0; i < 3; i++)
				num[next[i]]++;
			num[0] -= 3;
		}
		else
		{
			score += score_add;
			del[color] += (all_before - all);
			num[0] += (all_before - all);
			num[color] -= (all_before - all);
		}
		
	}
	cct_setcolor(0);
}
