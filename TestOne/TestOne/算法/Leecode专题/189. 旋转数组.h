//
//  189. 旋转数组.h
//
//  Created by lg on 2020/8/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _89_______h
#define _89_______h

void rotate(vector<int>& nums, int k) {
    if(nums.empty() || (k %= nums.size()) == 0) {
        return;
    }
    int n = nums.size();
    reverse(nums.begin(),nums.begin() + n -k);
    reverse(nums.begin() + n -k,nums.end());
    reverse(nums.begin(),nums.end());
}

#endif /* _89_______h */
