//2151753 ������ �ƿ�

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
struct KFC {
	char flag;
	char name[100];
	double  price;
};
struct SPECIAL {
	char flag[100];
	char name[100];
	double  price;
};
void output_menu(KFC *list,SPECIAL *special,int num,int together) {
	cout << "==============================================================" << endl;
	cout << "                          KFC�＾�˵�                        " << endl;
	cout << "==============================================================" << endl;
	for (int i = 0; i <together; i++) {
		cout << " ";
		cout << list[i].flag;
		cout << "  ";
		cout << std::left << setw(20) << list[i].name;
		cout << std::left << setw(7) << list[i].price;
		if (i % 2 == 0)
			cout << std::left << setw(3) << "|";
		if (i % 2 == 1)
			cout << endl;
	}
	cout << endl;
	cout << "���Ż���Ϣ��:" << endl;
	for (int i = together; i < num-1; i++) {
		cout << setw(18)<<special[i].flag;
		cout << setw(18)<<special[i].name;
		cout << setw(4)<<special[i].price << endl;
	}
	cout << "���������˵����:" << endl;
	cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
	cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
	cout << endl;
	cout << "��㵥:";
}

int main()
{
	KFC list[100];
	SPECIAL special[100];
	int num = 0;
	int together = 0;
	bool check = 1;
	ifstream file("KFC-price2.cfg", ios::in);
	if (file.is_open() == 0) {
		cout << "�ļ���ʧ��" << endl;
		return 0;
	}
	while (file.peek() != EOF) {
		char input[100];
		file >> input;
		if (!strcmp(input, "[��Ʒ�˵�]") || !strcmp(input, "[��ϲ˵�]"))
			continue;
		if (input[0] == '#') {
			file.ignore(65536, '\n');
			continue;
		}
		if (strlen(input) > 1 && check) {
			together = num;
			check = 0;
		}
		if (check) {
			list[num].flag = input[0];
			file >> list[num].name;
			file >> list[num++].price;
		}
		else {
			strcpy_s(special[num].flag, input);
			file >> special[num].name;
			file >> special[num++].price;
		}
	}
	file.close();
	while (1) {
		char choose[27], * p = choose;
		output_menu(list,special,num,together);
		double money = 0;
		int t;
		bool x = 1;
		while (1) {
			cin >> choose;
			if (choose[0] == '0' && choose[1] == '\0') {
				return 0;
			}
			for (; *p != '\0'; p++) {
				if (*p < 'A' || *p>'Z') {
					x = 0;
					cout << "������󣬰����������" << endl;
					t = _getch();
					system("cls");
					output_menu(list, special, num, together);
					break;
				}
			}
			if (x == 1) {
				p = choose;
				break;
			}
			if (x == 0)
				x = 1;
		}
		int number[26];
		for (int i = 0; i <= 25; i++) {
			number[i] = 0;
		}
		for (; *p != '\0'; p++) {
			for (int i = 0; i <= 25; i++) {
				if (*p == list[i].flag) {
					money = money + list[i].price;
					number[i]++;
					break;
				}
			}
		}
		bool add = 0;
		cout << "���ĵ��=";
		for (int i = 0; i <= 25; i++) {
			if (number[i] != 0) {
				if (add == 1)
					cout << "+";
				add = 1;
				cout << list[i].name;
				if (number[i] != 1) {
					cout << "*" << number[i];
				}
			}
		}
		cout << endl;
		if (number[0] >= 1 && number[1] >= 1 && number[2] >= 1 && number[6] >= 2 && number[8] >= 2 && number[10] >= 2 && number[14] >= 1 && number[20] >= 1 && number[22] >= 3) {
			number[0] -= 1;
			number[1] -= 1;
			number[2] -= 1;
			number[6] -= 2;
			number[8] -= 2;
			number[10] -= 2;
			number[14] -= 1;
			number[20] -= 1;
			number[22] -= 3;
			money = money - 37.5;
		}
		if (number[9] >= 2) {
			number[9] -= 2;
			money -= 10.5;
		}
		if (number[8] >= 2 && number[9] >= 1 && number[10] >= 1 && number[17] >= 2 && number[20] >= 1 && number[22] >= 2) {
			number[8] -= 2;
			number[9] -= 1;
			number[10] -= 1;
			number[17] -= 2;
			number[20] -= 1;
			number[22] -= 2;
			money -= 22.5;
		}
		if (number[1] >= 1 && number[12] >= 1 && number[21] >= 1) {
			number[1] -= 1;
			number[12] -= 1;
			number[21] -= 1;
			money -= 12.5;
		}
		cout << "����:" << " " << money << "Ԫ" << endl;
		cout << "�㵥��ɣ������������" << endl;
		t = _getch();
		system("cls");
	}
	return 0;
}