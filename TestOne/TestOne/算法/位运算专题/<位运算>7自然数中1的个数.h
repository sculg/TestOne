//
//  numOf1.h
//
//  Created by lg on 2020/6/2.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef numOf1_h
#define numOf1_h

//3、自然数中1的个数
int numOf1(int i) {
    int count  = 0;
    if(i < 0) {
        return -1;
    }
    while (i!=0) {
        i &= (i-1);
        count ++;
    }
    return count;
}

#endif /* numOf1_h */
