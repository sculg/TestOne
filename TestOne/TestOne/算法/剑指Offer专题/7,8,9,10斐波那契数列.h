//
//  斐波那契数列.h
//
//  Created by lg on 2020/6/15.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _______h
#define _______h
//斐波那契数列

//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
//n<=39

//矩形覆盖
//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
int Fibonacci(int n) {
    if (n<2) {
        return n;
    }
    int a = 0;
    int b = 1;
    int result = 0;
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}
#endif /* _______h */
