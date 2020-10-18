//
//  123. 买卖股票的最佳时机 III.h
//
//  Created by lg on 2020/6/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _23____________III_h
#define _23____________III_h

//123. 买卖股票的最佳时机 III
//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
//设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

int maxProfit(vector<int>& prices) {
    int  n = prices.size();
    if(n == 0) {
        return 0;
    }
    int minPrice = prices.front(),maxProfit1 = 0;
    int maxPrice = prices.back(),maxProfit2 = 0;
    vector<int> profit1(n,0),profit2(n,0);
    for(int i = 0; i < n; i++) {
        if(prices[i] <=  minPrice) {
            minPrice = prices[i];
        } else {
            maxProfit1 = max(maxProfit1,prices[i]-minPrice);
        }
        profit1[i] = maxProfit1;
        if(prices[n-i-1] >=  maxPrice) {
            maxPrice = prices[n-i-1];
        } else {
            maxProfit2 = max(maxProfit2,maxPrice-prices[n-i-1]);
        }
        profit2[n-i-1] = maxProfit2;
    }
    int maxPro = profit1[n-1];
    for(int i = 0;i < n-1;i++) {
        maxPro = max(maxPro,profit1[i] + profit2[i+1]);
    }
    return maxPro;
}

#endif /* _23____________III_h */
