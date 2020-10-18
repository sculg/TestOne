//
//  36左旋转字符串.h
//
//  Created by lg on 2020/6/18.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _6_______h
#define _6_______h

//左旋转字符串
//例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
void reverse(string &str,int startIndex,int endIndex) {
    while (startIndex < endIndex) {
        char temp = str[startIndex];
        str[startIndex] = str[endIndex];
        str[endIndex] = temp;
        startIndex++;
        endIndex--;
    }
}

string LeftRotateString(string str, int n) {
    int length = str.size();
    if (!str.empty() && n<=length) {
        int pFirstStart = 0;
        int pFirstEnd = n-1;
        int pSecondStart = n;
        int pSecondEnd = length - 1;
        reverse(str, pFirstStart, pFirstEnd);
        reverse(str, pSecondStart, pSecondEnd);
        reverse(str, pFirstStart, pSecondEnd);
    }
    return str;
}
#endif /* _6_______h */
