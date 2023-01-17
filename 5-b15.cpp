//2151753 彭坤宇 计科
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int big = 0, small = 0, number = 0, blank = 0,others=0;
	char str[3][128];
	for (int i = 0; i < 3; i++) {
		cout << "请输入第" << i+1 << "行" << endl;
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
	cout << "大写 :" << big << endl;
	cout << "小写 :" << small << endl;
	cout << "数字 :" << number << endl;
	cout << "空格 :" << blank << endl;
	cout << "其他 :" << others << endl;
	return 0;
}