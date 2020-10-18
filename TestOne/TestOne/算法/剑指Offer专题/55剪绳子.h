//
//  55剪绳子.h
//
//  Created by lg on 2020/6/20.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _5____h
#define _5____h

//剪绳子
//给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[1],...,k[m]。请问k[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

int cutRope(int number) {
    vector<int> tem(number+1,0);
    tem[0] = 0;
    for (int i = 1; i<=number; i++) {
        tem[i] = i/2*(i-i/2);
        for (int j = i - 1; j>0; j--) {
            tem[i] = max(tem[i], tem[j]*tem[i-j]);
        }
    }
    return tem[number];
}

#endif /* _5____h */
