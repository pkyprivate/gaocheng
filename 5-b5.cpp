//2151753 彭坤宇 计科
#include<iostream>
using namespace std;
int main() 
{
	int i, k = 1000, result[1001];
	int chengji;
	int number = 0;
	int sum = 0, x;
	cout << "请输入成绩（最多1000个），以-1结束" << endl;
	for (i = 0; i < 1001; i += 1) {
		cin >> result[i];
		if (result[i] < 0) {
			k = i;
			break;
		}
	}
	if (k == 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
	else {
		int flag = 1;
		cout << "输入的数组为:" << endl;
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
		cout << "分数与名次的对应关系为:" << endl;
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