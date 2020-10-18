//
//  singleNumber.h
//
//  Created by lg on 2020/6/2.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef singleNumber_h
#define singleNumber_h
//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

int singleNumber(vector<int>& nums) {
    int result = nums[0];
    for(int i= 1;i<nums.size();i++){
        result^=nums[i];
    }
    return result;
}

#endif /* singleNumber_h */
