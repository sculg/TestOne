//
//  maxProfit3.h
//
//  Created by lg on 2019/9/27.
//  Copyright © 2019 sculg. All rights reserved.
//

#ifndef maxProfit3_h
#define maxProfit3_h

//714. 买卖股票的最佳时机含手续费

//给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。你可以无限次地完成交易，但是你每次交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。返回获得利润的最大值。
//示例 1:
//输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
//输出: 8
//解释: 能够达到的最大利润:
//在此处买入 prices[0] = 1
//在此处卖出 prices[3] = 8
//在此处买入 prices[4] = 4
//在此处卖出 prices[5] = 9
//总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
//注意:
//0 < prices.length <= 50000.
//0 < prices[i] < 50000

int maxProfit(vector<int>& prices, int fee) {
    if (prices.size() <= 1) {
        return 0;
    }
    
    int cash = 0;
    int hold = -prices[0];
    for(int i=1; i<prices.size(); i++){
        cash = max(cash, hold+prices[i]-fee);
        hold = max(hold, cash-prices[i]);
    }
    return cash;
}

int maxProfit(vector<int>& prices, int fee) {
    if (prices.size()<=1) {
        return 0;
    }
    int hold[2] = {-prices[0],0};
    int cash[2] = {0,0};

    for (int i = 1; i < prices.size(); i++) {
        hold[i%2] = max(hold[(i-1)%2],cash[(i-1)%2] - prices[i]);
        cash[i%2] = max(cash[(i-1)%2],hold[(i-1)%2] + prices[i] - fee);
    };
    return cash[(prices.size()-1)%2];
}

int arr[] = {3,1,2,5,8,9};
vector<int> priceVect(arr,arr+sizeof(arr)/sizeof(int));
int maxProfit = Solution().maxProfit(priceVect,2);
cout<< maxProfit << endl;

#endif /* maxProfit3_h */
