//2151753 彭坤宇 计科
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	double pi = 3.14159;
	double a, b, c, d, e, f, g;
	cout << "请输入半径和高度" << endl;
	cin >> a >> b;
	c = 2 * pi * a;
	d = pi * a * a;
	e = 4 * pi * a * a;
	f = 4.0 / 3 * pi * a * a * a;
	g = pi * a * a * b;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "圆周长     ：" << c << endl;
	cout << "圆面积     ：" << d << endl;
	cout << "圆球表面积 ：" << e << endl;
	cout << "圆球体积   ：" << f << endl;
	cout << "圆柱体积   ：" << g << endl;
	return 0;
}