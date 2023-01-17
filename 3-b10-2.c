//2151753 计科 彭坤宇
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	int x1, x2, x3, a1, b1, c1, a2, b2, c2, a3, b3, c3, number = 1;
	for (a1 = 1; a1 < 10; a1++) {
		for (a2 = 1; a2 < 10; a2++) {
			if (a2 != a1) {
				for (a3 = 1; a3 < 10; a3++) {
					if (a3 != a1 && a3 != a2) {
						for (b1 = 1; b1 < 10; b1++) {
							if (b1 != a1 && b1 != a2 && b1 != a3) {
								for (b2 = 1; b2 < 10; b2++) {
									if (b2 != a1 && b2 != a2 && b2 != a3 && b2 != b1) {
										for (b3 = 1; b3 < 10; b3++) {
											if (b3 != a1 && b3 != a2 && b3 != a3 && b3 != b1 && b3 != b2) {
												for (c1 = 1; c1 < 10; c1++) {
													if (c1 != a1 && c1 != a2 && c1 != a3 && c1 != b1 && c1 != b2 && c1 != b3) {
														for (c2 = 1; c2 < 10; c2++) {
															if (c2 != a1 && c2 != a2 && c2 != a3 && c2 != b1 && c2 != b2 && c2 != b3 && c2 != c1) {
																for (c3 = 1; c3 < 10; c3++) {
																	if (c3 != a1 && c3 != a2 && c3 != a3 && c3 != b1 && c3 != b2 && c3 != b3 && c3 != c1 && c3 != c2) {
																		x1 = a1 * 100 + a2 * 10 + a3;
																		x2 = b1 * 100 + b2 * 10 + b3;
																		x3 = c1 * 100 + c2 * 10 + c3;
																		if (x1 + x2 + x3 == 1953) {
																			if (x1 < x2 && x2 < x3) {
																				printf("No.");
																				printf( "%3d",number);
																				printf(" : ");
																				printf("%d+%d+%d=1953\n", x1, x2, x3);
																				number++;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("total=%d", number-1);
	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}