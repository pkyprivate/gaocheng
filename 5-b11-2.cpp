//2151753 ������ �ƿ�
#include <iostream>
#include<iomanip>
#include<cstring>
using namespace std;
const char chnstr[] = "��Ҽ��������½��ƾ�";
string result;
int main()
{
	const char s[] = "ʰ��Ǫ����Բ�Ƿ���";
	double a, t;
	int b, c, d, e, f, g, h, i, j, k, l, m;

	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	cout << "��д�����:" << endl;
	{t = a / 10.0;
	b = int(t) / 100000000;
	c = (int(t) - 100000000 * b) / 10000000;
	d = (int(t) - 100000000 * b - 10000000 * c) / 1000000;
	e = (int(t) - 100000000 * b - 10000000 * c - 1000000 * d) / 100000;
	f = (int(t) - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e) / 10000;
	g = (int(t) - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f) / 1000;
	h = (int(t) - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g) / 100;
	i = (int(t) - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h) / 10;
	j = (int(t) - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i);
	k = int((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 + 0.001);
	l =int(((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 - k) * 10 + 0.001);
	m = int((((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 - k) * 10 - l) * 10 + 0.001);
	//�ֳ����ֵĸ���λ�� 
	}
	if (b != 0) {
		result = result + chnstr[2 * b] + chnstr[2 * b + 1] + s[0] + s[1];
	}
	if (c != 0) {
		result = result + chnstr[2 * c] + chnstr[2 * c + 1];
	}
	if (b * b + c * c != 0) {
		result = result + s[8] + s[9];
	}
	if (d == 0) {
		if (b * b + c * c != 0 && d * d + e * e + f * f + g * g != 0) {
			result = result + chnstr[0] + chnstr[1];
		}
	}
	else {
		result = result + chnstr[2 * d] + chnstr[2 * d + 1];
	}
	if (d != 0) {
		result = result + s[4] + s[5];
	}
	if (e == 0) {
		if (d != 0 && d * d + e * e + f * f + g * g != 0 && f * f + g * g != 0) {
			result = result + chnstr[0] + chnstr[1];
		}
	}
	else {
		result = result + chnstr[2 * e] + chnstr[2 * e + 1];
	}
	if (e != 0) {
		result = result + s[2] + s[3];
	}
	if (f == 0) {
		if (e != 0 && d * d + e * e + f * f + g * g != 0 && g != 0) {
			result = result + chnstr[0] + chnstr[1];
		}
	}
	else {
		result = result + chnstr[2 * f] + chnstr[2 * f + 1];
	}
	if (f != 0) {
		result = result + s[0] + s[1];
	}
	if (g != 0) {
		result = result + chnstr[2 * g] + chnstr[2 * g + 1];
	}
	if (d * d + e * e + f * f + g * g != 0) {
		result = result + s[6] + s[7];
	}
	if (h == 0) {
		if (b * b + c * c + d * d + e * e + f * f + g * g != 0 && h * h + i * i + j * j + k * k != 0) {
			result = result + chnstr[0] + chnstr[1];
		}
	}
	else { result = result + chnstr[2 * h] + chnstr[2 * h + 1]; }
	if (h != 0) {
		result = result + s[4] + s[5];
	}
	if (i == 0) {
		if (h != 0 && h * h + i * i + j * j + k * k != 0 && j * j + k * k != 0) {
			result = result + chnstr[0] + chnstr[1];
		}
	}
	else {
		result = result + chnstr[2 * i] + chnstr[2 * i + 1];
	}
	if (i != 0) {
		result = result + s[2] + s[3];
	}
	if (j == 0) {
		if (i != 0 && h * h + i * i + j * j + k * k != 0 && k != 0) {
			result = result + chnstr[2 * j] + chnstr[2 * j + 1];
		}
	}
	else {
		result = result + chnstr[2 * j] + chnstr[2 * j + 1];
	}
	if (j != 0) {
		result = result + s[0] + s[1];
	}
	int x;
	x = b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k == 0 && l * l + m * m == 0;
	if (k == 0) {
		if (x == 1) {
			result = result + chnstr[2 * k] + chnstr[2 * k + 1];
		}
	}
	else {
		result = result + chnstr[2 * k] + chnstr[2 * k + 1];
		if (x == 1) {
			result = result + chnstr[0] + chnstr[1];
		}
	}
	if (b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k != 0 || x == 1) {
		result = result + s[10] + s[11];//Բ
	}
	if (l * l + m * m == 0) {
		result = result + s[16] + s[17];
	}
	if (l == 0) {
		if (m != 0 && b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k != 0) {
			result = result + chnstr[2 * l] + chnstr[2 * l + 1];
		}
	}
	else {
		result = result + chnstr[2 * l] + chnstr[2 * l + 1];
	}
	if (l != 0) {
		result = result + s[12] + s[13];
	}
	if (l != 0 && m == 0) {
		result = result + s[16] + s[17];
	}
	if (m != 0) {
		result = result + chnstr[2 * m] + chnstr[2 * m + 1] + s[14] + s[15];
	}
	cout << result << endl;
	return 0;
}