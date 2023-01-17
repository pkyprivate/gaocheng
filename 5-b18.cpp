#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int big = 0, small = 0, number = 0, others = 0;
	int big0, small0, number0, others0,all0;
	char str[11][128];
	cin.ignore(65536,'\n');
	cin >> all0 >> big0 >> small0 >> number0 >> others0;
	for (int i = 0; i < 11; i++) {
		cin.getline(str[i], 128);
	}
	bool check = 0;
	for (int i = 1; i < 11; i++) {
		for (int j = 0; str[i][j] != '\0'; j++) {
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				big++;
			if (str[i][j] >= 'a' && str[i][j] <= 'z')
				small++;
			if (str[i][j] >= '0' && str[i][j] <= '9')
				number++;
		}
			others = strlen(str[i]) - big - small - number;
			if (all0 != strlen(str[i]))
				check = 1;
			if (big < big0)
				check = 1;
			if (small < small0)
				check = 1;
			if (number < number0)
				check = 1;
			if (others < others0)
				check = 1;
			big = 0;
			small = 0;
			number = 0;
			others = 0;
	}
	
	if (check)
		cout << "´íÎó" << endl;
	else
		cout << "ÕýÈ·" << endl;
	return 0;
}