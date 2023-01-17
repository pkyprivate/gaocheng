
#include <iostream>
using namespace std;

/* 1�����������κ����͵�ȫ�ֱ������������������궨���
   2������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

	/* ������Բ�����Ҫ�����Ա�����Ķ��壨���ṩ����磬���������������Ա�������ã��������Ϊ˽�У��������ޣ��������壩 */
public:
	int calc_days();     //�����ǵ���ĵڼ���
	/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������ޣ��������� */
	Days(int year1, int month1, int day1);
};

/* --- �˴��������Ա����������ʵ�� --- */
int Days::calc_days() {
	int z = 0;
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
				if (day > 31)
					return -1;
				break;
			case 2:
				if (day > 29)
					return -1;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30)
					return -1;
				break;
			default:
				return -1;
		}
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
				if (day > 31)
					return -1;
				break;
			case 2:
				if (day > 28)
					return -1;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30)
					return -1;
				break;
			default:
				return -1;
		}
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
				z = 304 + day;
				break;
			case 12:
				z = 334 + day;
				break;
		}
	}
	return z;
}
Days::Days(int year1, int month1, int day1)
{
	day = day1;
	year = year1;
	month = month1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}
