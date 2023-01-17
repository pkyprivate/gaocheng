//2151753 彭坤宇 计科
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环
      如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        cout << " " << n << "# " << src << "-->" << dst << endl;
    }
    if (n > 1) {
        hanoi(n - 1, src, dst, tmp);
        if (n < 10) {
            cout << " ";
        }
        cout << n << "# " << src << "-->" << dst << endl;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;
    while (1) {
        cout << "请输入汉诺塔的层数(1-16)" << endl;
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
        cout << "请输入起始柱(A-C)" << endl;
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
        cout << "请输入目标柱(A-C)" << endl;
        x = getchar();
        dst = getchar();
        int t;
        if (dst == src || dst == src + 32) {
            cout << "目标柱(A)不能与起始柱(A)相同" << endl;
        }
        t = (dst == 'a' || dst == 'b' || dst == 'c' || dst == 'A' || dst == 'B' || dst == 'C');
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
    cout << "移动步骤为:" << endl;
    hanoi(n, src, tmp, dst);
}