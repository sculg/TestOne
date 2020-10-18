//
//  53. 最大子序和.h
//
//  Created by lg on 2020/6/28.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _3________h
#define _3________h

//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//示例:
//输入: [-2,1,-3,4,-1,2,1,-5,4],
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

 int maxSubArray(vector<int> &nums) {
    //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
    int result = INT_MIN;
    int numsSize = int(nums.size());
    //dp[i]表示nums中以nums[i]结尾的最大子序和
    vector<int> dp(numsSize);
    dp[0] = nums[0];
    result = dp[0];
    for (int i = 1; i < numsSize; i++)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        result = max(result, dp[i]);
    }

    return result;
}


#endif /* _3________h */
