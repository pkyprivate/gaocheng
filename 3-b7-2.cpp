#include<iostream>
using namespace std;
int main() {
	cout << "请输入找零值：" << endl;
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
	cout << "共" << sum << "张找零，" << "具体如下：" << endl;


	if (a != 0)
		cout << "50元 : " << a << "张" << endl;

	if (b != 0)
		cout << "20元 : " << b << "张" << endl;

	if (c != 0)
		cout << "10元 : " << c << "张" << endl;

	if (d != 0)
		cout << "5元  : " << d << "张" << endl;

	if (e != 0)
		cout << "1元  : " << e << "张" << endl;

	if (f != 0)
		cout << "5角  : " << f << "张" << endl;

	if (g != 0)
		cout << "1角  : " << g << "张" << endl;

	if (h != 0)
		cout << "5分  : " << h << "张" << endl;

	if (i != 0)
		cout << "2分  : " << i << "张" << endl;

	if (j != 0)
		cout << "1分  : " << j << "张" << endl;


	return 0;
}