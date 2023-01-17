//2151753 彭坤宇 计科
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double pi = 3.14159;
	double a, b, c, d, e, f, g;
	printf("请输入半径和高度\n");
	//cout << "请输入半径和高度" << endl;
	scanf("%lf %lf", &a, &b);
	c = 2 * pi * a;
	d = pi * a * a;
	e = 4 * pi * a * a;
	f = 4.0 / 3 * pi * a * a * a;
	g = pi * a * a * b;
	printf("圆周长     ：%.2f\n", c);
	printf("圆面积     ：%.2f\n", d);
	printf("圆球表面积 ：%.2f\n", e);
	printf("圆球体积   ：%.2f\n", f);
	printf("圆柱体积   ：%.2f\n", g);
	return 0;
}