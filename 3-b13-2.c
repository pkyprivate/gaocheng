//2151753 ������ �ƿ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c, x = 1;
	int ret;
	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret=scanf("%d%d",&a, &b);
		if (ret && (a >= 2000 && a <= 2030) && (b <= 12 && b >= 1))
			break;
		else {
			rewind(stdin);
			printf("����Ƿ�������������\n");
		}
	}
	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", a, b);
		ret=scanf("%d",&c);
		if (ret&& c <= 6 && c >= 0)
			break;
		else {
			rewind(stdin);
			printf("����Ƿ�������������\n");
		}
	}
	printf("\n");
	printf("%d��%d�µ�����Ϊ:\n",a,b);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
	int m = 8*c;
	if (c != 0) {
		while (m> 0) {
			printf(" ");
			m--;
		}
	}
	int length = 8, all;
	if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
		all = 31;
	else if (b == 2) {
		if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
			all = 29;
		else
			all = 28;
	}
	else
		all = 30;
	for (x = 1; x <= all;) {
		while ((x + c) < length) {
			printf("  ");
			printf("%2d", x);
			x++;
			printf("    ");
			if (x > all)
				break;
		}
		printf("\n");
		length += 7;
	}
	return 0;
}
