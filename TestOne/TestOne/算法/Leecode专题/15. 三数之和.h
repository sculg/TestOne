//
//  15. 三数之和.h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _5_______h
#define _5_______h

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    for (int first = 0; first < n;first++) {
        if(first > 0 && nums[first] == nums[first - 1]) {
            continue;
        }
        int third = n-1;
        int target = -nums[first];
        for(int second = first + 1;second < n; second++) {
            if(second > first + 1 && nums[second] == nums[second - 1]) {
                continue;
            }
            while(second < third && nums[second] + nums[third] > target) {
                third--;
            }
            if(third == second) {
               break;
            }
            if(nums[second] + nums[third] == target) {
                result.push_back({nums[first],nums[second],nums[third]});
            }
        }
    }
    return result;
}

#endif /* _5_______h */
