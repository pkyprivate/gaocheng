//2151753 �ƿ� ������
#include<iostream>
#include<iomanip>
using namespace std;
int main() 
{
	int a, b, c, x = 1;
	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> a >> b;
		if (cin.good() && (a >= 2000 && a <= 2030) && (b <= 12 && b >= 1))
			break;
		else {
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "����Ƿ�������������" << endl;
		}
	}
	while (1) {
		cout << "������" << a << "��" << b << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> c;
		if (cin.good() && c <= 6 && c >= 0)
			break;
		else {
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "����Ƿ�������������" << endl;
		}
	}
	cout << endl;
	cout << a << "��" << b << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
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
