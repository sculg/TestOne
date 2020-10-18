//
//  字符串去空格.h
//
//  Created by lg on 2020/7/25.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _______h
#define _______h

/*去除字符串左边的空格*/
char* ltrim(char* s)
{
    int i = 0, j = 0;

    if(s == NULL)
        return (char *)NULL;

    while(' ' == s[i] || '\t' == s[i])
        i++;

    if(0 == i)
        return s;

    while('\0' != s[j + i])
        {
        s[j] = s[j + i];
        j++;
        }

    s[j] = '\0';

    return s;
}

/*去除字符串右边的空格*/
char* rtrim(char* s)
{
    int i;

    if(s == NULL)
        return (char *)NULL;

    for(i = strlen(s); i > 0; i--)
        {
        if(s[i - 1] == ' ' || s[i - 1] == '\t')
            s[i - 1] = '\0';
        else
            break;
        }

    return s;
}

void ltrim(char *s)
{// 去掉前部的
    int l=0,p=0,k=0;
    l = strlen(s);
    if( l == 0 ) return;
    p = 0;
    while( s[p] == ' ' || s[p] == '\t' )  p++;
    if( p == 0 ) return;
    while( s[k] != '\0') s[k++] = s[p++];
    return;
}

void rtrim(char *s)
{// 去掉尾部的
    int l=0,p=0;
    l = strlen(s);
    if( l == 0 ) return;
    p = l -1;
    while( s[p] == ' ' || s[p] == '\t' ) {
        s[p--] = '\0';
        if( p < 0 ) break;
    }
    return;
}

/*去除字符串两边的空格*/
char* alltrim(char* s)
{
    ltrim(s);
    rtrim(s);
    return s;
}
————————————————
版权声明：本文为CSDN博主「导演我躺哪儿」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u010931295/java/article/details/89312328

#endif /* _______h */
