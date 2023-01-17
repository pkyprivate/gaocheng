//2151753 彭坤宇 计科
//2151338 李秉嵘  2151974 赵明泽 2152871 王颢瑾 2151601 邹昕恺  2152988 杨恺铭 2051961 王煜程
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
    cerr << "文件名以下形式均可以:" << endl;
    cerr << "    a.hex                     : 不带路径形式" << endl;
    cerr << "    .." << char(92) << "data" << char(92) << "b.txt             : 相对路径形式" << endl;
    cerr << "    C:" << char(92) << "Windows" << char(92) << "System32" << char(92) << "c.hex : 绝对相对路径形式" << endl;
    cerr << "请输入要转换的hex格式文件名 :";
    char name_of_file1[100];
    char name_of_file2[100];
    cin >> name_of_file1;
    cerr << "请输入转换后的文件名        :";
    cin >> name_of_file2;
    ifstream file(name_of_file1, ios::in | ios::binary);
    ofstream out(name_of_file2, ios::out | ios::binary);
    if (file.is_open() == 0) {
        cout << "输入文件" << name_of_file1 << "打开失败!" << endl;
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