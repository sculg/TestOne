//
//  46第一个只出现一次的字符.h
//
//  Created by lg on 2020/6/19.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _6____________h
#define _6____________h

//第一个只出现一次的字符
//在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数
int FirstNotRepeatingChar(string str) {
    if (str.size() == 0) {
        return -1;
    }
    char ch[256] = {0};
    for (int i = 0; i<str.size(); i++) {
        ch[str[i]]++;
    }
    for (int i = 0; i<str.size(); i++) {
        if (ch[str[i]] == 1) {
            return i;
        }
    }
    return 0;
}
#endif /* _6____________h */
