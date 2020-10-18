//
//  7. 整数反转.h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef ________h
#define ________h

int reverse(int x) {
    long result = 0;
    int i = x;
    while(i != 0) {
        result = result * 10 + i % 10;
        i = i/10;
    }
    return (result > INT_MAX) || (result < INT_MIN)  ? 0 : result;
}

#endif /* ________h */
