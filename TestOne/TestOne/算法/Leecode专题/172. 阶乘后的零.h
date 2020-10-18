//
//  172. 阶乘后的零.h
//
//  Created by lg on 2020/8/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _72________h
#define _72________h

int trailingZeroes(int n) {
    int count=0;
    while(n>0){
        count=count+n/5;
        n=n/5;
    }
    return count;
}

#endif /* _72________h */
