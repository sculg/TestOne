//
//  322. 零钱兑换.h
//
//  Created by lg on 2020/6/28.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _22_______h
#define _22_______h

//322. 零钱兑换
//给定不同面额的硬币 coins 和一个总金额 amount。
//编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
//如果没有任何一种硬币组合能组成总金额，返回 -1。
int coinChange(vector<int>& coins, int amount) {
    if(coins.size() == 0 || amount == 0) {
        return 0;
    }
    vector<int> dp(amount+1,-1);
    for(int i = 0;i<coins.size();i++) {
        if(coins[i] == amount) {
            return 1;
        }
        dp[coins[i]] = 1;
    }
    for(int i = 1; i <= amount; i++) {
        for(int j = 0;j<coins.size();j++) {
            if(i-coins[j]>=0 && dp[i-coins[j]] != -1){
                if(dp[i]== -1 || dp[i] > dp[i - coins[j]] + 1) {
                    dp[i] = dp[i-coins[j]]+1;
                }
            }
        }
    }
    return dp[amount];
}

#endif /* _22_______h */
