//2151753 ������ �ƿ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a, t;
	int b, c, d, e, f, g, h, i, j, k, l, m;
	printf( "������[0-100��)֮�������:\n");
	scanf("%lf",&a);
	printf("��д�����:\n"); 
	t = a / 10.0;
	b = (int)(t) / 100000000;
	c = ((int)(t) - 100000000 * b) / 10000000;
	d = ((int)(t) - 100000000 * b - 10000000 * c) / 1000000;
	e = ((int)(t) - 100000000 * b - 10000000 * c - 1000000 * d) / 100000;
	f = ((int)(t) - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e) / 10000;
	g = ((int)(t) - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f) / 1000;
	h = ((int)(t) - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g) / 100;
	i = ((int)(t) - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h) / 10;
	j = ((int)(t) - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i);
	k = (int)((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 + 0.001);
	l = (int)(((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 - k) * 10 + 0.001);
	m = (int)((((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 - k) * 10 - l) * 10 + 0.001);

	switch (b) {
		case 0:
			break;
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			printf( "error");
			break;
	}
	if (b != 0) {
		printf( "ʰ");
	}
	switch (c) {
		case 0:
			break;
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			printf( "error");
			break;
	}
	if (b * b + c * c != 0) {
		printf( "��");
	}

	//��ǰ��λ�������
	switch (d) {
		case 0:
			if (b * b + c * c != 0 && e * e + f * f + g * g != 0)
				printf( "��");
			break;
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			printf( "error");
			break;
	}
	if (d != 0) {
		printf( "Ǫ");
	}

	switch (e) {
		case 0:
			if (d != 0 && f * f + g * g != 0)
				printf( "��");
			break;
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			printf( "error");
			break;
	}
	if (e != 0) {
		printf( "��");
	}

	switch (f) {
		case 0:
			if (e != 0 && d * d + e * e + f * f + g * g != 0 && g != 0)
				printf( "��");
			break;
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			printf( "error");
			break;
	}
	if (f != 0) {
		printf( "ʰ");
	}

	switch (g) {
		case 0:
			break;
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			printf( "error");
			break;
	}
	if (d * d + e * e + f * f + g * g != 0) {
		printf( "��");
	}
	//���м���λ�������

	switch (h) {
		case 0:
			if (b * b + c * c + d * d + e * e + f * f + g * g != 0 && h * h + i * i + j * j + k * k != 0)
				printf( "��");
			break;
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			printf( "error");
			break;
	}
	if (h != 0) {
		printf( "Ǫ");
	}

	switch (i) {
		case 0:
			if (h != 0 && h * h + i * i + j * j + k * k != 0 && j * j + k * k != 0)
				printf( "��");
			break;
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			printf( "error");
			break;
	}
	if (i != 0) {
		printf( "��");
	}

	switch (j) {
		case 0:
			if (i != 0 && h * h + i * i + j * j + k * k != 0 && k != 0)
				printf( "��");
			break;
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			printf( "error");
			break;
	}
	if (j != 0) {
		printf( "ʰ");
	}
	int x;
	x = b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k == 0 && l * l + m * m == 0;
	switch (k) {
		case 0:
			if (x)
				printf( "��");
			break;
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			printf( "error");
			break;
	}
	if (b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k != 0 || x) {
		printf( "Բ");
	}
	if (l * l + m * m == 0) {
		printf( "��");
	}
	//�Ժ���λ�������
	switch (l) {
		case 0:
			if (m != 0 && b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k != 0)
				printf( "��");
			break;
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			printf( "error");
			break;
	}
	if (l != 0) {
		printf( "��");
	}

	if (l != 0 && m == 0) {
		printf( "��");
	}

	switch (m) {
		case 0:
			break;
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			printf( "error");
			break;
	}
	if (m) {
		printf( "��");
	}
	//�����λ���
	printf( "\n");
	return 0;
}
