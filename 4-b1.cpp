//2151753 彭坤宇 计科
#include <iostream>
#include<iomanip>
using namespace std;
/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	double a, t;
	int b, c, d, e, f, g, h, i, j, k, l, m;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	cout << "大写结果是:" << endl;
	t = a / 10.0;
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
	l = int(((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 - k) * 10 + 0.001);
	m = int((((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 - k) * 10 - l) * 10 + 0.001);
	//分出数字的各个位数 

	daxie(b, 0);
	if (b != 0) {
		cout << "拾";
	}
	daxie(c, 0);
	if (b * b + c * c != 0) {
		cout << "亿";
	}
	daxie(d, b * b + c * c != 0 && d * d + e * e + f * f + g * g != 0);
	if (d != 0) {
		cout << "仟";
	}
	daxie(e, d != 0 && d * d + e * e + f * f + g * g != 0 && f * f + g * g != 0);
	if (e != 0) {
		cout << "佰";
	}
	daxie(f, e != 0 && d * d + e * e + f * f + g * g != 0 && g != 0);
	if (f != 0) {
		cout << "拾";
	}
	daxie(g, 0);
	if (d * d + e * e + f * f + g * g != 0) {
		cout << "万";
	}
	daxie(h, b * b + c * c + d * d + e * e + f * f + g * g != 0 && h * h + i * i + j * j + k * k != 0);
	if (h != 0) {
		cout << "仟";
	}
	daxie(i, h != 0 && h * h + i * i + j * j + k * k != 0 && j * j + k * k != 0);
	if (i != 0) {
		cout << "佰";
	}
	daxie(j, i != 0 && h * h + i * i + j * j + k * k != 0 && k != 0);
	if (j != 0) {
		cout << "拾";
	}
	int x;
	x = b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k == 0 && l * l + m * m == 0;
	daxie(k, x);
	if (b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k != 0 || x) {
		cout << "圆";
	}
	if (l * l + m * m == 0) {
		cout << "整";
	}
	daxie(l, m != 0 && b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k != 0);
	if (l != 0) {
		cout << "角";
	}
	if (l != 0 && m == 0) {
		cout << "整";
	}
	daxie(m, 0);
	if (m) {
		cout << "分";
	}
	cout << endl;
	return 0;
}