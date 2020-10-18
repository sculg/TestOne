//
//  34. 在排序数组中查找元素的第一个和最后一个位置.h
//
//  Created by lg on 2020/7/30.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _4________________________h
#define _4________________________h

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result;
    if(nums.size() == 0) {
        return {-1,-1};
    }
    int left = 0;
    int right = nums.size() - 1;
    while(left < right) {
        int middle = left + (right-left)/2;
        if(nums[middle] >= target) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    if(nums[left] == target) {
        result.push_back(left);
    } else {
        return {-1,-1};
    }
    

    left = 0;
    right = nums.size() -1;
    while (left < right) {
        int middle = left + (right-left) + 1/2;
        if(nums[middle] <= target) {
            left = middle;
        } else {
            right = middle - 1;
        }
    }
    if( nums[right] == target) {
        result.push_back(right);
    } else {
        return {-1,-1};
    }
    return result;
}

#endif /* _4________________________h */
