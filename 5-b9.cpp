//2151753 ������ �ƿ�
#include<iostream>
#include<cmath>
using namespace std;

int main() 
{
	int a[10][10];
	int judge = 1;
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			while (1) {
				cin >> a[i][j];
				if (cin.good() == 0) {
					cin.clear();
					cin.ignore(65536, '\n');
					cout << "�����������" << i << "�е�" << j << "��(���о���1��ʼ����)��ֵ\n";
					continue;
				}
				else if (a[i][j] < 1 || a[i][j]>9) {
					cout << "�����������" << i << "�е�" << j << "��(���о���1��ʼ����)��ֵ\n";
				}
				else
					break;
			}
		}
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 9; k > j; k--) {
				if (a[i][j] == a[i][k]) {
					judge = 0;
				}
			}
		}
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 9; k > j; k--) {
				if (a[j][i] == a[k][i]) {
					judge = 0;
				}
			}
		}
	}
	for (int i = 3; i < 10; i += 3) {
		for (int j = i - 2; j < i + 1; j++) {
			for (int k = 3; k < 10; k += 3) {
				for (int l = k - 2; l < k + 1; l++) {
					for (int m = i - 2; m < i + 1; m++) {
						for (int n = k - 2; n < k + 1; n++) {
							int t = m != i || n != j;
							if (a[m][n] == a[i][j] && t) {
								judge = 0;
							}
						}
					}
				}
			}
		}
	}
	if (judge == 0) {
		cout << "��";
	}
	cout << "�������Ľ�" << endl;
	return 0;
}
