
#include <iostream>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	/* 下面可以补充需要的类成员函数的定义（不提供给外界，仅供本类的其它成员函数调用，因此声明为私有，数量不限，允许不定义） */
public:
	int calc_days();     //计算是当年的第几天
	/* 下面可以补充其它需要的类成员函数的定义(体外实现)，数量不限，允许不定义 */
	Days(int year1, int month1, int day1);
};

/* --- 此处给出类成员函数的体外实现 --- */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 3, 18);
		cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}
