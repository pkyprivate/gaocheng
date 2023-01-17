#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
static const char other[] = "~!@#$%^&*()-_=+[],.?";
void random_number(int sum, int number[]) {
	int others = sum - number[1] - number[2] - number[3] - number[4];
	int t;
	for (int i = 1; i <= others; i++) {
		t = rand() % 4 + 1;
		number[t]++;
	}
}

void random_out(int number[], char daxie[], char xiaoxie[], char shuzi[], char others[], const char other[]) {

	for (int i = 0; i < number[1]; i++) {
		daxie[i] = char(rand() % 26 + 65);
	}
	for (int i = 0; i < number[2]; i++) {
		xiaoxie[i] = char(rand() % 26 + 97);
	}
	for (int i = 0; i < number[3]; i++) {
		shuzi[i] = char(rand() % 10 + 48);
	}
	for (int i = 0; i < number[4]; i++) {
		while (1) {
			int x = 1;
			others[i] = char(rand() % 128);
			for (int j = 0; j < 20; j++) {
				if (others[i] == other[j]) {
					x = 0;
					break;
				}
			}
			if (x == 0)
				break;
		}
	}
}

int tj_strcat(char s1[], const char s2[])
{
	int length1 = strlen(s1);
	int length2 = strlen(s2);
	for (int i = length1; i < length1 + length2 + 1; i++) {
		s1[i] = s2[i - length1];
	}
	return 0;
}

int tj_strcpy(char s1[], const char s2[])
{
	int length1 = strlen(s1);
	int length2 = strlen(s2);

	for (int i = 0; i < length2; i++) {
		s1[i] = s2[i];
	}
	s1[length2] = '\0';
	return 0;
}

void printout(int sum, int number[], char daxie[], char xiaoxie[], char shuzi[], char others[]) {
	random_number(sum, number);
	random_out(number, daxie, xiaoxie, shuzi, others, other);
	char all[100];
	tj_strcpy(all, daxie);
	tj_strcat(all, xiaoxie);
	tj_strcat(all, shuzi);
	tj_strcat(all, others);
	for (int i = 0; i < sum; i++) {
		char x;
		x = all[i];
		all[i] = all[rand() % sum];
		all[rand() % sum] = x;
	}
	cout << all << endl;
}

int main() {
	srand((unsigned)time(NULL));
	int sum, a, b, c, d;
	char daxie[16] = { '\0' }, xiaoxie[16] = { '\0' }, shuzi[16] = { '\0' }, others[16] = { '\0' };
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> sum >> a >> b >> c >> d;
	int number[5] = { 0,a,b,c,d };
	if (cin.fail()) {
		cout << "输入非法" << endl;
		return 0;
	}
	if (sum > 16 || sum < 12) {
		cout << "密码长度[" << sum << "]不正确" << endl;
		return 0;
	}
	if (a < 2) {
		cout << "大写字母个数[" << a << "]不正确" << endl;
		return 0;
	}
	if (b < 2) {
		cout << "小写字母个数[" << b << "]不正确" << endl;
		return 0;
	}
	if (c < 2) {
		cout << "数字个数[" << c << "]不正确" << endl;
		return 0;
	}
	if (d < 2) {
		cout << "其他符号个数[" << d << "]不正确" << endl;
		return 0;
	}
	if (a + b + c + d > sum) {
		cout << "所有字符类型之和[" << a << "+" << b << "+" << c << "+" << d << "]大于总密码长度[" << sum << "]" << endl;
		return 0;
	}
	srand((unsigned)time(NULL));
	for (int i = 1; i <= 10; i++) {
		printout(sum, number, daxie, xiaoxie, shuzi, others);
	}
	return 0;
}