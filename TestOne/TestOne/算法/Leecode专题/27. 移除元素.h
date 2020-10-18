//
//  27. 移除元素.h
//
//  Created by lg on 2020/7/30.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _7_______h
#define _7_______h

int removeElement(vector<int>& nums, int val) {
    if(nums.size() == 0) {
        return 0;
    }
    for(int i = nums.size() - 1; i >= 0; i--) {
        if(nums[i] == val) {
            for(int j = i;j < nums.size()-1;j++) {
                nums[j] = nums[j+1];
            }
            nums.pop_back();
        }
        
    }
    return nums.size();
}

#endif /* _7_______h */
