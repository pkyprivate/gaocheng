//2151753 彭坤宇 计科
#include<iostream>
#include<stdio.h>
using namespace std;
int judge(char* p) {
	char* pa;
	pa = p;
	int a = 0, x = 1;
	int length = strlen(p) - 1;
	if (length > 1) {
		for (; p - pa < length / 2; p++, a++) {
			if (*p != *(pa + length - 1 - a)) {
				x = 0;
				break;
			}
		}
	}
	return x;
}

int main() 
{
	char huiwen[81];
	int x;
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(huiwen, 81, stdin);
	x = judge(huiwen);
	if (x)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}