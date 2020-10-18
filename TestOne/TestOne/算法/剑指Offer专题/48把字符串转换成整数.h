//
//  48把字符串转换成整数.h
//
//  Created by lg on 2020/6/19.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _8__________h
#define _8__________h

//把字符串转换成整数
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
int StrToInt(string str) {
    int length = str.size();
    int result = 0;
    if (length == 0) {
        return 0;
    }
    int s;
    if (str[0] == '-') {
        s = -1;
    } else {
        s = 1;
    }
    int startIndex = ((str[0] == '-')||(str[0] == '+')) ? 1: 0;
    for (int i = startIndex ; i<length; i++) {
        if (!(str[i]<='9' && str[i]>='0')) {
            return 0;;
        }
        result = result*10 + str[i] - '0';
    }
    return result*s;
}
#endif /* _8__________h */
