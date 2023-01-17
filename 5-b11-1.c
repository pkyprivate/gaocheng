//2151753 彭坤宇 计科
/* 班级 学号 姓名 */
#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	int num = 0;
	const char s[] = "拾佰仟万亿圆角分整";
	double a, t;
	int b, c, d, e, f, g, h, i, j, k, l, m;
	printf("请输入[0-100亿)之间的数字:\n");
	scanf("%lf", &a);
	printf("大写结果是:\n");
	t = a / 10;
	b = (int)(t) / 100000000;
	c = (int)((t)-100000000 * b) / 10000000;
	d = (int)((t)-100000000 * b - 10000000 * c) / 1000000;
	e = (int)((t)-100000000 * b - 10000000 * c - 1000000 * d) / 100000;
	f = (int)((t)-100000000 * b - 10000000 * c - 1000000 * d - 100000 * e) / 10000;
	g = (int)((t)-100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f) / 1000;
	h = (int)((t)-100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g) / 100;
	i = (int)((t)-100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h) / 10;
	j = (int)((t)-100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i);
	k = (int)((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 + 0.001);
	l = (int)(((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 - k) * 10 + 0.001);
	m = (int)((((t - 100000000 * b - 10000000 * c - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i - j) * 10 - k) * 10 - l) * 10 + 0.001);
	//分出数字的各个位数 
	if (b != 0) {
		result[num++]=chnstr[2 * b];
		result[num++] = chnstr[2 * b + 1];
		result[num++] = s[0];
		result[num++] = s[1];
	}
	if (c != 0) {
		result[num++] =chnstr[2 * c] ;
		result[num++] = chnstr[2 * c + 1];
	}
	if (b * b + c * c != 0) {
		result[num++] = s[8];
		result[num++] = s[9];
	}
	if (d == 0) {
		if (b * b + c * c != 0 && d * d + e * e + f * f + g * g != 0) {
			result[num++] = chnstr[0];
			result[num++] = chnstr[1];
		}
	}
	else {
		result[num++] =chnstr[2 * d] ;
		result[num++] = chnstr[2 * d + 1];
	}
	if (d != 0) {
		result[num++] =s[4];
		result[num++] = s[5];
	}
	if (e == 0) {
		if (d != 0 && d * d + e * e + f * f + g * g != 0 && f * f + g * g != 0) {
			result[num++] =chnstr[0] ;
			result[num++] = chnstr[1];
		}
	}
	else {
		result[num++] = chnstr[2 * e];
		result[num++]=chnstr[2 * e + 1];
	}
	if (e != 0) {
		result[num++] = s[2];
		result[num++] = s[3];
	}
	if (f == 0) {
		if (e != 0 && d * d + e * e + f * f + g * g != 0 && g != 0) {
			result[num++] = chnstr[0];
			result[num++] = chnstr[1];
		}
	}
	else {
		result[num++] = chnstr[2 * f];
		result[num++] = chnstr[2 * f + 1];
	}
		if (f != 0) {
			result[num++] = s[0];
			result[num++] = s[1];
		}
		if (g != 0) {
			result[num++] = chnstr[2 * g];
			result[num++] = chnstr[2 * g + 1];
		}
		if (d * d + e * e + f * f + g * g != 0) {
			result[num++] = s[6];
			result[num++] = s[7];
		}
		if (h == 0) {
			if (b * b + c * c + d * d + e * e + f * f + g * g != 0 && h * h + i * i + j * j + k * k != 0) {
				result[num++] = chnstr[0];
				result[num++] = chnstr[1];
			}
		}
		else {
			result[num++] = chnstr[2 * h];
			result[num++] = chnstr[2 * h + 1];
		}
		if (h != 0) {
			result[num++] = s[4];
			result[num++] = s[5];
		}
		if (i == 0) {
			if (h != 0 && h * h + i * i + j * j + k * k != 0 && j * j + k * k != 0) {
				result[num++] = chnstr[0];
				result[num++] = chnstr[1];
			}
		}
		else {
			result[num++] = chnstr[2 * i];
			result[num++] = chnstr[2 * i + 1];
		}
		if (i != 0) {
			result[num++] = s[2];
			result[num++] = s[3];
		}
		if (j == 0) {
			if (i != 0 && h * h + i * i + j * j + k * k != 0 && k != 0) {
				result[num++] = chnstr[2 * j];
				result[num++] = chnstr[2 * j + 1];
			}
		}
		else {
			result[num++] = chnstr[2 * j];
			result[num++] = chnstr[2 * j + 1];
		}
		if (j != 0) {
			result[num++] = s[0];
			result[num++] = s[1];
		}
		int x;
		x = b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k == 0 && l * l + m * m == 0;
		if (k == 0) {
			if (x == 1) {
				result[num++] = chnstr[2 * k];
				result[num++] = chnstr[2 * k + 1];
			}
		}
		else {
			result[num++] = chnstr[2 * k];
			result[num++] = chnstr[2 * k + 1];
			if (x == 1) {
				result[num++] = chnstr[0];
				result[num++] = chnstr[1];
			}
		}
		if (b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k != 0 || x == 1) {
			result[num++] = s[10];
			result[num++] = s[11];//圆
		}
		if (l * l + m * m == 0) {
			result[num++] = s[16];
			result[num++] = s[17];
		}
		if (l == 0) {
			if (m != 0 && b * b + c * c + d * d + e * e + f * f + g * g + h * h + i * i + j * j + k * k != 0) {
				result[num++] = chnstr[2 * l];
				result[num++] = chnstr[2 * l + 1];
			}
		}
		else {
			result[num++] = chnstr[2 * l];
			result[num++] = chnstr[2 * l + 1];
		}
		if (l != 0) {
			result[num++] = s[12];
			result[num++] = s[13];
		}
		if (l != 0 && m == 0) {
			result[num++] = s[16];
			result[num++] = s[17];
		}
		if (m != 0) {
			result[num++] = chnstr[2 * m];
			result[num++] = chnstr[2 * m + 1];
			result[num++] = s[14];
			result[num++] = s[15];
		}
	result[num] = '\0';

    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}