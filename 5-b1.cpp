//2151753 彭坤宇 计科
#include<iostream>
#include<cstdio>
using namespace std;
int main() 
{
	int x, number=20;
	bool check=1;
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
	int input[21];
	for (int i = 0; i < 20; i++) {
		cin >> input[i];
		if (input[i] == -1) {
			number = i;
			cin.ignore(65536, '\n');
			break;
		}
	}
	if (input[0] == -1) {
		cout << "无有效输入" << endl;
		return 0;
	}
	cout << "原数组为：" << endl;
	for (int i = 0; i < number; i++) {
		cout <<input[i]<< " ";
	}
	cout << endl;
	cout << "请输入要插入的正整数"<<endl;
	cin >> x;
	cout << "插入后的数组为：" << endl;
	for (int i = 0; i < number; i++) {
		if (x < input[i] || x == input[i]) {
			for (int j = number; j >i; j--) {
				input[j] = input[j - 1];
			}
			input[i] = x;
			check = 0;
			break;
		 }
	}
	if (check)
		input[number] = x;
	for (int i = 0; i < number + 1; i++) {
		cout << input[i] << " ";
	}
	cout << endl;
	return 0;
}