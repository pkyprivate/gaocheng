
/* 允许按需加入系统的宏定义、需要的头文件等 */
#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class stu_list;
#define MAX_STU_NUM			256	//约定最大人数为256人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			32	//学生姓名的最大长度不超过16个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_info {
private:
	int  stu_no;			//学号
	char stu_name[MAX_NAME_LEN];	//姓名
	int  first;
	int  second;
	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */


public:
	/* 本类不允许定义任何的公有数据成员、成员函数 */
	friend stu_list;
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	int num;
	/* 允许按需加入private数据成员和成员函数 */

public:
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	int print(const char* prompt = NULL);			//打印当前读入的选课名单

	/* 允许按需加入其它public成员函数 */

};

/* --- 此处给出上面两个类的成员函数的体外实现 --- */
int stu_list::read(const char* filename, const int append ) {
	int i = 0;
	ifstream file(filename, ios::in | ios::binary);
	if (file.is_open() == 0)
		return -1;
	if (append == 0) {
		while (file.peek() != EOF) {
			file >> stu[i].stu_no;
			file >> stu[i].stu_name;
			stu[i].second = 0;
			stu[i++].first = 1;
		}
		num = i;
	}
	if (append == 1) {
		while (file.peek() != EOF) {
			stu_info s;
			file >> s.stu_no;
			file >> s.stu_name;
			bool check = 1;
			for (int j = 0; j < num; j++) {
				if (stu[j].stu_no == s.stu_no) {
					stu[j].second = 1;
					check = 0;
					break;
				}
			}
			if (check) {
				s.first = 0;
				s.second = 1;
				stu[num++] = s;
			}
		}
	}
	file.close();
	return 0;
}
int stu_list::print(const char* prompt) {
	cout << prompt << endl;
	cout << setw(59) << setfill('=') << "=" << endl;
	cout << "序号 学号    姓名                             第一轮 第二轮" << endl;
	cout << setw(59) << setfill('=') << "=" << endl;
	cout << setfill(' ');
	for (int i = 0; i < num; i++) {
		for (int j = i ; j < num; j++) {
			if (stu[i].stu_no > stu[j ].stu_no) {
				stu_info temp;
				temp = stu[i];
				stu[i] = stu[j ];
				stu[j] = temp;
			}
		}
	}
	for (int i = 0; i < num; i++) {
		cout << setiosflags(ios::left) << setw(5) << i + 1;
		cout << stu[i].stu_no;
		cout << " ";
		cout << setiosflags(ios::left) << setw(33)<<stu[i].stu_name;
		if (stu[i].first == 1)
			cout << "Y";
		else
			cout << "/";
		cout << setw(6) << " ";
		if (stu[i].first == 1 && stu[i].second == 1)
			cout << "Y" << endl;
		if (stu[i].first!= 1 && stu[i].second == 1)
			cout << "补选" << endl;
		if (stu[i].first == 1 && stu[i].second != 1)
			cout << "退课" << endl;
	}
	cout << setw(59) << setfill('=') << "=" << endl;
	return 0;
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
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;

	/* 读入第一个数据文件 */
	if (list.read(file1) < 0)
		return -1;

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}
