//
//  66. 加一.h
//
//  Created by lg on 2020/8/5.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _6_____h
#define _6_____h

vector<int> plusOne(vector<int>& digits) {
    int length = digits.size();
    for(int i = length-1; i >= 0; --i) {
        if(digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i] += 1;
            break;
        }
    }
    if(digits[0] == 0) {
        digits[0] = 1;
        digits.push_back(0);
    }
    return digits;
}

#endif /* _6_____h */
