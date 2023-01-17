//2157153 彭坤宇 计科
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
int menu(void);
void change(char src, char dst);
void printabcx(void);
char changeatoA(char s);
char findtmp(char src, char dst);
void _input(char* p1, char* p2, char* p3, int* s1, int choose);
void _output(int n, char src, char tmp, char dst, int choose);
void hanoi(int n, char src, char tmp, char dst, int choose);
void reset(char src, int n);
void background(int n, char src, char tmp, char dst, int choose);
int basic(int choose);
void printabcy(int choose);
void speed1(void);
void choice5(void);
void choice6(char src, char dst,int n,int choose);
void moveplate(char src, char dst,int a1,int b1,int c1);
int _inputspecial(char* p1, char* p2);

