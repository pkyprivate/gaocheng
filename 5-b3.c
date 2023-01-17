//2151753 彭坤宇 计科
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int judge(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}

void output(int flag, int year, int month, int day) {
	int m0[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int m1[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int z = 0;
	if (flag) {
		for (int i = 1; i < month; i++) {
			z += m1[i];
		}
		z += day;
	}
	if (!flag) {
		for (int i = 1; i < month; i++) {
			z += m0[i];
		}
		z += day;
	}
	printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, z);
}
int main()
{
	int m0[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int m1[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	printf("请输入年，月，日\n");
	int year, month, day;
	int z = 0;
	int flag;
	scanf("%d%d%d", &year, &month, &day);
	flag = judge(year);
	if (flag) {
		if (month < 1 || month>12) {
			printf("输入错误-月份不正确\n");
			return 0;
		}
		if (m1[month] < day) {
			printf("输入错误-日与月的非法关系\n");
			return 0;
		}
	}
	if (!flag) {
		if (month < 1 || month>12) {
			printf("输入错误-月份不正确\n");
			return 0;
		}
		if (m0[month] < day) {
			printf("输入错误-日与月的非法关系\n");
			return 0;
		}
	}
	output(flag, year, month, day);
	return 0;
}