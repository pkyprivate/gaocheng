//2151753 彭坤宇 计科
#include <iostream>
using namespace std;
int main()
{
	cout << "请输入一个[1..30000]间的整数:" << endl;
	int a, b, c, d, e, f;
	cin >> a;
	b = a / 10000;
	c = (a - 10000 * b) / 1000;
	d = (a - 10000 * b - 1000 * c) / 100;
	e = (a - 10000 * b - 1000 * c - 100 * d) / 10;
	f = (a - 10000 * b - 1000 * c - 100 * d - 10 * e);
	cout << "万位 ：" << b << endl;
	cout << "千位 ：" << c << endl;
	cout << "百位 ：" << d << endl;
	cout << "十位 ：" << e << endl;
	cout << "个位 ：" << f << endl;
	return 0;
}