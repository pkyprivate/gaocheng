//2151753 ������ �ƿ�
//2151338 �����  2151974 ������ 2152871 ���� 2151601 �����  2152988 ������ 2051961 ���ϳ�
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int chartoint(char a) {
    if (a >= 'A' && a <= 'F')
        return a - 'A' + 10;
    if (a >= '0' && a <= '9')
        return a - '0';
    else
        return 0;
}
int main()
{
    cerr << "�ļ���������ʽ������:" << endl;
    cerr << "    a.hex                     : ����·����ʽ" << endl;
    cerr << "    .." << char(92) << "data" << char(92) << "b.txt             : ���·����ʽ" << endl;
    cerr << "    C:" << char(92) << "Windows" << char(92) << "System32" << char(92) << "c.hex : �������·����ʽ" << endl;
    cerr << "������Ҫת����hex��ʽ�ļ��� :";
    char name_of_file1[100];
    char name_of_file2[100];
    cin >> name_of_file1;
    cerr << "������ת������ļ���        :";
    cin >> name_of_file2;
    ifstream file(name_of_file1, ios::in | ios::binary);
    ofstream out(name_of_file2, ios::out | ios::binary);
    if (file.is_open() == 0) {
        cout << "�����ļ�" << name_of_file1 << "��ʧ��!" << endl;
        return 0;
    }
    while (file.peek() != EOF) {
        char t[100];
        file.getline(t, 100);
        for (int i = 11; t[i] != '\0' && i <= 59; i++) {
            if (t[i] == ' ' || t[i] == '-')
                continue;
            else {
                int x1 = chartoint(t[i]);
                int x2 = chartoint(t[++i]);
                out << char(x1 * 16 + x2);
            }
        }
    }
    file.close();
    out.close();
    return 0;
}