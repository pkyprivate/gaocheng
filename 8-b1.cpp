//2151753 ������ �ƿ�
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
    cerr << "�ļ���������ʽ������:" << endl;
    cerr << "    a.txt                     : ����·����ʽ" << endl;
    cerr << "    .." << char(92) << "data" << char(92) << "b.dat             : ���·����ʽ" << endl;
    cerr << "    C:" << char(92) << "Windows" << char(92) << "System32" << char(92) << "c.dat : �������·����ʽ" << endl;
    cerr << "�������ļ��� :";
    char name_of_file[100];
    cin.getline(name_of_file,'\n');
    ifstream file(name_of_file, ios::in | ios::binary);
    if (file.is_open() == 0) {
        cout << "�����ļ�" << name_of_file << "��ʧ��" << endl;
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