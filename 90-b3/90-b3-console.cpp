//2151753 彭坤宇 计科
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<io.h>
#include<windows.h>
#include<conio.h>
#include"cmd_console_tools.h"
#include"90-b3.h"
using namespace std;
int check_wrong(char s[]) {
    for (int i = 0; s[i] != '\0'&&i!=16;i++) {
        if (s[i] == '9' || s[i] == 'W' || s[i] == '0' || s[i] == 'B' || s[i] == 'S' || s[i] == 'F' || s[i] == 'R')
            continue;
        else
            return i;
    }
    return -1;
}
//判断有没有错误字符
int select_txt(char s[],char map[20][20],int &line) {
    char s0[30] = "stage//";
    strcat(s0, s);
    ifstream file(s0, ios::in);
    if (file.is_open() == 0) {
        cout << "没有找到此文件" << endl;
        return -1;
    }
    int check=0;
    while (file.peek() != EOF) {
        char s[100];
        file.getline(s,sizeof(s));
        strncpy(map[line++], s, 16);
        map[line - 1][16] = '\0';
        check=check_wrong(map[line-1]);
        if (check != -1){
            cct_gotoxy(0, 45);
            cct_setcolor(0);
            cout << "第" << line - 1 << "行第" << check << "个字符出现错误,错误为:" << map[line- 1][check] << endl;
            break;
        }
        if (line == 14)
            break;
    }
    file.close();
    if (check == -1)
        return -1;
    return 0;
}
//从指定的文件中取出所需要的字符
void print_9() {
    int x, y;
    cct_getxy(x, y);
    cct_showstr(x, y, "      ");
    cct_showstr(x, y+1, "      ");
    cct_showstr(x, y+2, "      ");
    cct_gotoxy(x+6, y);
}
void print_W() {
    int x, y;
    cct_getxy(x, y);
    cct_showstr(x, y, "╔═╗",4,0);
    cct_showstr(x, y + 1, "║XX║",4,0);
    cct_showstr(x, y + 2, "╚═╝",4,0);
    cct_gotoxy(x + 6, y);
}
void print_0() {
    int x, y;
    cct_getxy(x, y);
    cct_showstr(x, y, "      ",8);
    cct_showstr(x, y + 1, "      ", 8);
    cct_showstr(x, y + 2, "      ", 8);
    cct_gotoxy(x + 6, y);
}
void print_B() {
    int x, y;
    cct_getxy(x, y);
    cct_showstr(x, y, "╔═╗", 2, 6);
    cct_showstr(x, y + 1, "║★║", 2, 6);
    cct_showstr(x, y + 2, "╚═╝", 2, 6);
    cct_gotoxy(x + 6, y);
}
void print_F() {
    int x, y;
    cct_getxy(x, y);
    cct_showstr(x, y, "╔═╗", 3, 2);
    cct_showstr(x, y + 1, "║●║", 3, 2);
    cct_showstr(x, y + 2, "╚═╝", 3, 2);
    cct_gotoxy(x + 6, y);
}
void print_S() {
    int x, y;
    cct_getxy(x, y);
    cct_showstr(x, y, "╔═╗", 1, 6);
    cct_showstr(x, y + 1, "║¤║", 1, 6);
    cct_showstr(x, y + 2, "╚═╝", 1, 6);
    cct_gotoxy(x + 6, y);
}
void print_R() {
    int x, y;
    cct_getxy(x, y);
    cct_showstr(x, y, "╔═╗", 6, 4);
    cct_showstr(x, y + 1, "║★║", 6, 4);
    cct_showstr(x, y + 2, "╚═╝", 6, 4);
    cct_gotoxy(x + 6, y);

}
void print_stage(char map[20][20],int line) {
    cct_gotoxy(0, 0);
    for (int i = 0; i < line; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == '9')
                print_9();
            if(map[i][j]=='W')
                print_W();
            if (map[i][j] == '0')
                print_0();
            if (map[i][j] == 'B')
                print_B();
            if (map[i][j] == 'F')
                print_F();
            if (map[i][j] == 'S')
                print_S();
            if (map[i][j] == 'R')
                print_R();
        }
        cout << endl << endl << endl;
    }
}
//打印图形化界面



