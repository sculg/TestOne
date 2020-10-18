//
//  35. 搜索插入位置.h
//
//  Created by lg on 2020/7/30.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _5_________h
#define _5_________h

int searchInsert(vector<int>& nums, int target) {
    if(nums.size() == 0) {
        return 0;
    }
    int left = 0;
    int right = nums.size()-1;
    int result = nums.size();
    while (left <= right) {
        int middle = left + (right - left)/2;
        if(nums[middle] >= target) {
            result = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return result;
}


#endif /* _5_________h */
