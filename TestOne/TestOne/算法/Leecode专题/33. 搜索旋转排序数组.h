//
//  33. 搜索旋转排序数组.h
//
//  Created by lg on 2020/7/30.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _3___________h
#define _3___________h

int search(vector<int>& nums, int target) {
    if(nums.size() == 0) {
        return -1;
    }
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high) {
        int middle = low + (high - low)/2;
        if(nums[middle] == target) {
            return middle;
        }
        if(nums[low] <= nums[middle]) {
            if(target>=nums[low] && nums[middle] > target) {
                high = middle-1;
            } else {
                low = middle+1;
            }
        } else {
            if(target<=nums[high] && nums[middle] < target) {
                low = middle+1;
            } else {
                high = middle-1;
            }
        }
    }
    return -1;
}

//执行用时：4 ms, 在所有 C++ 提交中击败了 65.32% 的用户
//内存消耗：6.4 MB, 在所有 C++ 提交中击败了78.13%的用户
#endif /* _3___________h */
