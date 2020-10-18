//
//  38不用加减乘除做加法.h
//
//  Created by lg on 2020/6/18.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _8__________h
#define _8__________h

//不用加减乘除做加法
//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
int Add(int num1, int num2){
    int sum ,carry;
    do {
        sum = num1 ^ num2;
        carry = (num1 & num2)<<1;
        
        num1 = sum;
        num2 = carry;
        
    } while (num2 != 0);
    return num1;
}

#endif /* _8__________h */
