//2151753 ������ �ƿ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

int main()
{
	printf("���ε����߼���н�(�Ƕȣ�\n");
	int a, b, c;
	double pi = 3.14159;
	float s;
	scanf(" %d %d %d", &a, &b, &c);
	s = (float)(0.5 * a * b * sin(c * pi / 180));
	printf("�����ε����Ϊ ��%.3f", s);
	return 0;
}