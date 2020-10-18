//
//  9. 回文数.h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _______h
#define _______h

bool isPalindrome(int x) {
    if(x < 0) {
        return false;
    }
    if(x % 10 == 0 && x != 0) {
        return false;
    }
    int num = 0;
    while(x > num) {
        num = num * 10 + x % 10;
        x = x / 10;
    }
    return x == num || x == num / 10;
}
#endif /* _______h */
