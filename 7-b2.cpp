//2151753 彭坤宇 计科
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
		{'A', "香辣鸡腿堡", 18.5},
		{ 'B', "劲脆鸡腿堡",         18.5 },
		{ 'C', "新奥尔良烤鸡腿堡",   19 },
		{ 'D', "老北京鸡肉卷",       17 },
		{ 'E', "川辣嫩牛卷",         19.5 },
		{ 'F', "深海鳕鱼堡",         18.5 },
		{ 'G', "吮指原味鸡(1块)",    11.5 },
		{ 'H', "芝芝肉酥热辣脆皮鸡", 12.5 },
		{ 'I', "新奥尔良烤翅(2块)",  12.5 },
		{ 'J', "劲爆鸡米花",         11.5 },
		{ 'K', "香辣鸡翅(2块)",      12.0 },
		{ 'L', "藤椒无骨大鸡柳(2块)",12.5 },
		{ 'M', "鲜蔬色拉",           13 },
		{ 'N', "薯条(小)",           9 },
		{ 'O', "薯条(中)",           12 },
		{ 'P', "薯条(大)",           14 },
		{ 'Q', "芙蓉蔬荟汤",         9 },
		{ 'R', "原味花筒冰激凌",     6 },
		{ 'S', "醇香土豆泥",         7 },
		{ 'T', "香甜粟米棒",         9.0 },
		{ 'U', "葡式蛋挞",           8.0 },
		{ 'V', "百事可乐(小)",       7.0 },
		{ 'W', "百事可乐(中)",       9.5 },
		{ 'X', "百事可乐(大)",       11.5 },
		{ 'Y', "九珍果汁饮料",       12.5 },
		{ 'Z', "纯纯玉米饮",         11.5 },
		{ '\0', NULL,                0 }
};
const struct SPECIAL special[] = {
	//{"ANV", "香辣鸡腿堡工作日午餐",  24}, //如果有需要，放开此项，注释掉下一行的“BMV”优惠，观察优惠菜单是否发生了变化
	{"BMV", "劲脆鸡腿堡超值套餐", 26},
	{ "ABCGGIIKKOUWWW", "超值全家桶", 115 },
	{ "KIIRRJUWW", "缤纷小吃桶",      65 },
	{ "JJ","劲爆鸡米花(2份小)",       12.5 },
	{ NULL, NULL, 0 }
};
void output_menu() {
	cout << "==============================================================" << endl;
	cout << "                          KFC秋季菜单                        " << endl;
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
	cout << "【优惠信息】:" << endl;
	cout << special[0].name << "=" << list[1].name << "+" << list[12].name << "+" << list[21].name << "=" << special[0].price << endl;
	cout << special[1].name << "=" << list[0].name << "+" << list[1].name << "+" << list[2].name << "+" << list[6].name << "*2+" << list[8].name << "*2+" << list[10].name << "*2+" << list[14].name << "+" << list[20].name << "+" << list[22].name << "*3=" << special[1].price << endl;
	cout << special[2].name << "=" << list[8].name << "*2+" << list[9].name << "+" << list[10].name << "+" << list[16].name << "*2+" << list[19].name << "+" << list[22].name << "*2=" << special[2].price << endl;
	cout << special[3].name << "=" << list[9].name << "*2=" << special[3].price << endl;
	cout << "【输入规则说明】:" << endl;
	cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
	cout << endl;
	cout << "请点单:";

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
					cout << "输入错误，按任意键继续" << endl;
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
		cout << "您的点餐=";
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
		cout << "共计:" << " " << money << "元" << endl;
		cout << "点单完成，按任意键继续" << endl;
		t = _getch();
		system("cls");
	}
}
