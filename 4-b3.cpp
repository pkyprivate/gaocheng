//2151753 计科 彭坤宇
#include<iostream>
#include<iomanip>
using namespace std;
int zeller(int y, int m);
int main() {
	int a, b, t, x = 1;
	cout << "请输入年[1900-2100]、月" << endl;
	cin >> a >> b;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(65535, '\n');
		cout << "输入错误，请重新输入" << endl;
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> a >> b;
	}//判断是否合法
	while (x) {
		if (a > 2100 || a < 1900) {
			cout << "年份不正确，请重新输入" << endl;
			cout << "请输入年[1900-2100]、月" << endl;
			cin >> a >> b;
			x = 1;
		}
		else {
			if (b < 0 || b>12) {
				cout << "月份不正确，请重新输入" << endl;
				cout << "请输入年[1900-2100]、月" << endl;
				cin >> a >> b;
				x = 1;
			}
			else {
				x = 0;
			}
		}
	}//判断是否合适
	cout << endl;
	cout << a << "年" << b << "月" << endl;
	t = zeller(a, b);
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;
	if (t != 0) {
		cout << setw(6 * t + 2 * t) << " ";
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
		while ((x + t) < length) {
			cout << "  ";
			cout << setw(2) << x++;
			cout << "    ";
			if (x > all)
				break;
		}
		cout << endl;
		length += 7;
	}
	if ((x + t) == (length - 7))
		cout << endl;
	cout << endl;
	return 0;
}

int zeller(int y, int m) {
	int w, c, e, f, g;
	if (m == 1) {
		m = 13;
		y -= 1;
	}
	if (m == 2) {
		m = 14;
		y -= 1;
	}
	c = y / 100;
	e = y - 100 * c; 100;
	f = 13 * (m + 1);
	w = e + e / 4 + c / 4 - 2 * c + f / 5;
	while (w < 0) {
		w += 7;
	}
	g = w % 7;
	return g;
}