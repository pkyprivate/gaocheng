//2151753 ������ �ƿ�
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	double pi = 3.14159;
	double a, b, c, d, e, f, g;
	cout << "������뾶�͸߶�" << endl;
	cin >> a >> b;
	c = 2 * pi * a;
	d = pi * a * a;
	e = 4 * pi * a * a;
	f = 4.0 / 3 * pi * a * a * a;
	g = pi * a * a * b;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "Բ�ܳ�     ��" << c << endl;
	cout << "Բ���     ��" << d << endl;
	cout << "Բ������ ��" << e << endl;
	cout << "Բ�����   ��" << f << endl;
	cout << "Բ�����   ��" << g << endl;
	return 0;
}