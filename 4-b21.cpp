//2151753 彭坤宇 计科
#include <iostream>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、整个程序不允许出现任何形式的循环
   ---------------------------------------------------------------------
*/

/***************************************************************************
  函数名称：
  功    能：递归方式完成十进制到其它进制的转换并打印
  输入参数：int num ：十进制数
			int base：要转换的进制
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
			2、不允许出现任何形式的循环
			3、不允许使用cmath中的函数
			4、不允许使用64位整数
***************************************************************************/
void dec_to_base_n(int num, int base)
{
	if (num < 0) {
		unsigned int num0;
		num0 = num;
		dec_to_base_n(num0 / base, base);
		if (num0 % base < 10)
			cout << num0 % base;
		else if (num0 % base == 10)
			cout << "A";
		else if (num0 % base == 11)
			cout << "B";
		else if (num0 % base == 12)
			cout << "C";
		else if (num0 % base == 13)
			cout << "D";
		else if (num0 % base == 14)
			cout << "E";
		else if (num0 % base == 15)
			cout << "F";
	}
	else {
		if (num > base || num == base) {
			dec_to_base_n(num / base, base);
			if (num % base < 10)
				cout << num % base;
			else if (num % base == 10)
				cout << "A";
			else if (num % base == 11)
				cout << "B";
			else if (num % base == 12)
				cout << "C";
			else if (num % base == 13)
				cout << "D";
			else if (num % base == 14)
				cout << "E";
			else if (num % base == 15)
				cout << "F";
		}
		else {
			if (num % base < 10)
				cout << num % base;
			else if (num % base == 10)
				cout << "A";
			else if (num % base == 11)
				cout << "B";
			else if (num % base == 12)
				cout << "C";
			else if (num % base == 13)
				cout << "D";
			else if (num % base == 14)
				cout << "E";
			else if (num % base == 15)
				cout << "F";
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	int num, base;

	cout << "请输入十进制整数(int型)及要转换的进制[2..16]" << endl;
	cin >> num >> base;		//不考虑输入错误，num为int型范围任何值均可，base为2~16，不考虑10进制

	if (base == 10) //进制为10直接退出
		return -1;

	/* 完成进制转换并打印 */
	dec_to_base_n(num, base);
	cout << endl;

	return 0;
}