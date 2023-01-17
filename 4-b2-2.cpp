//2151753 彭坤宇 计科
#include<iostream>
using namespace std;
int zeller(int y, int m, int d);
int main()
{
	int a, b, c, t;
	cout << "请输入年[1900-2100]、月、日：" << endl;
	cin >> a >> b >> c;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(65536, '\n');
		cout << "输入错误，请重新输入" << endl;
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> a >> b >> c;
	}
	int x;
	x = 1;
	while (x) {
		if (a > 2100 || a < 1900) {
			cout << "年份不正确，请重新输入" << endl;
			cout << "请输入年[1900-2100]、月、日：" << endl;
			cin >> a >> b >> c;
			x = 1;
		}
		else {
			if (b < 0 || b>12) {
				cout << "月份不正确，请重新输入" << endl;
				cout << "请输入年[1900-2100]、月、日：" << endl;
				cin >> a >> b >> c;
				x = 1;
			}
			else {
				if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {
					switch (b) {
						case 1:
						case 3:
						case 5:
						case 7:
						case 8:
						case 10:
						case 12:
							if (c < 1 || c>31) {
								cout << "日不正确，请重新输入" << endl;
								cout << "请输入年[1900-2100]、月、日：" << endl;
								cin >> a >> b >> c;
								x = 1;
							}
							else x = 0;
							break;
						case 2:
							if (c < 1 || c>29) {
								cout << "日不正确，请重新输入" << endl;
								cout << "请输入年[1900-2100]、月、日：" << endl;
								cin >> a >> b >> c;
								x = 1;
							}
							else x = 0;
							break;
						case 4:
						case 6:
						case 9:
						case 11:
							if (c < 1 || c>30) {
								cout << "日不正确，请重新输入" << endl;
								cout << "请输入年[1900-2100]、月、日：" << endl;
								cin >> a >> b >> c;
								x = 1;
							}
							else x = 0;
							break;
					}
				}
				else {
					switch (b) {
						case 1:
						case 3:
						case 5:
						case 7:
						case 8:
						case 10:
						case 12:
							if (c < 1 || c>31) {
								cout << "日不正确，请重新输入" << endl;
								cout << "请输入年[1900-2100]、月、日：" << endl;
								cin >> a >> b >> c;
								x = 1;
							}
							else x = 0;
							break;
						case 2:if (c < 1 || c>28) {
							cout << "日不正确，请重新输入" << endl;
							cout << "请输入年[1900-2100]、月、日：" << endl;
							cin >> a >> b >> c;
							x = 1;
						}
							  else x = 0;
							break;
						case 4:
						case 6:
						case 9:
						case 11:
							if (c < 1 || c>30) {
								cout << "日不正确，请重新输入" << endl;
								cout << "请输入年[1900-2100]、月、日：" << endl;
								cin >> a >> b >> c;
								x = 1;
							}
							else x = 0;
							break;
					}
				}
			}





		}
	}
	t = zeller(a, b, c);
	switch (t) {
		case 0:cout << "星期日" << endl;
			break;
		case 1:cout << "星期一" << endl;
			break;
		case 2:cout << "星期二" << endl;
			break;
		case 3:cout << "星期三" << endl;
			break;
		case 4:cout << "星期四" << endl;
			break;
		case 5:cout << "星期五" << endl;
			break;
		case 6:cout << "星期六" << endl;
			break;
	}
	return 0;
}

int zeller(int y, int m, int d) {
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
	w = e + e / 4 + c / 4 - 2 * c + f / 5 + d - 1;
	while (w < 0) {
		w += 7;
	}
	g = w % 7;
	return g;
}

