//2151753 ������ �ƿ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a, t;
	int b, c, d, e, f, g, h, i, j, k, l, m;
	printf("������[0..100��]֮�������\n");
	scanf("%lf", &a);
	t = a / 10;
	b = (int)(t) / 100000000;
	c = (int)((t)-100000000 * b) / 10000000;
	d = (int)((t)-100000000 * b - 10000000 * c) / 1000000;
	e = (int)((t)-100000000 * b - 10000000 * c - 1000000 * d) / 100000;
	f = (int)((t)-100000000 * b - 10000000 * c - 1000000 * d - 100000 * e) / 10000;
	g = (int)((t)-100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f) / 1000;
	h = (int)((t)-100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g) / 100;
	i = (int)((t)-100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h) / 10;
	j = (int)((t)-100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i);
	k = (int)((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 + 0.001);
	l = (int)(((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 - k) * 10 + 0.001);
	m = (int)((((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 - k) * 10 - l) * 10 + 0.001);
	printf("ʮ��λ ��%d\n", b);
	printf("��λ   ��%d\n", c);
	printf("ǧ��λ ��%d\n", d);
	printf("����λ ��%d\n", e);
	printf("ʮ��λ ��%d\n", f);
	printf("��λ   ��%d\n", g);
	printf("ǧλ   ��%d\n", h);
	printf("��λ   ��%d\n", i);
	printf("ʮλ   ��%d\n", j);
	printf("Բ     ��%d\n", k);
	printf("��     ��%d\n", l);
	printf("��     ��%d\n", m);
	return 0;
}