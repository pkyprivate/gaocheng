//2151753 ������ �ƿ�
#include<iostream>
using namespace std;
int zeller(int y, int m, int d);
int main()
{
	int a, b, c, t;
	cout << "��������[1900-2100]���¡��գ�" << endl;
	cin >> a >> b >> c;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(65536, '\n');
		cout << "�����������������" << endl;
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> a >> b >> c;
	}
	int x;
	x = 1;
	while (x) {
		if (a > 2100 || a < 1900) {
			cout << "��ݲ���ȷ������������" << endl;
			cout << "��������[1900-2100]���¡��գ�" << endl;
			cin >> a >> b >> c;
			x = 1;
		}
		else {
			if (b < 0 || b>12) {
				cout << "�·ݲ���ȷ������������" << endl;
				cout << "��������[1900-2100]���¡��գ�" << endl;
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
								cout << "�ղ���ȷ������������" << endl;
								cout << "��������[1900-2100]���¡��գ�" << endl;
								cin >> a >> b >> c;
								x = 1;
							}
							else x = 0;
							break;
						case 2:
							if (c < 1 || c>29) {
								cout << "�ղ���ȷ������������" << endl;
								cout << "��������[1900-2100]���¡��գ�" << endl;
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
								cout << "�ղ���ȷ������������" << endl;
								cout << "��������[1900-2100]���¡��գ�" << endl;
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
								cout << "�ղ���ȷ������������" << endl;
								cout << "��������[1900-2100]���¡��գ�" << endl;
								cin >> a >> b >> c;
								x = 1;
							}
							else x = 0;
							break;
						case 2:if (c < 1 || c>28) {
							cout << "�ղ���ȷ������������" << endl;
							cout << "��������[1900-2100]���¡��գ�" << endl;
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
								cout << "�ղ���ȷ������������" << endl;
								cout << "��������[1900-2100]���¡��գ�" << endl;
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
		case 0:cout << "������" << endl;
			break;
		case 1:cout << "����һ" << endl;
			break;
		case 2:cout << "���ڶ�" << endl;
			break;
		case 3:cout << "������" << endl;
			break;
		case 4:cout << "������" << endl;
			break;
		case 5:cout << "������" << endl;
			break;
		case 6:cout << "������" << endl;
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

