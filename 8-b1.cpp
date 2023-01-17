//2151753 彭坤宇 计科
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
    cerr << "文件名以下形式均可以:" << endl;
    cerr << "    a.txt                     : 不带路径形式" << endl;
    cerr << "    .." << char(92) << "data" << char(92) << "b.dat             : 相对路径形式" << endl;
    cerr << "    C:" << char(92) << "Windows" << char(92) << "System32" << char(92) << "c.dat : 绝对相对路径形式" << endl;
    cerr << "请输入文件名 :";
    char name_of_file[100];
    cin.getline(name_of_file,'\n');
    ifstream file(name_of_file, ios::in | ios::binary);
    if (file.is_open() == 0) {
        cout << "输入文件" << name_of_file << "打开失败" << endl;
        return 0;
    }
    char ch[16];
    int i = 0;
    while (file.peek() != EOF) {
        if (i == 0)
            cout << setw(8) << setfill('0') << hex << file.tellg() << ":  ";
        file.get(ch[i++]);
        if (i == 8) {
            for (int t = 0; t <= 7; t++) {
                if (int(unsigned char(ch[t])) < 16)
                    cout << "0";
                cout << setiosflags(ios::uppercase) << hex <<  int(unsigned char(ch[t])) << " ";
            }
            if (file.peek() != EOF)
                cout << "- ";
        }
        if (i == 16) {
            for (int t = 8; t <= 15; t++) {
                if (int(unsigned char(ch[t])) < 16)
                    cout << "0";
                cout << setiosflags(ios::uppercase) << hex << int(unsigned char(ch[t])) << " ";
            }
            cout << " ";
            for (int t = 0; t <= 15; t++) {
                if (int(unsigned char(ch[t])) >= 33 && int(unsigned char(ch[t])) <= 126)
                    cout << ch[t];
                else
                    cout << ".";
            }
            i = 0;
            cout << endl;
        }
    }
    if (i < 8 && i >= 1) {
        for (int t = 0; t < i; t++) {
            if (int(unsigned char(ch[t])) < 16)
                cout << "0";
            cout << setiosflags(ios::uppercase) << hex << int(unsigned char(ch[t])) << " ";
        }
     
        cout << setw(51 - 3 * i) << setfill(' ') << " ";
    }
    else if (8 <= i && i < 16) {
        for (int t = 8; t < i; t++) {
            if (int(unsigned char(ch[t])) < 16)
                cout << "0";
            cout << setiosflags(ios::uppercase) << hex << int(unsigned char(ch[t])) << " ";
        }
        if (file.peek() == EOF)
            cout << "  ";
        cout << setw(49 - 3 * i) << setfill(' ') << " ";
    }
    if (i != 0) {
        for (int t = 0; t < i; t++) {
            if (int(unsigned char(ch[t])) >= 33 && int(unsigned char(ch[t])) <= 126)
                cout << ch[t];
            else
                cout << ".";
        }
        cout << endl;
    }
    file.close();
    return 0;
}