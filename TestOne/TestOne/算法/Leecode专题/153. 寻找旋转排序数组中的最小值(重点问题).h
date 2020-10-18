//
//  153. 寻找旋转排序数组中的最小值.h
//
//  Created by lg on 2020/8/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _53________________h
#define _53________________h

int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size()-1;
    while (left < right) {
        int mid = left + (right-left)/2;
        if(nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}

#endif /* _53________________h */
