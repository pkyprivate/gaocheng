//2151753 ������ �ƿ�
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int big = 0, small = 0, number = 0, blank = 0,others=0;
	char str[3][128];
	for (int i = 0; i < 3; i++) {
		cout << "�������" << i+1 << "��" << endl;
		cin.getline(str[i], 128);
		others += strlen(str[i]);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; str[i][j] != '\0'; j++) {
			if (str[i][j] == ' ')
				blank++;
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				big++;
			if (str[i][j] >= 'a' && str[i][j] <= 'z')
				small++;
			if (str[i][j] >= '0' && str[i][j] <= '9')
				number++;
		}
	}
	others = others - big - small - number - blank;
	cout << "��д :" << big << endl;
	cout << "Сд :" << small << endl;
	cout << "���� :" << number << endl;
	cout << "�ո� :" << blank << endl;
	cout << "���� :" << others << endl;
	return 0;
}