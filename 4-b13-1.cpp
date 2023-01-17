//2151753 ������ �ƿ�
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
               3��������һ����̬�ֲ�����
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int number = 1;
    if (n == 1) {
        cout <<setw(5) << number << ":";
        cout <<setw(3) << n << "# " << src << "-->" << dst << endl;
    }
    if (n > 1) {
        hanoi(n - 1, src, dst, tmp);
        number++;
        cout << setw(5) << number << ":";
        cout <<setw(3) << n << "# " << src << "-->" << dst << endl;
        number++;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;
    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        if (cin.good() == 1 && n > 0 && n < 17) {
            break;
        }
    }
    while (1) {
        int x;
        cout << "��������ʼ��(A-C)" << endl;
        x = getchar();
        src = getchar();
        if (src == 'a' || src == 'b' || src == 'c' || src == 'A' || src == 'B' || src == 'C')
            break;
    }
    if (src == 'A' || src == 'a') {
        src = 'A';
    }
    if (src == 'B' || src == 'b') {
        src = 'B';
    }
    if (src == 'C' || src == 'c') {
        src = 'C';
    }
    while (1) {
        int x;
        cout << "������Ŀ����(A-C)" << endl;
        x = getchar();
        dst = getchar();
        int t;
        t = (dst == 'a' || dst == 'b' || dst == 'c' || dst == 'A' || dst == 'B' || dst == 'C');
        if (dst == src || dst == src + 32) {
            cout << "Ŀ����(A)��������ʼ��(A)��ͬ" << endl;
        }
        if (t == 1 && dst != src && dst != src + 32)
            break;
    }

    if (dst == 'A' || dst == 'a') {
        dst = 'A';
    }
    if (dst == 'B' || dst == 'b') {
        dst = 'B';
    }
    if (dst == 'C' || dst == 'c') {
        dst = 'C';
    }
    if (src == 'A' && dst == 'B')tmp = 'C';
    if (src == 'A' && dst == 'C')tmp = 'B';
    if (src == 'B' && dst == 'A')tmp = 'C';
    if (src == 'B' && dst == 'C')tmp = 'A';
    if (src == 'C' && dst == 'A')tmp = 'B';
    if (src == 'C' && dst == 'B')tmp = 'A';
    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(n, src, tmp, dst);
}