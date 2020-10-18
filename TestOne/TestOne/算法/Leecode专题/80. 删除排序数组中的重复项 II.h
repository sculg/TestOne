//
//  80. 删除排序数组中的重复项 II.h
//
//  Created by lg on 2020/7/25.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _0______________II_h
#define _0______________II_h

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2) {
        return n;
    }
    int index = 1;
    for(int i = 2; i < n; i++) {
        if(nums[i] != nums[index - 1]) {
            nums[++index] = nums[i];
        }
    }
    return index + 1;
}

#endif /* _0______________II_h */
