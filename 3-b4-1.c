//2151753 彭坤宇 计科
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

int main()
{
	printf("三形的两边及其夹角(角度）\n");
	int a, b, c;
	double pi = 3.14159;
	float s;
	scanf(" %d %d %d", &a, &b, &c);
	s = (float)(0.5 * a * b * sin(c * pi / 180));
	printf("三角形的面积为 ；%.3f", s);
	return 0;
}