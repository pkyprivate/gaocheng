//2151753 �ƿ� ������
#include<iostream>
using namespace std;
int main()
{
	cout << "�������꣬�£���" << endl;
	int year, month, day;
	int z = 0;
	bool a, b;
	cin >> year >> month >> day;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		switch (month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (day > 31) {
					cout << "�������-�����µķǷ���ϵ" << endl;
					a = 0;
				}
				else {
					a = 1;
				}
				break;
			case 2:
				if (day > 29) {
					cout << "�������-�����µķǷ���ϵ" << endl;
					a = 0;
				}
				else {
					a = 1;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30) {
					cout << "�������-�����µķǷ���ϵ" << endl;
					a = 0;
				}
				else {
					a = 1;
				}
				break;
			default:
				cout << "�������-�·ݲ���ȷ" << endl;
				a = 0;
				break;
		}
		if (a == 1)
		{
			switch (month) {
				case 1:
					z = day;
					break;
				case 2:
					z = 31 + day;
					break;
				case 3:
					z = 60 + day;
					break;
				case 4:
					z = 91 + day;
					break;
				case 5:
					z = 121 + day;
					break;
				case 6:
					z = 152 + day;
					break;
				case 7:
					z = 182 + day;
					break;
				case 8:
					z = 213 + day;
					break;
				case 9:
					z = 243 + day;
					break;
				case 10:
					z = 274 + day;
					break;
				case 11:
					z = 305 + day;
					break;
				case 12:
					z = 335 + day;
					break;
			}
			cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << z << "��" << endl;
		}
	}
	else {
		switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (day > 31) {
					cout << "�������-�����µķǷ���ϵ" << endl;
					b = 0;
				}
				else {
					b = 1;
				}
				break;
			case 2:
				if (day > 28) {
					cout << "�������-�����µķǷ���ϵ" << endl;
					b = 0;
				}
				else {
					b = 1;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30) {
					cout << "�������-�����µķǷ���ϵ" << endl;
					b = 0;
				}
				else {
					b = 1;
				}
				break;
			default:
				cout << "�������-�·ݲ���ȷ" << endl;
				b = 0;
				break;
		}
		if (b == 1) {
			switch (month) {
				case 1:
					z = day;
					break;
				case 2:
					z = 31 + day;
					break;
				case 3:
					z = 59 + day;
					break;
				case 4:
					z = 90 + day;
					break;
				case 5:
					z = 120 + day;
					break;
				case 6:
					z = 151 + day;
					break;
				case 7:
					z = 181 + day;
					break;
				case 8:
					z = 212 + day;
					break;
				case 9:
					z = 243 + day;
					break;
				case 10:
					z = 273 + day;
					break;
				case 11:
					z = 304+ day;
					break;
				case 12:
					z = 334 + day;
					break;
			}
			cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << z << "��" << endl;
		}
	}
	return 0;

}