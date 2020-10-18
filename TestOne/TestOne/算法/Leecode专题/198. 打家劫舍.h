//
//  198. 打家劫舍.h
//
//  Created by lg on 2020/6/28.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _98_______h
#define _98_______h

//198. 打家劫舍
int rob(vector<int>& nums) {
    int length = nums.size();
    if(length == 0) return 0;
    vector<int> dp(length+1,-1);
    dp[0] = nums[0];
    if(length>=2) {
        dp[1] = max(nums[0],nums[1]);
    }
    for(int i = 2; i<length; i++) {
        dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
    }
    return dp[length-1];
}

#endif /* _98_______h */
