//2151753 彭坤宇 计科
/*2152871 王灏瑾 2151338 李秉嵘 2151974 赵明泽 2151601 邹昕凯 2152988 杨恺铭 2051961王煜程*/
#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
int main()
{
	char trash;
	char s[12][28];
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 27; j++) {
			scanf("%c", &s[i][j]);
			scanf("%c", &trash);
		}
		scanf("%c", &trash);
	}
	for (int i = 0; i < 28; i++) {
		s[0][i] = '0';
		s[11][i] = '0';
	}
	for (int i = 0; i < 12; i++) {
		s[i][0] = '0';
		s[i][27] = '0';
	}

	int sum = 0;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 27; j++) {
			if (s[i][j] == '*')
				sum++;
		}
	}
	if (sum != 50) {
		printf("错误1\n");
		return 0;
	}
	int check = 0;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 27; j++) {
			int x = 0;
			if (s[i][j] == '*')
				continue;
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
			if (x != s[i][j]-'0') {
				check = 1;
				break;
			}
		}
	}
	
	if (check)
		printf("错误2\n");
	else
		printf("正确\n");
	return 0;
}
