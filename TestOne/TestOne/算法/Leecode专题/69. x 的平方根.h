//
//  69. x 的平方根.h
//
//  Created by lg on 2020/8/5.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _9__x______h
#define _9__x______h

int mySqrt(int x) {
    int left = 0;
    int right = x;
    int result = 0;
    while(left <= right) {
        int mid = left + (right - left)/2;
        if((long long)mid * mid <= x) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

#endif /* _9__x______h */
