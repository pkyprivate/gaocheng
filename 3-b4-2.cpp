//2151753 ������ �ƿ�
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	cout << "�����������ε����߼���н�(�Ƕȣ�" << endl;
	int a, b, c;
	double pi = 3.14159;
	float s;
	cin >> a >> b >> c;
	s = float(0.5 * a * b * sin(c * pi / 180));
	cout << "�����ε����Ϊ ��" << fixed << setprecision(3) << s << endl;
	return 0;
}