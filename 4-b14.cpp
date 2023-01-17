//2151753 彭坤宇 计科
#include<iostream>
using namespace std;

int max(int a, int b) {
	int x;
	x = (a > b ? a : b);
	return x;
}
int max(int a, int b,int c) {
	int x;
	x = (a > b ? a : b);
	x = (x > c ? x : c);
	return x;
}
int max(int a, int b, int c,int d) {
	int x;
	x = (a > b ? a : b);
	x = (x > c ? x : c);
	x = (x > d? x : d);
	return x;
}
int main()
{
	int x;
	bool check = 0;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		int number;
		cin >> number;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65526, '\n');
			continue;
		}
		if (number < 2 || number>4) {
			check = 1;
			break;
		}
		if (number == 2) {
			int a, b;
			cin >> a >> b;
			if (cin.fail()) {
					cin.clear();
					cin.ignore(65526, '\n');
					continue;
				}
			else {
				x = max(a, b);
				cout << "max=" << x << endl;
				break;
			}
		}
		if (number == 3) {
			int a, b,c;
			cin >> a >> b>>c;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(65526, '\n');
				continue;
			}
			else {
				x = max(a, b,c);
				cout << "max=" << x << endl;
				break;
			}
		}
		if (number == 4) {
			int a, b, c,d;
			cin >> a >> b >> c>>d;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(65526, '\n');
				continue;
			}
			else {
				x = max(a, b, c,d);
				cout << "max=" << x << endl;
				break;
			}
		}
	}
	if (check)
		cout << "个数输入错误" << endl;
	return 0;
}
