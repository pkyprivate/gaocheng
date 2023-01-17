//2151753 彭坤宇 计科
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */
int number = 1;

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        printf("%5d:",number);
        printf("%3d# %c-->%c\n", n, src, dst);
    }
    if (n > 1) {
        hanoi(n - 1, src, dst, tmp);
        number++;
        printf("%5d:", number);
        printf("%3d# %c-->%c\n", n, src, dst);
        number++;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;
    while (1) {
        printf("请输入汉诺塔的层数(1-16)\n");
        int ret;
        ret=scanf("%d", &n);
        if (ret!=1) {
            rewind(stdin);
        }
        if (ret== 1 && n > 0 && n < 17) {
            break;
        }
    }
    while (1) {
        int x;
        printf("请输入起始柱(A-C)\n");
        x = getchar();
        src = getchar();
        if (src == 'a' || src == 'b' || src == 'c' || src == 'A' || src == 'B' || src == 'C')
            break;
    }
    if (src == 'A' || src == 'a') {
        src = 'A';
    }
    if (src == 'B' || src == 'b') {
        src = 'B';
    }
    if (src == 'C' || src == 'c') {
        src = 'C';
    }
    while (1) {
        int x;
        printf("请输入目标柱(A-C)\n");
        x = getchar();
        dst = getchar();
        int t;
        t = (dst == 'a' || dst == 'b' || dst == 'c' || dst == 'A' || dst == 'B' || dst == 'C');
        if (dst == src || dst == src + 32) {
            printf("目标柱(A)不能与起始柱(A)相同\n");
        }
        if (t == 1 && dst != src && dst != src + 32)
            break;
    }

    if (dst == 'A' || dst == 'a') {
        dst = 'A';
    }
    if (dst == 'B' || dst == 'b') {
        dst = 'B';
    }
    if (dst == 'C' || dst == 'c') {
        dst = 'C';
    }
    if (src == 'A' && dst == 'B')tmp = 'C';
    if (src == 'A' && dst == 'C')tmp = 'B';
    if (src == 'B' && dst == 'A')tmp = 'C';
    if (src == 'B' && dst == 'C')tmp = 'A';
    if (src == 'C' && dst == 'A')tmp = 'B';
    if (src == 'C' && dst == 'B')tmp = 'A';
    printf("移动步骤为:\n");
    hanoi(n, src, tmp, dst);
}