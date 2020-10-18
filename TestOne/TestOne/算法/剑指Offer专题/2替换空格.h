//
//  replaceSpace.h
//
//  Created by lg on 2020/6/14.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef replaceSpace_h
#define replaceSpace_h
//替换空格

//请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

void replaceSpace(char *str,int length) {
    if (str == nullptr || length <= 0) {
        return;
    }
    int numberOfSpace = 0;
    int numberOfChar = 0;
    int i = 0;
    while (str[i] != '\0') { // '\0'字符串结尾符
        ++numberOfChar;
        if (str[i] == ' ') {
            numberOfSpace++;
        }
        ++i;
    }
    int numberOfNew = numberOfSpace*2 + numberOfChar;
    if (numberOfNew > length) {
        return;
    }
    int newIndex = numberOfNew;
    for (int j = numberOfChar; j >= 0; j--) {
        if(str[j] == ' ') {
            str[newIndex--] = '0';
            str[newIndex--] = '2';
            str[newIndex--] = '%';
        } else {
            str[newIndex--] = str[j];
        }
    }
}

#endif /* replaceSpace_h */
