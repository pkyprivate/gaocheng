//2151753 ������ �ƿ�
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main() 
{
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
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