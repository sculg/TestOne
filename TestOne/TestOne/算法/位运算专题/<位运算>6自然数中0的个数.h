//
//  numOf0.h
//
//  Created by lg on 2020/6/2.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef numOf0_h
#define numOf0_h

//2、自然数中0的个数
int numOf0(int i) {
    int count  = 0;
    if(i < 0) {
        return -1;
    }
    while (i!=0) {
        if ((i & 1) == 0) {
            count ++;
        }
        i>>=1;
    }
    return count;
}

#endif /* numOf0_h */
