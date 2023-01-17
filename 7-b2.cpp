//2151753 ������ �ƿ�
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct KFC {
	char flag;
	char name[100];
	double  price;
};

struct SPECIAL {
	char flag[20];
	char name[100];
	double  price;
};
const struct KFC list[] = {
		{'A', "�������ȱ�", 18.5},
		{ 'B', "���༦�ȱ�",         18.5 },
		{ 'C', "�°¶��������ȱ�",   19 },
		{ 'D', "�ϱ��������",       17 },
		{ 'E', "������ţ��",         19.5 },
		{ 'F', "����㱤",         18.5 },
		{ 'G', "˱ָԭζ��(1��)",    11.5 },
		{ 'H', "֥֥����������Ƥ��", 12.5 },
		{ 'I', "�°¶�������(2��)",  12.5 },
		{ 'J', "�������׻�",         11.5 },
		{ 'K', "��������(2��)",      12.0 },
		{ 'L', "�ٽ��޹Ǵ���(2��)",12.5 },
		{ 'M', "����ɫ��",           13 },
		{ 'N', "����(С)",           9 },
		{ 'O', "����(��)",           12 },
		{ 'P', "����(��)",           14 },
		{ 'Q', "ܽ��������",         9 },
		{ 'R', "ԭζ��Ͳ������",     6 },
		{ 'S', "����������",         7 },
		{ 'T', "�������װ�",         9.0 },
		{ 'U', "��ʽ��̢",           8.0 },
		{ 'V', "���¿���(С)",       7.0 },
		{ 'W', "���¿���(��)",       9.5 },
		{ 'X', "���¿���(��)",       11.5 },
		{ 'Y', "�����֭����",       12.5 },
		{ 'Z', "����������",         11.5 },
		{ '\0', NULL,                0 }
};
const struct SPECIAL special[] = {
	//{"ANV", "�������ȱ����������",  24}, //�������Ҫ���ſ����ע�͵���һ�еġ�BMV���Żݣ��۲��Żݲ˵��Ƿ����˱仯
	{"BMV", "���༦�ȱ���ֵ�ײ�", 26},
	{ "ABCGGIIKKOUWWW", "��ֵȫ��Ͱ", 115 },
	{ "KIIRRJUWW", "�ͷ�С��Ͱ",      65 },
	{ "JJ","�������׻�(2��С)",       12.5 },
	{ NULL, NULL, 0 }
};
void output_menu() {
	cout << "==============================================================" << endl;
	cout << "                          KFC�＾�˵�                        " << endl;
	cout << "==============================================================" << endl;
	for (int i = 0; i < 24; i++) {
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
	cout << special[0].name << "=" << list[1].name << "+" << list[12].name << "+" << list[21].name << "=" << special[0].price << endl;
	cout << special[1].name << "=" << list[0].name << "+" << list[1].name << "+" << list[2].name << "+" << list[6].name << "*2+" << list[8].name << "*2+" << list[10].name << "*2+" << list[14].name << "+" << list[20].name << "+" << list[22].name << "*3=" << special[1].price << endl;
	cout << special[2].name << "=" << list[8].name << "*2+" << list[9].name << "+" << list[10].name << "+" << list[16].name << "*2+" << list[19].name << "+" << list[22].name << "*2=" << special[2].price << endl;
	cout << special[3].name << "=" << list[9].name << "*2=" << special[3].price << endl;
	cout << "���������˵����:" << endl;
	cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
	cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
	cout << endl;
	cout << "��㵥:";

}

char* tj_strupr(char* str)
{
	char* p = str;
	if (str == NULL)
		return NULL;
	while (1) {
		if (*p == '\0')
			break;
		if (*p >= 'a' && *p <= 'z')
			*p = *p - 32;
		p++;
	}

	return str;
}

int main() 
{
	
	while (1) {
		char choose[27], * p = choose;
		output_menu();
		double money = 0;
		int t;
		bool x = 1;
		while (1) {
			cin >> choose;
			if (choose[0] == '0' && choose[1] == '\0') {
				return 0;
			}
			tj_strupr(choose);
			for (; *p != '\0'; p++) {
				if (*p < 'A' || *p>'Z') {
					x = 0;
					cout << "������󣬰����������" << endl;
					t = _getch();
					system("cls");
					output_menu();
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
}
