//2151753 彭坤宇 计科
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "5-b7.h"
using namespace std;
int a[11] = { 0,0,0,0,0,0,0,0,0,0,0 }, b[11] = { 0,0,0,0,0,0,0,0,0,0,0 }, c[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int sum = 0, ta = 1, tb = 1, tc = 1;
int speed, show;
char first, last;
int total;
void print_h() {
    cct_gotoxy(0, 0);
    cout << "从 " << first << " 移动到 " << last << "," << "共" << " " << total << " 层" << "," << "延时设置为 " << speed << ", ";
    if (show == 0)
        cout << "不";
    cout << "显示内部数值组" << endl;
    cct_gotoxy(0, 18);
}

void print_main() {
    cct_gotoxy(20, 13);
    int i;
    for (i = 1; i < 26; i++)
        cout << "=";
    cct_gotoxy(22, 14);
    cout << "A";
    cct_gotoxy(32, 14);
    cout << "B";
    cct_gotoxy(42, 14);
    cout << "C";
    int m = 1, n = 1, k = 1;
    for (i = 1; i < 11; i++) {
        if (a[i] != 0) {
            cct_gotoxy(22, 13 - m);
            cout << a[i];
            m++;
        }
    }
    for (i = 1; i < 11; i++) {
        if (b[i] != 0) {
            cct_gotoxy(32, 13 - n);
            cout << b[i];
            n++;
        }
    }
    for (i = 1; i < 11; i++) {
        if (c[i] != 0) {
            cct_gotoxy(42, 13 - k);
            cout << c[i];
            k++;
        }

    }
}

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
        Sleep((6 - speed) * 100);
    }


}

void aprint()
{
    cout << "A:";
    for (int i = 1; i < ta; i++)
        cout << setw(2) << a[i];
    for (int i = 11; i > ta; i--)
        cout << "  ";
    cout << ' ';
}

void bprint()
{
    cout << "B:";
    for (int i = 1; i < tb; i++)
        cout << setw(2) << b[i];
    for (int i = 11; i > tb; i--)
        cout << "  ";
    cout << ' ';
}

void cprint()
{
    cout << "C:";
    for (int i = 1; i < tc; i++)
        cout << setw(2) << c[i];
    for (int i = 11; i > tc; i--)
        cout << "  ";
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n > 1)
        hanoi(n - 1, src, dst, tmp);
    sum++;
    print_h();
    cout << "第" << setw(4) << sum << " 步";
    cout << "(" << n << "#:" << " " << src << "-->" << dst << " )" << "  ";
    if (src == 'A' && dst == 'B') {
        b[tb++] = a[--ta];
        a[ta] = 0;
    }
    if (src == 'A' && dst == 'C') {
        c[tc++] = a[--ta];
        a[ta] = 0;
    }
    if (src == 'B' && dst == 'A') {
        a[ta++] = b[--tb];
        b[tb] = 0;
    }
    if (src == 'B' && dst == 'C') {
        c[tc++] = b[--tb];
        b[tb] = 0;
    }
    if (src == 'C' && dst == 'B') {
        b[tb++] = c[--tc];
        c[tc] = 0;
    }
    if (src == 'C' && dst == 'A') {
        a[ta++] = c[--tc];
        c[tc] = 0;
    }
    if (show) {
        aprint();
        bprint();
        cprint();
        speed1();
        cct_cls();
    }
    print_main();
    if (show) {
        print_h();
        cout << "第" << setw(4) << sum << " 步";
        cout << "(" << n << "#:" << " " << src << "-->" << dst << " )" << "  ";
        aprint();
        bprint();
        cprint();
    }
    speed1();
    if (n > 1)cct_cls();
    if (show) {
        print_main();
        print_h();
    }
    if (n > 1)
        hanoi(n - 1, tmp, src, dst);
}

char a_to_A(char a)
{
    if (a >= 'a' && a <= 'z')
        return char(a - 32);
    else
        return a;
}

int main()
{
    int n;
    char src, tmp, dst;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)：\n";
        cin >> n;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        if (n >= 1 && n <= 10)
        {
            cin.ignore(65536, '\n');
            break;
        }
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)：\n";
        cin >> src;
        src = a_to_A(src);
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
        cin.ignore(65536, '\n');
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)：\n";
        cin >> dst;
        dst = a_to_A(dst);
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
        cin.ignore(65536, '\n');
    }
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
    while (1) {
        cout << "请输入是否显示内部数值组(0-不显示 1-显示)" << endl;
        cin >> show;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        if (show == 1 || show == 0)
            break;
    }
    { if (src == 'A' && dst == 'B' || src == 'B' && dst == 'A')
        tmp = 'C';
    else if (src == 'C' && dst == 'B' || src == 'B' && dst == 'C')
        tmp = 'A';
    else if (src == 'A' && dst == 'C' || src == 'C' && dst == 'A')
        tmp = 'B';
    if (src == 'A')
        for (int i = n; i >= 1; i--) {
            a[ta] = i;
            ta++;
        }
    if (src == 'B')
        for (int i = n; i >= 1; i--) {
            b[tb] = i;
            tb++;
        }
    if (src == 'C')
        for (int i = n; i >= 1; i--) {
            c[tc] = i;
            tc++;
        }
    }
    first = src;
    last = dst;
    total = n;
    cct_cls();
    print_h();
    if (show) {
        cout << setw(23) << setiosflags(ios::left) << "初始:" << resetiosflags(ios::left);
        aprint();
        bprint();
        cprint();
        speed1();
        print_main();
        speed1();
        cct_cls();
        print_main();
        print_h();
        hanoi(n, src, tmp, dst);
    }
    else {
        print_main();
        speed1();
        cct_cls();
        hanoi(n, src, tmp, dst);
    }
    cct_gotoxy(0, 22);
    system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
    return 0;
}