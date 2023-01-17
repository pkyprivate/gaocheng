
/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class stu_list;
#define MAX_STU_NUM			256	//Լ���������Ϊ256�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			32	//ѧ����������󳤶Ȳ�����16������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_info {
private:
	int  stu_no;			//ѧ��
	char stu_name[MAX_NAME_LEN];	//����
	int  first;
	int  second;
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */


public:
	/* ���಻�������κεĹ������ݳ�Ա����Ա���� */
	friend stu_list;
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	int num;
	/* ���������private���ݳ�Ա�ͳ�Ա���� */

public:
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	int print(const char* prompt = NULL);			//��ӡ��ǰ�����ѡ������

	/* �������������public��Ա���� */

};

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */
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
	cout << "��� ѧ��    ����                             ��һ�� �ڶ���" << endl;
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
			cout << "��ѡ" << endl;
		if (stu[i].first == 1 && stu[i].second != 1)
			cout << "�˿�" << endl;
	}
	cout << setw(59) << setfill('=') << "=" << endl;
	return 0;
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
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;

	/* �����һ�������ļ� */
	if (list.read(file1) < 0)
		return -1;

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}
