//
//  getNear2Power.h
//
//  Created by lg on 2020/6/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef getNear2Power_h
#define getNear2Power_h

//输出一个正整数的大于等于它的最近的2次幂的数

int getNear2Power(int i) {
    if (i < 0) {
        return 0;
    }
    int num = i - 1;
    num |= (num >> 1);
    num |= (num >> 2);
    num |= (num >> 4);
    num |= (num >> 8);
    num |= (num >> 16);
    return num + 1;
}

#endif /* getNear2Power_h */
