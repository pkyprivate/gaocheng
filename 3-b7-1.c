//2151753 ������ �ƿ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() 
{
	printf("����������ֵ��\n");
	double money;
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, sum;
	scanf("%lf", &money);
	money = money + 0.001;
	while (money >= 50) {
		money = money - 50;
		a++;
	}

	while (money >= 20) {
		money = money - 20;
		b++;
	}

	while (money >= 10) {
		money = money - 10;
		c++;
	}

	while (money >= 5) {
		money = money - 5;
		d++;
	}

	while (money >= 1) {
		money = money - 1;
		e++;
	}

	while (money >= 0.5) {
		money = money - 0.5;
		f++;
	}

	while (money >= 0.1) {
		money = money - 0.1;
		g++;
	}

	while (money >= 0.05) {
		money = money - 0.05;
		h++;
	}

	while (money >= 0.02) {
		money = money - 0.02;
		i++;
	}

	while (money >= 0.01) {
		money = money - 0.01;
		j++;
	}

	sum = a + b + c + d + e + f + g + h + i + j;
	printf("��%d�����㣬�������£�\n", sum); 


	if (a != 0)
		printf("50Ԫ : %d��\n", a); 

	if (b != 0)
		printf("20Ԫ : %d��\n", b);

	if (c != 0)
		printf("10Ԫ : %d��\n", c);
	if (d != 0)
		printf("5Ԫ  : %d��\n", d);

	if (e != 0)
		printf("1Ԫ  : %d��\n", e);
	if (f != 0)
		printf("5��  : %d��\n", f);
	if (g != 0)
		printf("1��  : %d��\n", g);
	if (h != 0)
		printf("5��  : %d��\n", h);
	if (i != 0)
		printf("2��  : %d��\n", i);
	if (j != 0)
		printf("1��  : %d��\n", j);
	return 0;
}
