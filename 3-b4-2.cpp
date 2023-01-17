//2151753 彭坤宇 计科
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入三角形的两边及其夹角(角度）" << endl;
	int a, b, c;
	double pi = 3.14159;
	float s;
	cin >> a >> b >> c;
	s = float(0.5 * a * b * sin(c * pi / 180));
	cout << "三角形的面积为 ；" << fixed << setprecision(3) << s << endl;
	return 0;
}