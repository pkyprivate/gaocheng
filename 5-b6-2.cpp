//2151753 彭坤宇 计科
#include <iostream>
#include <iomanip>
using namespace std;
int plate[4][11] = { {0},{0},{0},{0} };
int sum = 0;
int num[4] = { 1,1,1,1 };
void Aprint()
{
    cout << "A:";
    for (int i = 1; i < num[1]; i++)
        cout << setw(2) << plate[1][i];
    for (int i = 10; i >= num[1]; i--)
        cout << "  ";
    cout << " ";
}

void Bprint()
{
    cout << "B:";
    for (int i = 1; i < num[2]; i++)
        cout << setw(2) << plate[2][i];
    for (int i = 10; i >= num[2]; i--)
        cout << "  ";
    cout << " ";
}

void Cprint()
{
    cout << "C:";
    for (int i = 1; i < num[3]; i++)
        cout << setw(2) << plate[3][i];
    for (int i = 10; i >= num[3]; i--)
        cout << "  ";
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n > 1)
        hanoi(n - 1, src, dst, tmp);
    sum++;
    cout << "第" << setw(4) << sum << " 步";
    cout << '(' << setw(2) << n << "): " << src << "-->" << dst << ' ';
    if (src == 'A' && dst == 'B')
        plate[2][num[2]++] = plate[1][--num[1]];
    if (src == 'A' && dst == 'C')
        plate[3][num[3]++] = plate[1][--num[1]];
    if (src == 'B' && dst == 'A')
        plate[1][num[1]++] = plate[2][--num[2]];
    if (src == 'B' && dst == 'C')
        plate[3][num[3]++] = plate[2][--num[2]];
    if (src == 'C' && dst == 'B')
        plate[2][num[2]++] = plate[3][--num[3]];
    if (src == 'C' && dst == 'A')
        plate[1][num[1]++] = plate[3][--num[3]];
    Aprint();
    Bprint();
    Cprint();
    cout <<endl;
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
        cout << "请输入汉诺塔的层数(1-10)" << endl;
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
        cout << "请输入起始柱(A-C)" << endl;
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
        cout << "请输入目标柱(A-C)"<<endl;
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
            cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
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
    if (src == 'A' && dst == 'B' || src == 'B' && dst == 'A')
        tmp = 'C';
    if (src == 'C' && dst == 'B' || src == 'B' && dst == 'C')
        tmp = 'A';
    if (src == 'A' && dst == 'C' || src == 'C' && dst == 'A')
        tmp = 'B';
    cout << setw(21) << setiosflags(ios::left) << "初始:";
    cout<< resetiosflags(ios::left);
    if (src == 'A')
        for (int i = n; i >= 1; i--) {
            plate[1][num[1]++] = i;
        }
    if (src == 'B')
        for (int i = n; i >= 1; i--) {
           plate[2][num[2]++] = i;
        }
    if (src == 'C')
        for (int i = n; i >= 1; i--) {
            plate[3][num[3]++] = i;
        }
    //初始化三根柱子
    Aprint();
    Bprint();
    Cprint();
    cout << endl;
    hanoi(n, src, tmp, dst);
    return 0;
}