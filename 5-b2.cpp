//2151753 ≈Ì¿§”Ó º∆ø∆
#include<iostream>
using namespace std;
int main() 
{
	int a[101];
	int i, j;
	for (i = 0; i < 101; i++) {
		a[i] = 0;
	}
	for (j = 1; j < 101; j++) {
		for (i = 1; i < 101; i++) {
			if (i % j == 0) {
				if (a[i] == 0)a[i] = 1;
				else a[i] = 0;
			}
		}
	}
	for (i = 0; i < 101; i++) {
		if (a[i] == 1) {
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}