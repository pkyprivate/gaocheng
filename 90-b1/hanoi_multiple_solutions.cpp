//2157153 彭坤宇 计科
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include <stdio.h> 
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
int number = 1;
int a[11] = { 0 }, b[11] = { 0 }, c[11] = { 0 };
int ta = 1, tb = 1, tc = 1, speed;

/***************************************************************************
  函数名称：
  功    能：主函数，用来根据输入不同进行调用
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int basic(int choose)
{
    int n;
    char src, tmp, dst;
    if (choose != 5) {
        _input(&src, &tmp, &dst, &n, choose);
    }
    switch (choose) {
        case 1:
        case 2: 
        {
            number = 1;
            hanoi(n, src, tmp, dst, choose);
            break; 
        }
        case 3: 
        {
            for (int i = 0; i <= 10; i++) {
                a[i] = 0;
                b[i] = 0;
                c[i] = 0;
            }
            reset(src, n);
            hanoi(n, src, tmp, dst, choose);
            break; 
        }
        case 4:
        {
            for (int i = 0; i <= 10; i++) {
                a[i] = 0;
                b[i] = 0;
                c[i] = 0;
            }
            reset(src, n);
            cct_cls();
            background(n, src, tmp, dst, choose);
            cct_setcursor(3);
            cct_gotoxy(0, 17);
            cout << "初始:  ";
            printabcx();
            printabcy(choose);
            speed1();
            speed1();
            hanoi(n, src, tmp, dst, choose);
            cct_setcursor(2);
            break;
        }
        case 5:
            choice5();
            break;
        case 6:
            choice5();
            choice6(src, dst,n,choose);
            break;
        case 7:
            choice5();
            choice6(src,dst, n,choose);
            reset(src, n);
            if (n % 2 == 0) {
                moveplate(src, tmp,ta,tb,tc);
            }
            if (n % 2 == 1) {
                moveplate(src, dst,ta,tb,tc);
            }
            break;
        case 8:
        case 9:
            for (int i = 0; i <= 10; i++) {
                a[i] = 0;
                b[i] = 0;
                c[i] = 0;
            }
            reset(src, n);
            cct_cls();
            choice5();
            choice6(src, dst, n, choose);
            background(n, src, tmp, dst, choose);
            cct_setcursor(3);
            cct_gotoxy(0, 33);
            cout << "初始:  ";
            printabcx();
            printabcy(choose);
            if (choose == 8) {
                speed1();
                hanoi(n, src, tmp, dst, choose);
            }
            cct_setcursor(2);
            if (choose == 9) {
                int flag = 0;
                while (1) {
                    char p1, p2;
                    flag=_inputspecial(&p1,&p2);
                    int x=0;
                    if (flag == 1) {
                        cct_gotoxy(0, 35);
                        cout << "游戏中止！" << endl;
                        break;
                    }
                    if (p1 == 'A')
                        x = a[ta - 1];
                    if (p1 == 'B')
                        x = b[tb - 1];
                    if (p1 == 'C')
                        x = c[tc - 1];
                    _output(x, p1, tmp, p2, 9);
                    if (dst == 'A' && ta == n + 1)
                        flag = 2;
                    if (dst == 'B' && tb == n + 1)
                        flag = 2;
                    if (dst == 'C' && tc == n + 1)
                        flag = 2;
                    if (flag == 2) {
                        cct_gotoxy(0, 35);
                        cout << "恭喜成功！" << endl;
                        break;
                    }
                }
            }
            break;
    }
    return number;
}
/***************************************************************************
  函数名称：
  功    能：小写转换为大写
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char changeatoA(char s) {
    if (s == 'A' || s == 'a') {
        s = 'A';
    }
    if (s == 'B' || s == 'b') {
        s = 'B';
    }
    if (s == 'C' || s == 'c') {
        s = 'C';
    }
    return s;
}
/***************************************************************************
  函数名称：
  功    能：寻找中间柱
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char findtmp(char src, char dst) {
    char tmp='0';
    if (src == 'A' && dst == 'B')
        tmp = 'C';
    if (src == 'A' && dst == 'C')
        tmp = 'B';
    if (src == 'B' && dst == 'A')
        tmp = 'C';
    if (src == 'B' && dst == 'C')
        tmp = 'A';
    if (src == 'C' && dst == 'A')
        tmp = 'B';
    if (src == 'C' && dst == 'B')
        tmp = 'A';
    return tmp;
}
/***************************************************************************
  函数名称：
  功    能：数据输入函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void _input(char* p1, char* p2, char* p3, int* s1, int choose) {
    int n;
    char src, tmp, dst;
    while (1) {
        cout << "请输入汉诺塔的层数(1 - 10)" << endl;
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        if (cin.good() == 1 && n > 0 && n < 11) {
            break;
        }
    }
    //层数输入
    while (1)
    {
        cout << "请输入起始柱(A-C)\n";
        cin >> src;
        src = changeatoA(src);
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        if (src == 'A' || src == 'B' || src == 'C')
        {
            cin.ignore(65536, '\n');
            break;
        }
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)\n";
        cin >> dst;
        dst = changeatoA(dst);
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        if (dst == src)
        {
            cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同\n";
            cin.ignore(65536, '\n');
            continue;
        }
        if (dst == 'A' || dst == 'B' || dst == 'C')
        {
            cin.ignore(65536, '\n');
            break;
        }
    }
    //目标柱输入+转换
    tmp = findtmp(src, dst);
    if (choose == 4 || choose == 8) {
        while (1) {
            cout << "请输入移动速度（0-5： 0-按回车单步显示 1-延时最长 5-延时最短）" << endl;
            cin >> speed;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(65536, '\n');
            }
            if (speed<6 && speed>-1) {
                break;
            }
        }
    }
    *s1 = n;
    *p1 = src, * p2 = tmp, * p3 = dst;
}
/***************************************************************************
  函数名称：
  功    能：主输出函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void _output(int n, char src, char tmp, char dst, int choose)
{
    switch (choose) {
        case 1:
            cout << n << "# " << src << "---->" << dst << endl;
            break;
        case 2:
        case 3:
            cout << "第" << setfill(' ') << setw(4) << number << "步( " << n << "# " << src << "---->" << dst << ")";
            if (choose == 3) {
                change(src, dst);
                cout << " ";
                printabcx();
            }
            cout << endl;
            break;
        case 4:
            cct_gotoxy(0, 17);
            cout << "第" << setfill(' ') << setw(4) << number << "步( " << n << "# " << src << "---->" << dst << ")";
            change(src, dst);
            printabcx();
            printabcy(choose);
            speed1();
            cout << endl;
            break;
        case 8:
        case 9:
            int a0 = ta, b0 = tb, c0 = tc;
            cct_gotoxy(0, 33);
            cout << "第" << setfill(' ') << setw(4) << number << "步( " << n << "# " << src << "---->" << dst << ")";
            change(src, dst);
            printabcx();
            printabcy(choose);
            moveplate(src, dst,a0,b0,c0);
            if(choose==8)
            speed1();
    }
}
/***************************************************************************
  函数名称：
  功    能：汉诺塔主递归函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, int choose)
{
    if (n > 1)
        hanoi(n - 1, src, dst, tmp, choose);
    _output(n, src, tmp, dst, choose);
    number++;
    if (n > 1)
        hanoi(n - 1, tmp, src, dst, choose);
}
/***************************************************************************
  函数名称：
  功    能：初始化设置
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void reset(char src,int n) {
    ta = 1, tb = 1, tc = 1;
    if (src == 'A') {
        for (int i = n; i >= 1; i--) {
            a[ta] = i;
            ta++;
        }
    }
    if (src == 'B') {
        for (int i = n; i >= 1; i--) {
            b[tb] = i;
            tb++;
        }
    }
    if (src == 'C') {
        for (int i = n; i >= 1; i--) {
            c[tc] = i;
            tc++;
        }
    }
    number = 1;
}
/***************************************************************************
  函数名称：
  功    能：背景部分的输入
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void background(int n, char src, char tmp, char dst, int choose)
{
    int i;
    if (choose == 8||choose==9)
        cct_gotoxy(0, 15);
    for (i = 1; i <= 12; i++)
        cout << endl;;
    for (i = 1; i <= 9; i++)
        cout << ' ';
    cout << "=========================" << endl;
    cout << setfill(' ') << setw(12) << 'A';
    cout << setfill(' ') << setw(10) << 'B' << setw(10) << 'C';
    cout << endl;
    cout << endl;
    cout << endl;
}
/***************************************************************************
  函数名称：
  功    能：每一次移动时每个柱子上的变换
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void change(char src, char dst) {
    if (src == 'A' && dst == 'B')
        b[tb++] = a[--ta];
    if (src == 'A' && dst == 'C')
        c[tc++] = a[--ta];
    if (src == 'B' && dst == 'A')
        a[ta++] = b[--tb];
    if (src == 'B' && dst == 'C')
        c[tc++] = b[--tb];
    if (src == 'C' && dst == 'B')
        b[tb++] = c[--tc];
    if (src == 'C' && dst == 'A')
        a[ta++] = c[--tc];
}
/***************************************************************************
  函数名称：
  功    能：横向柱子上的圆盘的输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void printabcx() {
    cout << "A:";
    for (int i = 1; i < ta; i++)
        cout << setw(2) << a[i];
    for (int i = 11; i > ta; i--)
        cout << "  ";
    cout << ' ';
    cout << "B:";
    for (int i = 1; i < tb; i++)
        cout << setw(2) << b[i];
    for (int i = 11; i > tb; i--)
        cout << "  ";
    cout << ' ';
    cout << "C:";
    for (int i = 1; i < tc; i++)
        cout << setw(2) << c[i];
    for (int i = 11; i > tc; i--)
        cout << "  ";
}
/***************************************************************************
  函数名称：
  功    能：延时函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void speed1() {
    if (speed == 0) {
        while (1) {
            int enter;
            enter = getchar();
            if (enter == 10)
                break;
        }
    }
    else {
        Sleep((6 - speed) * 70);
    }
}
/***************************************************************************
  函数名称：
  功    能：竖直方向上的柱子的输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void printabcy(int choose) {
    for (int i = ta; i <= 10; i++)
    {
        if (choose == 4) {
            cct_gotoxy(11, 12 - i);
        }
        if (choose == 8) {
            cct_gotoxy(11, 27 - i);
        }
        if (choose == 9) {
            cct_gotoxy(11, 27 - i);
        }
        cout << ' ';
    }
    for (int i = 1; i < ta; i++)
    {
        if (choose == 4) {
            cct_gotoxy(10, 12 - i);
        }
        if (choose == 8) {
            cct_gotoxy(10, 27 - i);
        }
        if (choose == 9) {
            cct_gotoxy(10, 27 - i);
        }
        cout << setfill(' ') << setw(2) << a[i];
    }
    for (int i = tb; i <= 10; i++)
    {
        if (choose == 4) {
            cct_gotoxy(21, 12 - i);
        }
        if (choose == 8) {
            cct_gotoxy(21, 27 - i);
        }
        if (choose == 9) {
            cct_gotoxy(21, 27 - i);
        }
        cout << ' ';
    }
    for (int i = 1; i < tb; i++)
    {
        if (choose == 4) {
            cct_gotoxy(20, 12 - i);
        }
        if (choose == 8) {
            cct_gotoxy(20, 27 - i);
        }
        if (choose == 9) {
            cct_gotoxy(20, 27 - i);
        }
        cout << setfill(' ') << setw(2) << b[i];
    }
    for (int i = tc; i <= 10; i++)
    {
        if (choose == 4) {
            cct_gotoxy(31, 12 - i);
        }
        if (choose == 8) {
            cct_gotoxy(31, 27 - i);
        }
        if (choose == 9) {
            cct_gotoxy(31, 27 - i);
        }
        cout << ' ';
    }
    for (int i = 1; i < tc; i++)
    {
        if (choose == 4) {
            cct_gotoxy(30, 12 - i);
        }
        if (choose == 8) {
            cct_gotoxy(30, 27 - i);
        }
        if (choose == 9) {
            cct_gotoxy(30, 27 - i);
        }
        cout << setfill(' ') << setw(2) << c[i];
    }
}
/***************************************************************************
  函数名称：
  功    能：画出三个空柱子
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void choice5() {
    cct_cls();
    cct_showch(1, 15, ' ', 14,14, 23);
    cct_showch(33, 15, ' ', 14,14, 23);
    cct_showch(65, 15, ' ', 14,14, 23);
    for (int i =15 ; i >2 ; i--) {
        cct_showch(12, i, ' ', 14, 14);
        cct_showch(44, i, ' ', 14, 14);
        cct_showch(76, i, ' ', 14, 14);
        Sleep(100);
    }
    cct_setcolor(0);
}
/***************************************************************************
  函数名称：
  功    能：画出初始的位置
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void choice6(char src,char dst, int n,int choose) {
    cct_gotoxy(0, 0);
    cout << "从 " << src << " 移动到" << dst << " ,共" << n << "层";
    if (choose == 8)
        cout << ",延时设置为" << speed;
    if (src == 'A') {
        for (int i = n; i > 0; i--) {
            cct_showch(12-i, 14-n+i, ' ', i,i, 2 * i + 1);
            Sleep(200);
        }
    }
    if (src == 'B') {
        for (int i = n; i > 0; i--) {
            cct_showch(44 - i, 14 - n + i, ' ', i, i, 2 * i + 1);
            Sleep(200);
        }
    }
    if (src == 'C') {
        for (int i = n; i > 0; i--) {
            cct_showch(76 - i, 14 - n + i, ' ', i, i, 2 * i + 1);
            Sleep(150);
        }
    }
    cct_setcolor(0);
}
/***************************************************************************
  函数名称：
  功    能：盘子移动函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void moveplate(char src, char dst, int a1, int b1, int c1) {
    int color[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12 };
    int x, y;
    if (src == 'A') {
        for (y = 16 - a1; y > 0; y--) {
            cct_showch(12 - a[a1 - 1], y, ' ', color[a[a1 - 1]], color[a[a1 - 1]], 2 * a[a1 - 1] + 1);
            if (y != 16 - a1)
                cct_showch(12 - a[a1 - 1], y + 1, ' ', 0, 0, 2 * a[a1 - 1] + 1);
            if (y != 16 - a1 && y != 1)
                cct_showch(12, y + 1, ' ', 14, 14);
            Sleep(100);
        }
        if (dst == 'B') {
            for (x = 13 - a[a1 - 1]; x < 45 - a[a1 - 1]; x++) {
                cct_showch(x, 1, ' ', color[a[a1 - 1]], color[a[a1 - 1]], 2 * a[a1 - 1] + 1);
                cct_showch(x - 1, 1, ' ', 0, 0);
                Sleep(80);
            }
            for (y = 1; y < 16 - b1; y++) {
                cct_showch(44 - a[a1 - 1], y, ' ', color[a[a1 - 1]], color[a[a1 - 1]], 2 * a[a1 - 1] + 1);
                cct_showch(44 - a[a1 - 1], y - 1, ' ', 0, 0, 2 * a[a1 - 1] + 1);
                if (y != 1 && y != 2 && y != 3)
                    cct_showch(44, y - 1, ' ', 14, 14);
                Sleep(100);
            }
        }
        if (dst == 'C') {
            for (x = 13 - a[a1 - 1]; x < 77 - a[a1 - 1]; x++) {
                cct_showch(x, 1, ' ', color[a[a1 - 1]], color[a[a1 - 1]], 2 * a[a1 - 1] + 1);
                cct_showch(x - 1, 1, ' ', 0, 0);
                Sleep(80);
            }
            for (y = 1; y < 16 - c1; y++) {
                cct_showch(76 - a[a1 - 1], y, ' ', color[a[a1 - 1]], color[a[a1 - 1]], 2 * a[a1 - 1] + 1);
                cct_showch(76 - a[a1 - 1], y - 1, ' ', 0, 0, 2 * a[a1 - 1] + 1);
                if (y != 1 && y != 2 && y != 3)
                    cct_showch(76, y - 1, ' ', 14, 14);
                Sleep(100);
            }
        }
    }
    if (src == 'B') {
        for (y = 16 - b1; y > 0; y--) {
            cct_showch(44 - b[b1 - 1], y, ' ', color[b[b1 - 1]], color[b[b1 - 1]], 2 * b[b1 - 1] + 1);
            if (y != 16 - b1)
                cct_showch(44 - b[b1 - 1], y + 1, ' ', 0, 0, 2 * b[b1 - 1] + 1);
            if (y != 16 - b1 && y != 1)
                cct_showch(44, y + 1, ' ', 14, 14);
            Sleep(100);
        }
        if (dst == 'C') {
            for (x = 45 - b[b1 - 1]; x < 77 - b[b1 - 1]; x++) {
                cct_showch(x, 1, ' ', color[b[b1 - 1]], color[b[b1 - 1]], 2 * b[b1 - 1] + 1);
                cct_showch(x - 1, 1, ' ', 0, 0);
                Sleep(80);
            }
            for (y = 1; y < 16 - c1; y++) {
                cct_showch(76 - b[b1 - 1], y, ' ', color[b[b1 - 1]], color[b[b1 - 1]], 2 * b[b1 - 1] + 1);
                cct_showch(76 - b[b1 - 1], y - 1, ' ', 0, 0, 2 * b[b1 - 1] + 1);
                if (y != 1 && y != 2 && y != 3)
                    cct_showch(76, y - 1, ' ', 14, 14);
                Sleep(100);
            }
        }
        if (dst == 'A') {
            for (x = 44 - b[b1 - 1]; x > 11 - b[b1 - 1]; x--) {
                cct_showch(x + 1, 1, ' ', 0, 0, 2 * b[b1 - 1] + 1);
                cct_showch(x, 1, ' ', color[b[b1 - 1]], color[b[b1 - 1]], 2 * b[b1 - 1] + 1);
                Sleep(100);
            }
            for (y = 1; y < 16 - a1; y++) {
                cct_showch(12 - b[b1 - 1], y, ' ', color[b[b1 - 1]], color[b[b1 - 1]], 2 * b[b1 - 1] + 1);
                if (y != 1)
                    cct_showch(12 - b[b1 - 1], y - 1, ' ', 0, 0, 2 * b[b1 - 1] + 1);
                if (y != 1 && y != 2 && y != 3)
                    cct_showch(12, y - 1, ' ', 14, 14);
                Sleep(100);
            }
        }
    }
    if (src == 'C') {
        for (y = 16 - c1; y > 0; y--) {
            cct_showch(76 - c[c1 - 1], y, ' ', color[c[c1 - 1]], color[c[c1 - 1]], 2 * c[c1 - 1] + 1);
            if (y != 16 - c1)
                cct_showch(76 - c[c1 - 1], y + 1, ' ', 0, 0, 2 * c[c1 - 1] + 1);
            if (y != 16 - c1 && y != 1)
                cct_showch(76, y + 1, ' ', 14, 14);
            Sleep(100);
        }
        if (dst == 'A') {
            for (x = 76 - c[c1 - 1]; x > 11 - c[c1 - 1]; x--) {
                cct_showch(x + 1, 1, ' ', 0, 0, 2 * c[c1 - 1] + 1);
                cct_showch(x, 1, ' ', color[c[c1 - 1]], color[c[c1 - 1]], 2 * c[c1 - 1] + 1);
                Sleep(100);
            }
            for (y = 1; y < 16 - a1; y++) {
                cct_showch(12 - c[c1 - 1], y, ' ', color[c[c1 - 1]], color[c[c1 - 1]], 2 * c[c1 - 1] + 1);
                if (y != 1)
                    cct_showch(12 - c[c1 - 1], y - 1, ' ', 0, 0, 2 * c[c1 - 1] + 1);
                if (y != 1 && y != 2 && y != 3)
                    cct_showch(12, y - 1, ' ', 14, 14);
                Sleep(100);
            }
        }
        if (dst == 'B') {
            for (x = 76 - c[c1 - 1]; x > 43 - c[c1 - 1]; x--) {
                cct_showch(x + 1, 1, ' ', 0, 0, 2 * c[c1 - 1] + 1);
                cct_showch(x, 1, ' ', color[c[c1 - 1]], color[c[c1 - 1]], 2 * c[c1 - 1] + 1);
                Sleep(100);
            }
            for (y = 1; y < 16 - b1; y++) {
                cct_showch(44 - c[c1 - 1], y, ' ', color[c[c1 - 1]], color[c[c1 - 1]], 2 * c[c1 - 1] + 1);
                if (y != 1)
                    cct_showch(44 - c[c1 - 1], y - 1, ' ', 0, 0, 2 * c[c1 - 1] + 1);
                if (y != 1 && y != 2 && y != 3)
                    cct_showch(44, y - 1, ' ', 14, 14);
                Sleep(100);
            }
        }
    }
    cct_setcolor(0);
}
/***************************************************************************
  函数名称：
  功    能：为游戏模式单独写的数据输入
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int _inputspecial(char *p1,char *p2) {
    cct_gotoxy(0, 34);
    cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出)：";
    char src, dst;
    while (1) {
        src = getchar();
        if (src == 'q' || src == 'Q') {
            return 1;
        }
        dst = getchar();
        int zz=getchar();
        src = changeatoA(src);
        dst = changeatoA(dst);
        if (src > 64 && src < 68 && dst>64 && dst < 68 && dst != src)
        {
            if ((src == 'A' && ta == 1)|| (src == 'B' && tb == 1)|| (src == 'C' && tc == 1)) {
                cct_gotoxy(59, 34);
                cout << "       ";
                cct_gotoxy(0, 35);
                cout << "源柱为空";
                Sleep(400);
                cct_gotoxy(0, 35);
                cout << "              ";
                cct_gotoxy(59, 34);
                continue;
            }
            if (src == 'A' && dst == 'B' && a[ta - 1] > b[tb - 1]&&tb!=1) {
                cct_gotoxy(59, 34);
                cout << "       ";
                cct_gotoxy(0, 35);
                cout << "大盘不能压小盘";
                Sleep(400);
                cct_gotoxy(0, 35);
                cout << "                 ";
                cct_gotoxy(59, 34);
                continue;
            }
            if (src == 'A' && dst == 'C' && a[ta - 1] > c[tc - 1] && tc != 1) {
                cct_gotoxy(59, 34);
                cout << "       ";
                cct_gotoxy(0, 35);
                cout << "大盘不能压小盘";
                Sleep(400);
                cct_gotoxy(0, 35);
                cout << "                   ";
                cct_gotoxy(59, 34);
                continue;
            }
            if (src == 'B' && dst == 'A' && b[tb - 1] > a[ta - 1] && ta != 1) {
                cct_gotoxy(59, 34);
                cout << "       ";
                cct_gotoxy(0, 35);
                cout << "大盘不能压小盘";
                Sleep(400);
                cct_gotoxy(0, 35);
                cout << "                  ";
                cct_gotoxy(59, 34);
                continue;
            }
            if (src == 'B' && dst == 'C' && b[tb - 1] > c[tc - 1] && tc != 1) {
                cct_gotoxy(59, 34);
                cout << "       ";
                cct_gotoxy(0, 35);
                cout << "大盘不能压小盘";
                Sleep(400);
                cct_gotoxy(0, 35);
                cout << "                   ";
                cct_gotoxy(59, 34);
                continue;
            }
            if (src == 'C' && dst == 'A' && c[tc - 1] > a[ta - 1] && ta != 1) {
                cct_gotoxy(59, 34);
                cout << "       ";
                cct_gotoxy(0, 35);
                cout << "大盘不能压小盘";
                Sleep(400);
                cct_gotoxy(0, 35);
                cout << "                  ";
                cct_gotoxy(59, 34);
                continue;
            }
            if (src == 'C' && dst == 'b' && c[tc - 1] > b[tb - 1] && tb != 1) {
                cct_gotoxy(59, 34);
                cout << "       ";
                cct_gotoxy(0, 35);
                cout << "大盘不能压小盘";
                Sleep(400);
                cct_gotoxy(0, 35);
                cout << "                   ";
                cct_gotoxy(59, 34);
                continue;
            }
            *p1 = src;
            *p2 = dst;
            break;
        }   
        else {
            cct_gotoxy(59, 34);
            cout << "       ";
            cct_gotoxy(59, 34);
        }
    }
    cct_gotoxy(59, 34);
    cout << "       ";

    return 0;
}