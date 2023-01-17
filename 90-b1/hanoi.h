//2157153 ������ �ƿ�
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
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

