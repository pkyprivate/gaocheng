#include<iostream>
#include<cstring>

using namespace std;

void putin(int i, string xuehao[10], string name[10], int result[10])
{
	cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
	cin >> xuehao[i];
	cin >> name[i];
	cin >> result[i];
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

void judge(string xuehao[10], string name[10], int result[10]) {
	string replace1, replace2;
	int  replace3;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9-i; j++) {
			if (result[j+1]>result[j] ) {
				replace1=xuehao[j+1];
				xuehao[j+1]= xuehao[j];
				xuehao[j]= replace1;
				replace2= name[j+1];
				name[j+1]= name[j];
				name[j]=replace2;
				replace3 = result[j+1];
				result[j+1] = result[j];
				result[j] = replace3;
			}
		}
	}
}

int main() {
	string xuehao[10];
	string name[10];
	int result[10];
	for (int i = 0; i < 10; i++) {
		putin(i, xuehao, name, result);
	}
	cout << endl;
	judge(xuehao, name, result);
	cout << "����������(�ɼ�����):" << endl;
	for (int i = 0; i < 10; i++) {
		if (result[i] < 60) {
			cout << name[i];
			cout << " ";
			cout << xuehao[i];
			cout << " ";
			cout << result[i] << endl;
		}
	}
	return 0;
}