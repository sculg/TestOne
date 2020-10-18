//
//  441. 排列硬币.h
//
//  Created by lg on 2020/6/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _41_______h
#define _41_______h

//441. 排列硬币
//你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。
//给定一个数字 n，找出可形成完整阶梯行的总行数。
int arrangeCoins(int n) {
    int low = 1;
    int high = n;
    while(low <= high){
        long mid = low + (high - low) / 2;
        long sum = mid * (mid + 1) / 2;
        if(sum > n)
            high = mid - 1;
        else if(sum == n)
            return mid;
        else if(sum < n)
            low = mid + 1;
    }
    return low - 1;
}

int arrangeCoins(int n) {
    int i;
    for(i=1;i<=n;i++) {
        n-=i;
    }
    return i-1;
}


#endif /* _41_______h */
