//2151753 彭坤宇 计科

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */
#include<iostream>
using namespace std;
/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    int i, j = 0;
    for (i = 0;; i++) {
        if (str[i] != '\0') {
            j++;
        }
        else {
            break;
        }
    }


    return j; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    for (int i = length1; i < length1 + length2 + 1; i++) {
        s1[i] = s2[i - length1];
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    if (len > length2) {
        for (int i = length1; i < length1 + length2 + 1; i++) {
            s1[i] = s2[i - length1];
        }
    }
    else {
        for (int i = length1; i < length1 + len; i++) {
            s1[i] = s2[i - length1];
        }
    }


    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);

    for (int i = 0; i < length2; i++) {
        s1[i] = s2[i];
    }
    s1[length2] = '\0';
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    if (len >= length2) {
        for (int i = 0; i < length2; i++) {
            s1[i] = s2[i];
        }

    }
    else {
        for (int i = 0; i < len; i++) {
            s1[i] = s2[i];
        }

    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    int x = 0;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    if (length1 >= length2) {
        for (int i = 0; i < length2 + 1; i++) {
            if (s1[i] != s2[i]) {
                x = s1[i] - s2[i];
                break;
            }
        }
    }
    else {
        for (int i = 0; i < length1 + 1; i++) {
            if (s1[i] != s2[i]) {
                x = s1[i] - s2[i];
                break;
            }
        }
    }
    return x;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    int x = 0;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    if (length1 >= length2) {
        for (int i = 0; i < length2 + 1; i++) {
            if (s1[i] != s2[i]) {
                int m, n;
                if (s1[i] >= 65 && s1[i] <= 90) {
                    m = s1[i] + 32;
                }
                else {
                    m = s1[i];
                }
                if (s2[i] >= 65 && s2[i] <= 90) {
                    n = s2[i] + 32;
                }
                else {
                    n = s2[i];
                }
                x = m - n;
                if (x != 0)
                    break;
            }
        }
    }
    else {
        for (int i = 0; i < length1 + 1; i++) {
            if (s1[i] != s2[i]) {
                int m, n;
                if (s1[i] >= 65 && s1[i] <= 90) {
                    m = s1[i] + 32;
                }
                else {
                    m = s1[i];
                }
                if (s2[i] >= 65 && s2[i] <= 90) {
                    n = s2[i] + 32;
                }
                else {
                    n = s2[i];
                }
                x = m - n;
                break;
            }
        }
    }
    return x;
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    int x = 0;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    if (length1 >= length2) {
        if (len > length2) {
            for (int i = 0; i < length2 + 1; i++) {
                if (s1[i] != s2[i]) {
                    x = s1[i] - s2[i];
                    break;
                }
            }
        }
        if (len <= length2) {
            for (int i = 0; i < len; i++) {
                if (s1[i] != s2[i]) {
                    x = s1[i] - s2[i];
                    break;
                }
            }
        }
    }
    else {
        if (len > length1) {
            for (int i = 0; i < length1 + 1; i++) {
                if (s1[i] != s2[i]) {
                    x = s1[i] - s2[i];
                    break;
                }
            }
        }
        if (len <= length1) {
            for (int i = 0; i < len; i++) {
                if (s1[i] != s2[i]) {
                    x = s1[i] - s2[i];
                    break;
                }
            }
        }
    }
    return x;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    int x = 0;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    if (length1 >= length2) {
        if (len > length2) {
            for (int i = 0; i < length2 + 1; i++) {
                if (s1[i] != s2[i]) {
                    int m, n;
                    if (s1[i] >= 65 && s1[i] <= 90) {
                        m = s1[i] + 32;
                    }
                    else {
                        m = s1[i];
                    }
                    if (s2[i] >= 65 && s2[i] <= 90) {
                        n = s2[i] + 32;
                    }
                    else {
                        n = s2[i];
                    }
                    x = m - n;
                    if (x != 0)
                        break;
                }
            }
        }
        if (len <= length2) {
            for (int i = 0; i < len; i++) {
                int m, n;
                if (s1[i] >= 65 && s1[i] <= 90) {
                    m = s1[i] + 32;
                }
                else {
                    m = s1[i];
                }
                if (s2[i] >= 65 && s2[i] <= 90) {
                    n = s2[i] + 32;
                }
                else {
                    n = s2[i];
                }
                x = m - n;
                if (x != 0)
                    break;
            }
        }
    }

    else {
        if (len > length1) {
            for (int i = 0; i < length1 + 1; i++) {
                int m, n;
                if (s1[i] >= 65 && s1[i] <= 90) {
                    m = s1[i] + 32;
                }
                else {
                    m = s1[i];
                }
                if (s2[i] >= 65 && s2[i] <= 90) {
                    n = s2[i] + 32;
                }
                else {
                    n = s2[i];
                }
                x = m - n;
                if (x != 0)
                    break;
            }
        }
        if (len <= length1) {
            for (int i = 0; i < len; i++) {
                int m, n;
                if (s1[i] >= 65 && s1[i] <= 90) {
                    m = s1[i] + 32;
                }
                else {
                    m = s1[i];
                }
                if (s2[i] >= 65 && s2[i] <= 90) {
                    n = s2[i] + 32;
                }
                else {
                    n = s2[i];
                }
                x = m - n;
                if (x != 0)
                    break;
            }
        }
    }
    return x;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    int length = tj_strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] = str[i] - 32;
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    int length = tj_strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
        }
    }
    return 0; //return值可根据需要修改

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    int x = 0;
    int length = tj_strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == ch) {
            x = i + 1;
            break;
        }
    }
    return x;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    int x = 0, m = 1;
    int length1 = tj_strlen(str);
    int length2 = tj_strlen(substr);
    for (int i = 0; i < length1; i++) {
        if (str[i] == substr[0]) {
            for (int j = 0; j < length2; j++) {
                if (str[i + j] != substr[j]) {
                    m = 0;
                    break;
                }
            }
            if (m == 1) {
                x = i + 1;
                break;
            }
            else
                m = 1;
        }
    }
    return x;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    int x = 0;
    int length = tj_strlen(str);
    for (int i = length - 1; i >= 0; i--) {
        if (str[i] == ch) {
            x = i + 1;
            break;
        }
    }
    return x;

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    int x = 0, m = 1;
    int length1 = tj_strlen(str);
    int length2 = tj_strlen(substr);
    for (int i = length1 - 1; i >= 0; i--) {
        if (str[i] == substr[length2 - 1]) {
            for (int j = 1; j <= length2; j++) {
                if (str[i - j + 1] != substr[length2 - j]) {
                    m = 0;
                    break;
                }
            }
            if (m == 1) {
                x = i + 2 - length2;
                break;
            }
            else
                m = 1;
        }
    }
    return x;

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    char x;
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        x = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = x;
    }

    return 0;
}