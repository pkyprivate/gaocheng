//2151753 彭坤宇 计科
#include<iostream>
#include <iomanip>
using namespace std;
int zeller(int y, int m);
void printa(int m, int n, int d[13], int rizi[32], int y);
void printb(int x);
int Min(int a, int b);
int Max(int a, int b);
int main()
{
	system("mode con cols=120 lines=45");
	int year, d[13] = { 0 };
	int rizi[32] = { 0 };
	cout << "请输入年份[1900-2100]" << endl;
	cin >> year;
	while (1)
	{
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "输入错误，请重新输入" << endl;
			cout << "请输入年份[1900-2100]" << endl;
			cin >> year;
		}
		if (year < 1900 || year>2100) {
			cout << "请输入年份[1900-2100]" << endl;
			cin >> year;
		}
		else
			break;
	}
	cout << year << "年的日历:" << endl;
	cout << endl;
	for (int i = 1; i <= 12; i++) {
		d[i] = zeller(year, i);
	}
	for (int i = 1; i <= 31; i++) {
		rizi[i] = i;
	}
	for (int k = 1; k < 12; k += 3) {
		printb(k);
		for (int i = k; i < k + 3; i++) {
			if (d[i] != 0) {
				cout << setw(4 * d[i]) << " ";
			}
			for (int j = 1; j <= (7 - d[i]); j++) {
				cout << std::left << setw(4) << rizi[j];
			}
			if(i!=3&&i!=6&&i!=9&&i!=12)
			cout << setw(5) << " ";
		}
		cout << endl;
	    printa(k, 8, d, rizi, year);
		printa(k, 15, d, rizi, year);
		printa(k, 22, d, rizi, year);
		printa(k, 29, d, rizi, year);
		printa(k, 36, d, rizi, year);
		cout << endl;
	}
	cout << endl;
	return 0;
}

int zeller(int y, int m) {
	int w, c, e, f, g;
	if (m == 1) {
		m = 13;
		y -= 1;
	}
	if (m == 2) {
		m = 14;
		y -= 1;
	}
	c = y / 100;
	e = y - 100 * c; 100;
	f = 13 * (m + 1);
	w = e + e / 4 + c / 4 - 2 * c + f / 5;
	while (w < 0) {
		w += 7;
	}
	g = w % 7;
	return g;
}

void printa(int m, int n, int d[13], int rizi[32], int y) {
	int min[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 }, max[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	bool check=0 ;
	for (int i = m; i < m + 3; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			min[i] = Min(31, n + 6 - d[i]);
			max[i] = Max(31, n + 6 - d[i]);
		}
		if (i == 2) {
			if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
				min[i] = Min(29, n + 6 - d[i]);
				max[i] = Max(29, n + 6 - d[i]);
			}
			else {
				min[i] = Min(28, n + 6 - d[i]);
				max[i] = Max(28, n + 6 - d[i]);
			}
		}
		if (i == 4 || i == 6 || i == 9 || i == 11) {
			min[i] = Min(30, n + 6 - d[i]);
			max[i] = Max(30, n + 6 - d[i]);
		}
	}
	for (int i = m; i < m + 3; i++) {
		if (n - d[i] > min[i])
			check = 1;
		else {
			check = 0;
			break;
		}
	}
	if (check == 0) {
		for (int i = m; i < m + 3; i++) {
			for (int j = n - d[i]; j <= min[i]; j++) {
				cout << std::left << setw(4) << rizi[j];
			}
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
				if (max[i] == n + 6 - d[i]) {
					int t;
					t = Min(28, 4 * (n + 6 - d[i] - 31));
					if (t != 0)
						cout << setw(t) << " ";
				}
				if(i!=12&&i!=3)
				cout << setw(5) << " ";
			}
			if (i == 2) {
				if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
					if (max[i] == n + 6 - d[i]) {
						int t;
						t = Min(28, 4 * (n + 6 - d[i] - 29));
						if (t != 0)
							cout << setw(t) << " ";
					}
				}
				else {
					if (max[i] == n + 6 - d[i]) {
						int t;
						t = Min(28, 4 * (n + 6 - d[i] - 28));
						if (t != 0)
							cout << setw(t) << " ";
					}
				}
				cout << setw(5) << " ";
			}
			if (i == 4 || i == 6 || i == 9 || i == 11) {
				if (max[i] == n + 6 - d[i]) {
					int t;
					t = Min(28, 4 * (n + 6 - d[i] - 30));
					if (t != 0)
						cout << setw(t) << " ";
				}
				if(i!=6&&i!=9)
				cout << setw(5) << " ";
			}
		}
	}
	if(check==0)
	cout << endl;
}

void printb(int x) {
	if (x < 9) {
		cout << setw(12) << " " << x << "月" << setw(29) << " " << x + 1 << "月" << setw(29) << " " << x + 2 << "月" << endl;
	}
	if (x > 9) {
		cout << setw(11) << " " << x << "月" << setw(28) << " " << x + 1 << "月" << setw(28) << " " << x + 2 << "月" << endl;
	}
	cout << "Sun Mon Tue Wed Thu Fri Sat" << setw(5) << " " << "Sun Mon Tue Wed Thu Fri Sat" << setw(5) << " " << "Sun Mon Tue Wed Thu Fri Sat " << endl;

}


int Min(int a, int b) {
	return a > b ? b : a;
}

int Max(int a, int b) {
	return a < b ? b : a;
}