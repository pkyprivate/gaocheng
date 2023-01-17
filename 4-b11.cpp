//2151753 彭坤宇计科
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量和静态局部变量
   ----------------------------------------------------------------------------------- */
void line1(char x,char y,const char End) {
	if (x != 'A') {
		if ((x == y)&& (End - x)!=0)
			cout <<setfill(' ')<< setw(End - x) << " ";
		cout << x;
		line1(x - 1, y,End);
		cout << x;
	}
	if (x == 'A') {
		if ((x == y) && (End - x) != 0)
			cout << setfill(' ') << setw(End - x) << " ";
		cout << x;
	}
}


void line2(char x, char y, const char End) {
	if (x != End) {
		if ((x == y) && (x != 'A'))
			cout << setfill(' ') << setw(x - 'A')<<" ";
		cout << x;
		line2(x+1,y, End);
		cout << x;
	}
	else {
		if ((x == y) && (x != 'A'))
			cout << setfill(' ') << setw(x - 'A') << " ";
		cout << x;
	}
}
   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
   ***************************************************************************/
void print_tower(char x,const char End,int choose )
{
	if (choose == 1) {
		if ((x - 'A') != 0) {
			print_tower(x - 1, End, choose);
			line1(x, x,End);
			cout << endl;
		}
		else {
			line1(x, x, End);
			cout << endl;
		}
	}
	if (choose == 2) {
		if (x != End) {
			line2(x,x,End);
			cout << endl;
			print_tower(x + 1, End, choose);
		}
		else {
			line2(x, x, End);
			cout << endl;
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}
	const char End = end_ch;
	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw(2 * (end_ch - 'A') + 1) << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔" << endl;
	cout << setfill('=') << setw(2 * (end_ch - 'A') + 1) << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch,End,1);
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << setfill('=')<< setw(2 * (end_ch - 'A') + 1) << "=" << endl;  /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔" << endl;
	cout << setfill('=') << setw(2 * (end_ch - 'A') + 1) << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A', End, 2);
	cout << endl;
	return 0;
}