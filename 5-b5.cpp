//2151753 ������ �ƿ�
#include<iostream>
using namespace std;
int main() 
{
	int i, k = 1000, result[1001];
	int chengji;
	int number = 0;
	int sum = 0, x;
	cout << "������ɼ������1000��������-1����" << endl;
	for (i = 0; i < 1001; i += 1) {
		cin >> result[i];
		if (result[i] < 0) {
			k = i;
			break;
		}
	}
	if (k == 0) {
		cout << "����Ч����" << endl;
		return 0;
	}
	else {
		int flag = 1;
		cout << "���������Ϊ:" << endl;
		for (i = 0; i < k; i += 1) {
			cout << result[i] << " ";
			if ((i + 1) % 10 == 0) {
				if (i + 1 == k)
					flag = 0;
				cout << endl;
			}
		}
		if(flag)
		cout << endl;
		cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
		for (chengji = 100; chengji > -1; chengji--) {
			for (i = 0; i < k; i += 1) {
				if (result[i] == chengji) {
					number++;
				}
			}
			sum = sum + number;
			for (x = number; x > 0; x--) {
				cout << chengji << " " << sum - number + 1 << endl;
			}
			number = 0;
		}
		return 0;
	}
}