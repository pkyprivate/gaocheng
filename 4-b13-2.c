//2151753 ������ �ƿ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */
int number = 1;

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;
    while (1) {
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
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
        printf("��������ʼ��(A-C)\n");
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
        printf("������Ŀ����(A-C)\n");
        x = getchar();
        dst = getchar();
        int t;
        t = (dst == 'a' || dst == 'b' || dst == 'c' || dst == 'A' || dst == 'B' || dst == 'C');
        if (dst == src || dst == src + 32) {
            printf("Ŀ����(A)��������ʼ��(A)��ͬ\n");
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
    printf("�ƶ�����Ϊ:\n");
    hanoi(n, src, tmp, dst);
}