//2151753 º∆ø∆ ≈Ì¿§”Ó
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a, t;
	int b, c, d, e, f, g, h, i, j, k, l, m;
	cout << "«Î ‰»Î[0-100“⁄)÷Æº‰µƒ ˝◊÷:" << endl;
	cin >> a;
	cout << "¥Û–¥Ω·π˚ «:" << endl;
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
	
	switch (b) {
		case 0:
			break;
		case 1:
			cout << "“º";
			break;
		case 2:
			cout << "∑°";
			break;
		case 3:
			cout << "»˛";
			break;
		case 4:
			cout << "À¡";
			break;
		case 5:
			cout << "ŒÈ";
			break;
		case 6:
			cout << "¬Ω";
			break;
		case 7:
			cout << "∆‚";
			break;
		case 8:
			cout << "∞∆";
			break;
		case 9:
			cout << "æ¡";
			break;
		default:
			cout << "error";
			break;
	}
	if (b != 0) {
		cout << " ∞";
	}
	switch (c) {
		case 0:
			break;
		case 1:
			cout << "“º";
			break;
		case 2:
			cout << "∑°";
			break;
		case 3:
			cout << "»˛";
			break;
		case 4:
			cout << "À¡";
			break;
		case 5:
			cout << "ŒÈ";
			break;
		case 6:
			cout << "¬Ω";
			break;
		case 7:
			cout << "∆‚";
			break;
		case 8:
			cout << "∞∆";
			break;
		case 9:
			cout << "æ¡";
			break;
		default:
			cout << "error";
			break;
	}
	if (b * b + c * c != 0) {
		cout << "“⁄";
	}

	//∂‘«∞¡ΩŒªΩ¯–– ‰≥ˆ
	switch (d) {
		case 0:
			if (b * b + c * c != 0 &&  e * e + f * f + g * g != 0)
				cout << "¡„";
			break;
		case 1:
			cout << "“º";
			break;
		case 2:
			cout << "∑°";
			break;
		case 3:
			cout << "»˛";
			break;
		case 4:
			cout << "À¡";
			break;
		case 5:
			cout << "ŒÈ";
			break;
		case 6:
			cout << "¬Ω";
			break;
		case 7:
			cout << "∆‚";
			break;
		case 8:
			cout << "∞∆";
			break;
		case 9:
			cout << "æ¡";
			break;
		default:
			cout << "error";
			break;
	}
	if (d != 0) {
		cout << "«™";
	}

	switch (e) {
		case 0:
			if (d != 0 && f * f + g * g != 0)
				cout << "¡„";
			break;
		case 1:
			cout << "“º";
			break;
		case 2:
			cout << "∑°";
			break;
		case 3:
			cout << "»˛";
			break;
		case 4:
			cout << "À¡";
			break;
		case 5:
			cout << "ŒÈ";
			break;
		case 6:
			cout << "¬Ω";
			break;
		case 7:
			cout << "∆‚";
			break;
		case 8:
			cout << "∞∆";
			break;
		case 9:
			cout << "æ¡";
			break;
		default:
			cout << "error";
			break;
	}
	if (e != 0) {
		cout << "∞€";
	}

	switch (f) {
		case 0:
			if (e != 0 && d * d + e * e + f * f + g * g != 0 && g != 0)	
				cout << "¡„";
			break;
		case 1:
			cout << "“º";
			break;
		case 2:
			cout << "∑°";
			break;
		case 3:
			cout << "»˛";
			break;
		case 4:
			cout << "À¡";
			break;
		case 5:
			cout << "ŒÈ";
			break;
		case 6:
			cout << "¬Ω";
			break;
		case 7:
			cout << "∆‚";
			break;
		case 8:
			cout << "∞∆";
			break;
		case 9:
			cout << "æ¡";
			break;
		default:
			cout << "error";
			break;
	}
	if (f != 0) {
		cout << " ∞";
	}
	
	switch (g) {
		case 0:
			break;
		case 1:
			cout << "“º";
			break;
		case 2:
			cout << "∑°";
			break;
		case 3:
			cout << "»˛";
			break;
		case 4:
			cout << "À¡";
			break;
		case 5:
			cout << "ŒÈ";
			break;
		case 6:
			cout << "¬Ω";
			break;
		case 7:
			cout << "∆‚";
			break;
		case 8:
			cout << "∞∆";
			break;
		case 9:
			cout << "æ¡";
			break;
		default:
			cout << "error";
			break;
	}
	if (d * d + e * e + f * f + g * g != 0) {
		cout << "ÕÚ";
	}
	//∂‘÷–º‰ÀƒŒªΩ¯–– ‰≥ˆ

	switch (h) {
		case 0:
			if (b * b + c * c + d * d + e * e + f * f + g * g != 0 && h * h + i * i + j * j + k * k != 0)
				cout << "¡„";
			break;
		case 1:
			cout << "“º";
			break;
		case 2:
			cout << "∑°";
			break;
		case 3:
			cout << "»˛";
			break;
		case 4:
			cout << "À¡";
			break;
		case 5:
			cout << "ŒÈ";
			break;
		case 6:
			cout << "¬Ω";
			break;
		case 7:
			cout << "∆‚";
			break;
		case 8:
			cout << "∞∆";
			break;
		case 9:
			cout << "æ¡";
			break;
		default:
			cout << "error";
			break;
	}
	if (h != 0) {
		cout << "«™";
	}

	switch (i) {
		case 0:
			if (h != 0 && h * h + i * i + j * j + k * k != 0 && j * j + k * k != 0)	
				cout << "¡„";
			break;
		case 1:
			cout << "“º";
			break;
		case 2:
			cout << "∑°";
			break;
		case 3:
			cout << "»˛";
			break;
		case 4:
			cout << "À¡";
			break;
		case 5:
			cout << "ŒÈ";
			break;
		case 6:
			cout << "¬Ω";
			break;
		case 7:
			cout << "∆‚";
			break;
		case 8:
			cout << "∞∆";
			break;
		case 9:
			cout << "æ¡";
			break;
		default:
			cout << "error";
			break;
	}
	if (i != 0) {
		cout << "∞€";
	}

	switch (j) {
		case 0:
			if (i != 0 && h * h + i * i + j * j + k * k != 0 && k != 0)	
				cout << "¡„";
			break;
		case 1:
			cout << "“º";
			break;
		case 2:
			cout << "∑°";
			break;
		case 3:
			cout << "»˛";
			break;
		case 4:
			cout << "À¡";
			break;
		case 5:
			cout << "ŒÈ";
			break;
		case 6:
			cout << "¬Ω";
			break;
		case 7:
			cout << "∆‚";
			break;
		case 8:
			cout << "∞∆";
			break;
		case 9:
			cout << "æ¡";
			break;
		default:
			cout << "error";
			break;
	}
	if (j != 0) {
		cout << " ∞";
	}
	int x;
	x = b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k == 0 && l * l + m * m == 0;
	switch (k) {
		case 0:
			if (x)	
				cout << "¡„";
			break;
		case 1:
			cout << "“º";
			break;
		case 2:
			cout << "∑°";
			break;
		case 3:
			cout << "»˛";
			break;
		case 4:
			cout << "À¡";
			break;
		case 5:
			cout << "ŒÈ";
			break;
		case 6:
			cout << "¬Ω";
			break;
		case 7:
			cout << "∆‚";
			break;
		case 8:
			cout << "∞∆";
			break;
		case 9:
			cout << "æ¡";
			break;
		default:
			cout << "error";
			break;
	}
	if (b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k != 0 || x) {
		cout << "‘≤";
	}
	if (l * l + m * m == 0) {
		cout << "’˚";
	}
	//∂‘∫ÛÀƒŒªΩ¯–– ‰≥ˆ
	switch (l) {
		case 0:
			if (m != 0 && b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k != 0)	
				cout << "¡„";
			break;
		case 1:
			cout << "“º";
			break;
		case 2:
			cout << "∑°";
			break;
		case 3:
			cout << "»˛";
			break;
		case 4:
			cout << "À¡";
			break;
		case 5:
			cout << "ŒÈ";
			break;
		case 6:
			cout << "¬Ω";
			break;
		case 7:
			cout << "∆‚";
			break;
		case 8:
			cout << "∞∆";
			break;
		case 9:
			cout << "æ¡";
			break;
		default:
			cout << "error";
			break;
	}
	if (l != 0) {
		cout << "Ω«";
	}

	if (l != 0 && m == 0) {
		cout << "’˚";
	}

	switch (m) {
		case 0:
			break;
		case 1:
			cout << "“º";
			break;
		case 2:
			cout << "∑°";
			break;
		case 3:
			cout << "»˛";
			break;
		case 4:
			cout << "À¡";
			break;
		case 5:
			cout << "ŒÈ";
			break;
		case 6:
			cout << "¬Ω";
			break;
		case 7:
			cout << "∆‚";
			break;
		case 8:
			cout << "∞∆";
			break;
		case 9:
			cout << "æ¡";
			break;
		default:
			cout << "error";
			break;
	}
	if (m) {
		cout << "∑÷";
	}
	//◊Ó∫Û¡ΩŒª ‰≥ˆ
	cout << endl;
	return 0;
}