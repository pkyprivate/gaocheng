//2151753 ������ �ƿ�
#include <iostream>
using namespace std;
int main()
{
	cout << "������һ��[1..30000]�������:" << endl;
	int a, b, c, d, e, f;
	cin >> a;
	b = a / 10000;
	c = (a - 10000 * b) / 1000;
	d = (a - 10000 * b - 1000 * c) / 100;
	e = (a - 10000 * b - 1000 * c - 100 * d) / 10;
	f = (a - 10000 * b - 1000 * c - 100 * d - 10 * e);
	cout << "��λ ��" << b << endl;
	cout << "ǧλ ��" << c << endl;
	cout << "��λ ��" << d << endl;
	cout << "ʮλ ��" << e << endl;
	cout << "��λ ��" << f << endl;
	return 0;
}