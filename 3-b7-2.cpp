#include<iostream>
using namespace std;
int main() {
	cout << "����������ֵ��" << endl;
	double money;
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, sum;
	cin >> money;
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
	cout << "��" << sum << "�����㣬" << "�������£�" << endl;


	if (a != 0)
		cout << "50Ԫ : " << a << "��" << endl;

	if (b != 0)
		cout << "20Ԫ : " << b << "��" << endl;

	if (c != 0)
		cout << "10Ԫ : " << c << "��" << endl;

	if (d != 0)
		cout << "5Ԫ  : " << d << "��" << endl;

	if (e != 0)
		cout << "1Ԫ  : " << e << "��" << endl;

	if (f != 0)
		cout << "5��  : " << f << "��" << endl;

	if (g != 0)
		cout << "1��  : " << g << "��" << endl;

	if (h != 0)
		cout << "5��  : " << h << "��" << endl;

	if (i != 0)
		cout << "2��  : " << i << "��" << endl;

	if (j != 0)
		cout << "1��  : " << j << "��" << endl;


	return 0;
}