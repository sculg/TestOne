//
//  62把一个字符串转换成整数.h
//
//  Created by lg on 2020/7/1.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _2____________h
#define _2____________h

//62把一个字符串转换成整数
int StrToInt(char *string) {
    int num = 0;
    if (string == NULL || *string == '\0') {
        return -1;
    }
    char *temp = string;
    int flag = 1;
    if (*temp == '+') {
        flag = 1;
        temp++;
    } else if (*temp == '-') {
        flag = -1;
        temp++;
    }
    while (*temp !='\0') {
        if(*temp >='0' && *temp <= '9' ) {
            num = num*10 + *temp - '0';
        }
        else {
            return -1;
        }
        temp++;
    }
    return num*flag;
}
#endif /* _2____________h */
