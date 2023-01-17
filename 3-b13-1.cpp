//2151753 计科 彭坤宇
#include<iostream>
#include<iomanip>
using namespace std;
int main() 
{
	int a, b, c, x = 1;
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> a >> b;
		if (cin.good() && (a >= 2000 && a <= 2030) && (b <= 12 && b >= 1))
			break;
		else {
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "输入非法，请重新输入" << endl;
		}
	}
	while (1) {
		cout << "请输入" << a << "年" << b << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> c;
		if (cin.good() && c <= 6 && c >= 0)
			break;
		else {
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "输入非法，请重新输入" << endl;
		}
	}
	cout << endl;
	cout << a << "年" << b << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	if (c != 0) {
		cout << setw(6 * c + 2 * c) << " ";
	}
	int length = 8,all;
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
		while ((x + c) < length) {
			cout << "  ";
			cout << setw(2) << x++;
			cout << "    ";
			if (x > all)
				break;
		}
		cout << endl;
		length += 7;
	}
	return 0;
}
