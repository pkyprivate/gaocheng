//2151753 ������ �ƿ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double pi = 3.14159;
	double a, b, c, d, e, f, g;
	printf("������뾶�͸߶�\n");
	//cout << "������뾶�͸߶�" << endl;
	scanf("%lf %lf", &a, &b);
	c = 2 * pi * a;
	d = pi * a * a;
	e = 4 * pi * a * a;
	f = 4.0 / 3 * pi * a * a * a;
	g = pi * a * a * b;
	printf("Բ�ܳ�     ��%.2f\n", c);
	printf("Բ���     ��%.2f\n", d);
	printf("Բ������ ��%.2f\n", e);
	printf("Բ�����   ��%.2f\n", f);
	printf("Բ�����   ��%.2f\n", g);
	return 0;
}