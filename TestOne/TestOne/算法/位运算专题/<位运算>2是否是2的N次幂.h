//
//  is2Power.h
//
//  Created by lg on 2020/6/3.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef is2Power_h
#define is2Power_h

//判断一个整数是否是2的N次幂

bool is2Power(int i) {
    if (i<0) {
        return false;
    }
    return (i&(i-1)) == 0;
}

#endif /* is2Power_h */
