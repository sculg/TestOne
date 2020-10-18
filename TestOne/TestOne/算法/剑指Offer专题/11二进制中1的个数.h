//
//  11二进制中1的个数.h
//
//  Created by lg on 2020/6/16.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _1____1____h
#define _1____1____h
//二进制中1的个数

//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

int  NumberOf1(int n) {
    int result = 0;
    while (n != 0) {
        n = n & (n - 1);
        result++;
    }
    return result;
}

#endif /* _1____1____h */
