//2151753 彭坤宇 计科
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<io.h>
#include<conio.h>
#include"cmd_console_tools.h"
#include"90-b3.h"
using namespace std;
#define length 25
void print_board(int line) {
	cct_showstr(113, 3, "请选择关卡");
	cct_showstr(112, 4, "╔════╗"); 
	for (int i = 0; i <= min(line,length); i++) {
		cct_showstr(112, 5+i, "║");
		cct_showstr(122, 5+i, "║");
	}
	cct_showstr(112, 5+ min(line,length), "╚════╝");
}
//打印外边框
void print_inline(char num_name[][30],int begin,int num) {
	int j = 0;
	for (int i = begin; i < begin + min(num,length); i++,j++) {
		cct_showstr(114, 5 + j, num_name[i]);
	}
}
//打印内部数组
int keychoose(char num_name[][30],int num) {
	cct_setcursor(3);
	cct_showstr(114, 5, num_name[0],7,0);
	int choose = 0;
	int stage = 0;
	while (1) {
		int ch1 = _getch();
		if (ch1 == 224) {
			int ch2 = _getch();
			if ( ch2 == 72 && stage > 0) {
				cct_showstr(114, (5 + stage), num_name[choose], 0, 7);
				cct_showstr(114, (4 + stage), num_name[choose - 1], 7, 0);
				choose --;
				stage --;
			}
			else if (ch2 == 72 && stage == 0 && choose > 0) {
				print_inline(num_name, choose - 1,num);
				cct_showstr(114, 5, num_name[choose - 1], 7, 0);
				choose--;
			}
			if  (ch2 == 80 && stage < min(num, length)-1) {
				cct_showstr(114, (5 + stage), num_name[choose], 0, 7);
				cct_showstr(114, (6 + stage), num_name[choose + 1], 7, 0);
				choose ++;
				stage ++;
			}
			else if (ch2 == 80 && stage == min(num, length)-1 && choose < num-1) {
				print_inline(num_name, choose - min(num, length)+2,num);
				cct_showstr(114, 4 + min(num, length), num_name[choose + 1], 7, 0);
				choose++;
			}
		}
		if (ch1 == 13) {
			return choose;
		}
		if (ch1 == 27)
			return -1;
	}
	return 0;
}
char* the_popmenu() {
	char ori_name[200][30]; 
	//未删改前缀的数据
	int num = 0;
	char num_name[200][30];
	read_the_file(ori_name,num);
	if (num == 0) {
		cout << "没有符合的关卡存在" << endl;
		return NULL;
	}
	delet_wrong(ori_name, num);
	change_to_num(ori_name, num_name, num);
	print_board(num);
	print_inline(num_name,0,num);
	int choose=keychoose(num_name,num);
	if (choose == -1)
		return NULL;
	return ori_name[choose];
}