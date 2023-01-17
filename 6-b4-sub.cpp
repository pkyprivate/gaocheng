//2151753 彭坤宇 计科

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char* str)
{
    if (str == NULL)
        return 0;
    int x = 0;
    for (; *str != '\0'; str++)
        x++;

    return x;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    int len1 = tj_strlen(s1);
    char* p1 = s1 + len1;
    const char* p2 = s2;
    if (s1 == NULL)
        return NULL;
    else if (s2 == NULL)
        return s1;
    while (1)
    {
        if (*p2 == '\0')
        {
            *p1 = *p2;
            break;
        }
        *p1 = *p2;
        p1++;
        p2++;
    }
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
    if (s1 == NULL) {
        return NULL;
    }
    else if (s2 == NULL) {
        return s1;
    }
    char* p1 = s1 + len1;
    const char* p2 = s2;
    if (len >= len2) {
        while (1)
        {
            if (*p2 == '\0')
            {
                *p1 = *p2;
                break;
            }
            *p1 = *p2;
            p1++;
            p2++;
        }
    }
    else {
        while (1)
        {
            if (p2 - s2 == len - 1)
            {
                *p1 = *p2;
                break;
            }
            *p1 = *p2;
            p1++;
            p2++;
        }
        p1++;
        *p1 = '\0';
    }
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    char* p1 = s1;
    const char* p2 = s2;
    if (s1 == NULL)
        return NULL;
    else if (s2 == NULL)
    {
        *p1 = '\0';
        return s1;
    }
    while (1) {
        if (*p2 == '\0') {
            *p1 = *p2;
            break;
        }
        *p1 = *p2;
        p1++, p2++;
    }

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
    char* p1 = s1;
    const char* p2 = s2;
    if (s1 == NULL)
        return NULL;
    else if (s2 == NULL)
    {
        return s1;
    }
    if (len1 >= len2) {
        if (len >= len2) {
            while (1) {
                if (*p2 == '\0') {
                    break;
                }
                *p1 = *p2;
                p1++, p2++;
            }
        }
        else {
            while (1) {
                if (p2 - s2 == len2 - 1) {
                    break;
                }
                *p1 = *p2;
                p1++, p2++;
            }
        }
    }
    else {
        if (len >= len2) {
            while (1) {
                if (*p2 == '\0') {
                    *p1 = *p2;
                    break;
                }
                *p1 = *p2;
                p1++, p2++;
            }
        }
        else {
            if (len <= len1) {
                while (1) {
                    if (p2 - s2 == len - 1) {
                        break;
                    }
                    *p1 = *p2;
                    p1++, p2++;
                }
            }
            else {
                while (1) {
                    if (p2 - s2 == len - 1) {
                        *p1 = *p2;
                        break;
                    }
                    *p1 = *p2;
                    p1++, p2++;
                }
                p1++;
                *p1 = '\0';
            }
        }
    }

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
    int x = len1 < len2 ? len1 : len2;
    const char* p1 = s1;
    const char* p2 = s2;
    if (p1 == NULL && p2 != NULL)
        return -1;
    else if (p2 == NULL && p1 != NULL)
        return 1;
    else if (p1 == NULL && p2 == NULL)
        return 0;
    while (x >= 0)
    {
        x--;
        if (*p1 != *p2)
        {
            return int(*p1 - *p2);
        }
        p1++;
        p2++;
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
int tj_strcasecmp(const char* s1, const char* s2)
{
    int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
    int x = len1 <= len2 ? len1 : len2;
    const char* p1 = s1;
    const char* p2 = s2;
    if (p1 == NULL && p2 != NULL)
        return -1;
    else if (p2 == NULL && p1 != NULL)
        return 1;
    else if (p1 == NULL && p2 == NULL)
        return 0;
    while (x >= 0)
    {
        x--;
        if (*p1 != *p2) {
            if (*p1 >= 'A' && *p1 <= 'Z' && *p2 >= 'A' && *p2 <= 'Z') {
                return int(*p1 - *p2);
            }
            else if (*p1 >= 'A' && *p1 <= 'Z') {
                if (*p2 == *p1 + 32) {
                    p1++;
                    p2++;
                    continue;
                }
                else
                    return int(*p1 - *p2 + 32);
            }
            else if (*p2 >= 'A' && *p2 <= 'Z') {
                if (*p2 == *p1 - 32) {
                    p1++;
                    p2++;
                    continue;
                }
                else
                    return int(*p1 - *p2 - 32);
            }
            else
                return int(*p1 - *p2);
        }
        p1++, p2++;
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
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
    int x = len1 <= len2 ? len1 : len2;
    x = x <= len ? x : len;
    const char* p1 = s1;
    const char* p2 = s2;
    if (p1 == NULL && p2 != NULL)
        return -1;
    else if (p2 == NULL && p1 != NULL)
        return 1;
    else if (p1 == NULL && p2 == NULL)
        return 0;
    if (x == len)
        x--;
    while (x >= 0)
    {
        x--;
        if (*p1 != *p2)
        {
            return int(*p1 - *p2);
        }
        p1++;
        p2++;
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
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
    int x = len1 <= len2 ? len1 : len2;
    x = x < len ? x : len;
    const char* p1 = s1;
    const char* p2 = s2;
    if (p1 == NULL && p2 != NULL)
        return -1;
    else if (p2 == NULL && p1 != NULL)
        return 1;
    else if (p1 == NULL && p2 == NULL)
        return 0;
    if (x == len)
        x--;
    while (x >= 0)
    {
        x--;
        if (*p1 != *p2) {
            if (*p1 >= 'A' && *p1 <= 'Z' && *p2 >= 'A' && *p2 <= 'Z') {
                return int(*p1 - *p2);
            }
            else if (*p1 >= 'A' && *p1 <= 'Z') {
                if (*p2 == *p1 + 32) {
                    p1++;
                    p2++;
                    continue;
                }
                else
                    return int(*p1 - *p2 + 32);
            }
            else if (*p2 >= 'A' && *p2 <= 'Z') {
                if (*p2 == *p1 - 32) {
                    p1++;
                    p2++;
                    continue;
                }
                else
                    return int(*p1 - *p2 - 32);
            }
            else
                return int(*p1 - *p2);
        }
        p1++, p2++;
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
char* tj_strupr(char* str)
{
    char* p = str;
    if (str == NULL)
        return NULL;
    while (1) {
        if (*p == '\0')
            break;
        if (*p >= 'a' && *p <= 'z')
            *p = *p - 32;
        p++;
    }

    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strlwr(char* str)
{
    char* p = str;
    if (str == NULL)
        return NULL;
    while (1) {
        if (*p == '\0')
            break;
        if (*p >= 'A' && *p <= 'Z')
            *p = *p + 32;
        p++;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    const char* p = str;
    if (str == NULL)
        return 0;
    while (1) {
        if (*p == ch) {
            break;
        }
        p++;
        if (*p == '\0')
            break;
    }
    if (*p != '\0')
        return p - str + 1;
    else
        return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    int len = tj_strlen(substr);
    int x = 1;
    const char* p = str;
    const char* p0 = substr;
    if (str == NULL || substr == NULL)
        return 0;
    for (; *p != '\0'; p++) {
        if (*p == *p0) {
            const char* p1 = p;
            for (; *p0 != '\0'; p0++, p1++) {
                if (*p1 != *p0) {
                    x = 0;
                    p0 = substr;
                    break;
                }
            }
            if (x == 1)
                break;
            else
                x = 1;
        }
    }
    if (*p == '\0')
        return 0;
    else
        return p - str + 1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    int len = tj_strlen(str);
    const char* p = str + len;
    if (str == NULL)
        return 0;
    while (1) {
        if (*p == ch) {
            break;
        }
        if (p == str) {
            break;
        }
        p--;
    }
    if (p == str&& *p != ch) {
            return 0;
    }
    else
        return p - str + 1;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    int len1 = tj_strlen(str);
    int len2 = tj_strlen(substr);
    int x = 1;
    const char* p1 = str + len1 - 1;
    const char* p2 = substr + len2 - 1;
    if (str == NULL || substr == NULL)
        return 0;
    for (; p1 - str >= 0; p1--) {
        if (*p1 == *p2) {
            const char* p = p1;
            for (; p2 - substr >= 0; p--, p2--) {
                if (*p != *p2) {
                    p2 = substr + len2 - 1;
                    x = 0;
                    break;
                }
            }
            if (x == 1) {
                break;
            }
            if (x == 0) {
                x = 1;
            }
        }
    }
    if (p1 - str == -1)
        return 0;
    else
        return p1 - str + 2 - len2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
    int len = tj_strlen(str);
    char* p0 = str + len - 1;
    char* p1 = str;
    char x;
    if (str == NULL)
        return NULL;
    for (; p0 >= p1; p0--, p1++) {
        x = *p0;
        *p0 = *p1;
        *p1 = x;
    }

    return str;
}