//
//  121. 买卖股票的最佳时机.h
//
//  Created by lg on 2020/6/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _21____________h
#define _21____________h

//121. 买卖股票的最佳时机
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for(int price : prices) {
        maxProfit = max(maxProfit,price-minPrice);
        minPrice = min(minPrice,price);
    }
    return maxProfit;
}

#endif /* _21____________h */
