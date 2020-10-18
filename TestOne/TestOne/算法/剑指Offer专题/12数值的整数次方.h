//
//  数值的整数次方.h
//
//  Created by lg on 2020/6/16.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef ________h
#define ________h
//数值的整数次方
//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
double Power(double base, int exponent) {
    int p = abs(exponent);//注意有可能是负数次方
    double result = 1.0;
    while (p) {
        if (p&1) {
            result = result * base;
        }
        base = base * base; //此方法让时间复杂度由n变成O(logn)
        p = p>>1;
    }
    return exponent>0 ? result:1/result;
}

#endif /* ________h */
