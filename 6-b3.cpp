//2151753 彭坤宇 计科
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main() 
{
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	char two[33];
	gets_s(two, 33);
	char* p = two;
	unsigned int number = 0, x = 0;
	int length = strlen(two);
	p = two + length - 1;
	for (; p >= two; p--, x++) {
		number = number + int(pow(2, x) * (int(*p) - 48));
	}
	cout << number << endl;
}