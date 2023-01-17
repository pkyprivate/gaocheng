#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

void putin(int i, char xuehao[10][8], char name[10][9], int result[10])
{
	printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);

	scanf("%s", xuehao[i]);
	scanf("%s", name[i]);
	scanf("%d", &result[i]);
}


void judge(char xuehao[10][8], char name[10][9], int result[10]) {
	char replace1[8], replace2[9];
	int  replace3;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10-i; j++) {
			if (result[j+1]>result[j]) {
				strcpy(replace1, xuehao[j+1]);
				strcpy(xuehao[j+1], xuehao[j]);
				strcpy(xuehao[j], replace1);
				strcpy(replace2, name[j+1]);
				strcpy(name[j+1], name[j]);
				strcpy(name[j], replace2);
				replace3 = result[j+1];
				result[j+1] = result[j];
				result[j] = replace3;
			}
		}
	}
}

int main() {
	char xuehao[10][8];
	char name[10][9];
	int result[10];
	for (int i = 0; i < 10; i++) {
		putin(i, xuehao, name, result);
	}
	printf("\n");
	judge(xuehao, name, result);
	printf("全部学生(成绩降序):\n");
	for (int i = 0; i < 10; i++) {
			printf("%s %s %d\n", name[i], xuehao[i], result[i]);
	}
	return 0;
}