
#include <iostream>
#include <conio.h>
using namespace std;

/* --- �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� --- */

/* --- ���������ȫ�ֺ�����Ҫ������д�ڴ˴� --- */
void find(int& year0, int& month0, int& day0, int d);
/* ��ȫDate��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class Date {
private:
	int year;
	int month;
	int day;
	/* ������������ݳ�Ա */
public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������(������������ݳ�Ա) */
	Date(int year1, int month1, int day1 );
	Date();
	Date(int day0);
	void show();
	void set(int year1, int month1=1, int day1=1);
	void get(int& year1, int& month1, int& day1);
};

/* --- ���� Date ������г�Ա����������ʵ�� --- */
Date::Date(int year1, int month1, int day1 ) {
	if (year1 < 1900)
		year1 = 2000;
	year = year1;
	if (month1 < 1 || month1>12)
		month1 = 1;
	month = month1;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (day1 > 31||day1<1)
					day1 = 1;
				break;
			case 2:
				if (day1 > 29 || day1 < 1)
					day1 = 1;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day1 > 30 || day1 < 1)
					day1 = 1;
				break;
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
				if (day1 > 31 || day1 < 1)
					day1 = 1;
				break;
			case 2:
				if (day1 > 28 || day1 < 1)
					day1 = 1;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day1 > 30 || day1 < 1)
					day1 = 1;
				break;
		}
	}
	day = day1;
}
Date::Date() {
	year = 2000;
	month = 1;
	day = 1;
}
Date::Date(int day0) {
	if (day0 < 0)
	day0 = 1;
	find(year, month, day, day0);
}
void Date::show() {
	cout << year << "." << month << "." << day << endl;
}
void Date::get(int& year1, int& month1, int& day1) {
	year1 = year;
	month1 = month;
	day1 = day;
}
void Date::set(int year1, int month1, int day1) {
	int m1[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int m2[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year1 == 0)
		year1 = year;
	if (month1 == 0)
		month1 = month;
	if (day1 == 0)
		day1 = day;
	if (year1 < 2099&&year1>=1900)
		year = year1;
	else {
		year1 = 2000;
		year = 2000;
	}
	if (month1 < 13 && month1>0) {
		month = month1;
	}
	else {
		month1 = 1;
		month = 1;
	}
	if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)) {
		if (m1[month1] >= day1) {
			day = day1;
		}
		else
			day = 1;
	}
	else {
		if (m2[month1] >= day1) {
			day = day1;
		}
		else
			day = 1;
	}
}
/* --- �������Ҫ������ȫ�ֺ�����ʵ�֣�����д�ڴ˴� --- */
void find(int& year0, int& month0, int& day0, int d) {
	int m1[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int m2[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	year0 = 1900;
	month0 = 1;
	day0 = 0;
	while (1) {
		if ((year0 % 4 == 0 && year0 % 100 != 0) || (year0 % 400 == 0)) {
			if (d > 366) {
				d = d - 366;
				year0++;
			}
			else
				break;
		}
		else {
			if (d > 365) {
				d =d- 365;
				year0++;
			}
			else
				break;
		}
	}
	if ((year0 % 4 == 0 && year0 % 100 != 0) || (year0 % 400 == 0)) {
		for (int i = 1; i < 13; i++) {
			if (d > m1[i]) {
				d -= m1[i];
				month0++;
			}
			else
				break;
		}
		day0 = d;
	}
	else {
		for (int i = 1; i < 13; i++) {
			if (d > m2[i]) {
				d -= m2[i];
				month0++;
			}
			else
				break;
		}
		day0 = d;
	}
	if (year0 > 2099) {
		year0 = 2099;
		month0 = 12;
		day0 = 31;
	}
}
/* -- �滻����� -- ���в�Ҫ���κθĶ� -- ���в�Ҫɾ�� -- �ڱ��е����治Ҫ�����κ��Լ�����䣬��ҵ�ύ��ӱ��п�ʼ�ᱻ�滻 -- �滻����� -- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "���س�������";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��������ʱ���滻
***************************************************************************/
int main()
{
	if (1) {
		Date d1;				//2000.1.1
		Date d2(2022, 12, 9);	//2022.12.9

		cout << "�޲μ����ι��캯�����ԣ���ȫ��ȷ��" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����2000.1.1�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2022.12.9��ʵ��Ϊ��";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1870, 3, 15);  //2000.3.15
		Date d2(2112, 3, 4);   //2000.3.4
		Date d3(2005, 13, 15); //2005.1.15
		Date d4(2022, 6, 32);  //2022.6.1

		cout << "���ι��캯�����ԣ��ꡢ�¡��շǷ���" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����2000.3.15��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2000.3.4�� ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2005.1.15��ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2022.6.1�� ʵ��Ϊ��";
		d4.show();

		/* �������������˳���� */
		Date d5(1899, 2, 29);  //2000.2.29
		Date d6(1899, 2, 30);  //2000.2.1
		Date d7(1899, 13, 31); //2000.1.31
		Date d8(1899, 13, 32); //2000.1.1
		cout << "d5Ӧ����2000.2.29��ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2000.2.1�� ʵ��Ϊ��";
		d6.show();
		cout << "d7Ӧ����2000.1.31��ʵ��Ϊ��";
		d7.show();
		cout << "d8Ӧ����2000.1.1�� ʵ��Ϊ��";
		d8.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 2, 29); //2022.2.1
		Date d2(2020, 2, 29); //2020.2.29

		cout << "���ι��캯�����ԣ����꣩" << endl;
		cout << "========================" << endl;

		cout << "d1Ӧ����2022.2.1�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2020.2.29��ʵ��Ϊ��";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1);          //1900.1.1
		Date d2(73049);      //2099.12.31
		Date d3(-100);       //1900.1.1
		Date d4(80000);      //2099.12.31
		Date d5(30000);      //1982.2.19
		Date d6(44903);      //2022.12.9

		cout << "һ�ι��캯�����ԣ������Ϸ����Ƿ�ֵ" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����1900.1.1��  ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2099.12.31��ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����1900.1.1��  ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2099.12.31��ʵ��Ϊ��";
		d4.show();
		cout << "d5Ӧ����1982.2.19�� ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2022.12.9�� ʵ��Ϊ��";
		d6.show();

		wait_for_enter();
	}


	if (1) {
		Date d1, d2, d3; //����2000.1.1

		cout << "����set����ȱʡֵ" << endl;
		cout << "=================" << endl;

		d1.set(2022, 6, 10);	//2022.6.10
		d2.set(2022, 6);		//2022.6.1
		d3.set(2022);		//2022.1.1

		cout << "d1Ӧ����2022.6.10��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2022.6.1�� ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2022.1.1�� ʵ��Ϊ��";
		d3.show();

		wait_for_enter();
	}

	if (1) {
		Date d1, d2, d3, d4;

		cout << "����set���ꡢ�¡��շǷ�" << endl;
		cout << "=======================" << endl;

		d1.set(2112, 2, 29);  //2000.2.29
		d2.set(2019, 2, 29);  //2019.2.1
		d3.set(2022, 5, 32);  //2022.5.1
		d4.set(2022, 13, 12); //2022.1.12

		cout << "d1Ӧ����2000.2.29�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2019.2.1��  ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2022.5.1��  ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2022.1.12�� ʵ��Ϊ��";
		d4.show();

		/* �����+��ȱʡֵ����������˳���� */
		Date d5(2020, 1, 31), d6(d5), d7(d5), d8(d5), d9(d5), d10(d5), d11(d5);  //2020.1.31

		d5.set(1899, 2, 29);  //2000.2.29
		d6.set(1899, 2, 30);  //2000.2.1
		d7.set(1899, 2, 0);   //2000.2.1
		d8.set(0, 2, 0);      //2020.2.1
		d9.set(0, 13, 32);    //2020.1.1
		d10.set(1899, 13, 31);  //2000.1.31
		d11.set(1899, 13, 32);  //2000.1.1
		cout << "d5Ӧ����2000.2.29�� ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2000.2.1��  ʵ��Ϊ��";
		d6.show();
		cout << "d7Ӧ����2000.2.1��  ʵ��Ϊ��";
		d7.show();
		cout << "d8Ӧ����2020.2.1��  ʵ��Ϊ��";
		d8.show();
		cout << "d9Ӧ����2020.1.1��  ʵ��Ϊ��";
		d9.show();
		cout << "d10Ӧ����2000.1.31��ʵ��Ϊ��";
		d10.show();
		cout << "d11Ӧ����2000.1.1�� ʵ��Ϊ��";
		d11.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 12, 9);
		int y, m, d;

		cout << "����get" << endl;
		cout << "=======" << endl;

		d1.get(y, m, d);
		cout << "Ӧ��y=2022,m=12,d=9��ʵ��Ϊ��";
		cout << "y=" << y << ",m=" << m << ",d=" << d << endl;

		wait_for_enter();
	}

	return 0;
}
