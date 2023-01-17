//2151753 彭坤宇 计科
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入年，月，日\n"); 
	int year, month, day;
	int z = 0;
	int a, b;
	scanf(" %d %d %d", &year, &month, &day);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		switch (month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (day > 31) {
					printf("输入错误-日与月的非法关系\n");
					a = 0;
				}
				else {
					a = 1;
				}
				break;
			case 2:
				if (day > 29) {
					printf("输入错误-日与月的非法关系\n");
					a = 0;
				}
				else {
					a = 1;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30) {
					printf("输入错误-日与月的非法关系\n");
					a = 0;
				}
				else {
					a = 1;
				}
				break;
			default:
				printf("输入错误-日与月的非法关系\n");
				a = 0;
				break;
		}
		if (a == 1)
		{
			switch (month) {
				case 1:
					z = day;
					break;
				case 2:
					z = 31 + day;
					break;
				case 3:
					z = 60 + day;
					break;
				case 4:
					z = 91 + day;
					break;
				case 5:
					z = 121 + day;
					break;
				case 6:
					z = 152 + day;
					break;
				case 7:
					z = 182 + day;
					break;
				case 8:
					z = 213 + day;
					break;
				case 9:
					z = 243 + day;
					break;
				case 10:
					z = 274 + day;
					break;
				case 11:
					z = 305 + day;
					break;
				case 12:
					z = 335 + day;
					break;
			}
			printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, z);
		}
	}
	else {
		switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (day > 31) {
					printf("输入错误-日与月的非法关系\n"); 
					b = 0;
				}
				else {
					b = 1;
				}
				break;
			case 2:
				if (day > 28) {
					printf("输入错误-日与月的非法关系\n");
					b = 0;
				}
				else {
					b = 1;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30) {
					printf("输入错误-日与月的非法关系\n");
					b = 0;
				}
				else {
					b = 1;
				}
				break;
			default:
				printf("输入错误-日与月的非法关系\n");
				b = 0;
				break;
		}
		if (b == 1) {
			switch (month) {
				case 1:
					z = day;
					break;
				case 2:
					z = 31 + day;
					break;
				case 3:
					z = 59 + day;
					break;
				case 4:
					z = 90 + day;
					break;
				case 5:
					z = 120 + day;
					break;
				case 6:
					z = 151 + day;
					break;
				case 7:
					z = 181 + day;
					break;
				case 8:
					z = 212 + day;
					break;
				case 9:
					z = 243 + day;
					break;
				case 10:
					z = 273 + day;
					break;
				case 11:
					z = 304 + day;
					break;
				case 12:
					z = 334 + day;
					break;
			}
			printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, z);
		}
	}
	return 0;

}