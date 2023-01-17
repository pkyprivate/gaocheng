//2151753 ≈Ì¿§”Ó º∆ø∆
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main() 
{
	char s[12][28];
	int max = 50;

	srand((unsigned)time(NULL));
	for (int i = 0; i < max; i++) {
		int x = (rand() % 260) + 1;
		int n = x % 26;
		if (n == 0)
			n = 26;
		int m = (x - n) / 26 + 1;
		if (s[m][n] == '*') {
			while (1) {
				int x = (rand() % 260) + 1;
				int n = x % 26;
				if (n == 0)
					n = 26;
				int m = (x - n) / 26 + 1;
				if (s[m][n] != '*') {
					s[m][n] = '*';
					break;
				}
			}
		}
		else {
			s[m][n] = '*';
		}
	}
	for (int i = 0; i < 28; i++) {
		s[0][i] = '0';
		s[11][i] = '0';
	}
	for (int i = 0; i < 12; i++) {
		s[i][0] = '0';
		s[i][27] = '0';
	}

	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 27; j++) {
			if (s[i][j] != '*') {
				int x = 0;
				if (s[i - 1][j - 1] == '*')
					x++;
				if (s[i - 1][j] == '*')
					x++;
				if (s[i - 1][j + 1] == '*')
					x++;
				if (s[i][j - 1] == '*')
					x++;
				if (s[i][j + 1] == '*')
					x++;
				if (s[i + 1][j - 1] == '*')
					x++;
				if (s[i + 1][j] == '*')
					x++;
				if (s[i + 1][j + 1] == '*')
					x++;
				s[i][j] = char(x + 48);
			}
		}
	}

	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 27; j++) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}




	return 0;

}

