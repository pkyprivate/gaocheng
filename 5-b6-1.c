//2151753 彭坤宇 计科
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int a[11] = { 0 }, b[11] = { 0 }, c[11] = { 0 };
int sum = 0, ta = 1, tb = 1, tc = 1;
void Aprint()
{
    printf("A:");
    for (int i = 1; i < ta; i++)
        printf("%2d",a[i]);
    for (int i = 10; i >= ta; i--)
       printf("  ");
    printf(" ");
}

void Bprint()
{
    printf("B:");
    for (int i = 1; i < tb; i++)
        printf("%2d", b[i]);
    for (int i = 10; i >= tb; i--)
        printf("  ");
    printf(" ");
}

void Cprint()
{
    printf("C:");
    for (int i = 1; i < tc; i++)
        printf("%2d", c[i]);
    for (int i = 10; i >= tc; i--)
        printf("  ");
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n > 1)
        hanoi(n - 1, src, dst, tmp);
    sum++;
    printf("第%4d 步", sum);
    printf("(%2d): %c-->%c ", n, src, dst);
    if (src == 'A' && dst == 'B')
        b[tb++] = a[--ta];
    if (src == 'A' && dst == 'C')
        c[tc++] = a[--ta];
    if (src == 'B' && dst == 'A')
        a[ta++] = b[--tb];
    if (src == 'B' && dst == 'C')
        c[tc++] = b[--tb];
    if (src == 'C' && dst == 'B')
        b[tb++] = c[--tc];
    if (src == 'C' && dst == 'A')
        a[ta++] = c[--tc];
    Aprint();
    Bprint();
    Cprint();
    printf("\n");
    if (n > 1)
        hanoi(n - 1, tmp, src, dst);
}

char a_to_A(char a)
{
    if (a >= 'a' && a <= 'z')
        return (char)(a - 32);
    else
        return a;
}

int main()
{
    int n;
    char src, tmp, dst;
    while (1)
    {
        printf("请输入汉诺塔的层数(1-10)\n");
        int ret=scanf("%d", &n);
        if (ret == 0)
        {
            rewind(stdin);
            continue;
        }
        if (n >= 1 && n <= 10)
        {
            rewind(stdin);
            break;
        }
    }
    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        int ret=scanf("%c",&src);
        src = a_to_A(src);
        if (ret==0)
        {
            rewind(stdin);
            continue;
        }
        if (src == 'A' || src == 'B' || src == 'C')
        {
            rewind(stdin);
            break;
        }
        rewind(stdin);
    }
    while (1)
    {
       printf("请输入目标柱(A-C)\n");
       int ret = scanf("%c", &dst);
        dst = a_to_A(dst);
        if (ret== 0)
        {
            rewind(stdin);
            continue;
        }
        if (dst == src)
        {
            printf("目标柱(%c)不能与起始柱(%c)相同\n",dst,src);
            rewind(stdin);
            continue;
        }
        if (dst == 'A' || dst == 'B' || dst == 'C')
        {
            rewind(stdin);
            break;
        }
        rewind(stdin);
    }
    if (src == 'A' && dst == 'B' || src == 'B' && dst == 'A')
        tmp = 'C';
    if (src == 'C' && dst == 'B' || src == 'B' && dst == 'C')
        tmp = 'A';
    if (src == 'A' && dst == 'C' || src == 'C' && dst == 'A')
        tmp = 'B';
    printf("初始:                ");
    if (src == 'A')
        for (int i = n; i >= 1; i--) {
            a[ta++] = i;
        }
    if (src == 'B')
        for (int i = n; i >= 1; i--) {
            b[tb++] = i;
        }
    if (src == 'C')
        for (int i = n; i >= 1; i--) {
            c[tc++] = i;
        }
    //初始化三根柱子
    Aprint();
    Bprint();
    Cprint();
    printf("\n");
    hanoi(n, src, tmp, dst);
    return 0;
}