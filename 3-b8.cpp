//2151753 计科 彭坤宇
#include<iostream>
#include <iomanip> 
#include<cmath> 
using namespace std;
int main() 
{
	cout << "请输入x的值[-10 ~ +65]" << endl;
	int x;
	while (1) {
		cin >> x;
		if (x < -10 || x>65)
			cout << "输入非法，请重新输入" << endl;
		else
			break;
	}
	double sum=1,t=x;
	for (int i = 1;; i++) {
		if(fabs(t) < 1e-6)
			break;
		sum = sum + t;
		t = t * x / (i + 1);
	}
	cout << "e^" <<setprecision(10)<<x << "=" << sum << endl;
}
