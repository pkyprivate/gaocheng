//2151753 ������ �ƿ�
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
//�ж���û�д����ַ�
int select_txt(char s[],char map[20][20],int &line) {
    char s0[30] = "stage//";
    strcat(s0, s);
    ifstream file(s0, ios::in);
    if (file.is_open() == 0) {
        cout << "û���ҵ����ļ�" << endl;
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
            cout << "��" << line - 1 << "�е�" << check << "���ַ����ִ���,����Ϊ:" << map[line- 1][check] << endl;
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
//��ָ�����ļ���ȡ������Ҫ���ַ�
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
    cct_showstr(x, y, "�X�T�[",4,0);
    cct_showstr(x, y + 1, "�UXX�U",4,0);
    cct_showstr(x, y + 2, "�^�T�a",4,0);
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
    cct_showstr(x, y, "�X�T�[", 2, 6);
    cct_showstr(x, y + 1, "�U��U", 2, 6);
    cct_showstr(x, y + 2, "�^�T�a", 2, 6);
    cct_gotoxy(x + 6, y);
}
void print_F() {
    int x, y;
    cct_getxy(x, y);
    cct_showstr(x, y, "�X�T�[", 3, 2);
    cct_showstr(x, y + 1, "�U��U", 3, 2);
    cct_showstr(x, y + 2, "�^�T�a", 3, 2);
    cct_gotoxy(x + 6, y);
}
void print_S() {
    int x, y;
    cct_getxy(x, y);
    cct_showstr(x, y, "�X�T�[", 1, 6);
    cct_showstr(x, y + 1, "�U��U", 1, 6);
    cct_showstr(x, y + 2, "�^�T�a", 1, 6);
    cct_gotoxy(x + 6, y);
}
void print_R() {
    int x, y;
    cct_getxy(x, y);
    cct_showstr(x, y, "�X�T�[", 6, 4);
    cct_showstr(x, y + 1, "�U��U", 6, 4);
    cct_showstr(x, y + 2, "�^�T�a", 6, 4);
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
//��ӡͼ�λ�����



