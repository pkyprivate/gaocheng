//2151753 彭坤宇 计科
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() 
{
	int i, k = 1000, result[1001];
	int chengji;
	int number = 0;
	printf("请输入成绩（最多1000个），以-1结束\n");
	for (i = 0; i < 1001; i += 1) {
		scanf("%d", &result[i]);
		if (result[i] < 0) {
			k = i;
			break;
		}
	}
	if (k == 0) {
		printf("无有效输入\n");
		return 0;
	}
	else {
		int flag = 1;
		printf("输入的数组为:\n");
		for (i = 0; i < k; i += 1) {
			printf("%d ", result[i]);
			if ((i + 1) % 10 == 0) {
				if (i == k - 1)
					flag = 0;
				printf("\n");
			}
		}
		if (flag)
			printf("\n");
		printf("分数与人数的对应关系为:\n");
		for (chengji = 100; chengji > -1; chengji--) {
			for (i = 0; i < k; i++) {
				if (result[i] == chengji) {
					number++;
				}
			}
			if (number != 0) {
				printf("%d %d\n", chengji, number);
				number = 0;
			}
		}
		return 0;
	}
}