//2151753 ������ �ƿ�
#include<iostream>
#include<cstdio>
using namespace std;
int main() 
{
	int x, number=20;
	bool check=1;
	cout << "��������������������������20��������-1����" << endl;
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
		cout << "����Ч����" << endl;
		return 0;
	}
	cout << "ԭ����Ϊ��" << endl;
	for (int i = 0; i < number; i++) {
		cout <<input[i]<< " ";
	}
	cout << endl;
	cout << "������Ҫ�����������"<<endl;
	cin >> x;
	cout << "����������Ϊ��" << endl;
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