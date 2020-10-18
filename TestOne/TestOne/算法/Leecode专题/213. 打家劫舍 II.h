//
//  213. 打家劫舍 II.h
//
//  Created by lg on 2020/6/28.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _13_______II_h
#define _13_______II_h

//213. 打家劫舍 II
int rob(vector<int>& nums) {
    int count = nums.size();
    if(count == 0) {
        return 0;
    }
    if(count == 1) {
        return nums[0];
    }
    vector<int> dp(count+1,-1);
    vector<int> dp1(count+1,-1);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int i = 2;i < count-1;i++) {
        dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
    }
    dp1[0] = 0;
    dp1[1] = nums[1];
    for(int i = 2;i < count;i++) {
        dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i]);
    }
    return dp[count-2] > dp1[count-1] ? dp[count-2] : dp1[count-1];
}

#endif /* _13_______II_h */
