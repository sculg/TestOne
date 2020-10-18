//
//  46. 全排列.h
//
//  Created by lg on 2020/8/1.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _6______h
#define _6______h
private:

private:
    vector<vector<int>> result;
    vector<int> nums;
    void permute1(int first,int end) {
        if(first == end) {
            result.push_back(nums);
        }
        for(int i = first; i < end; i++) {
            swap(nums[i],nums[first]);
            permute1(first + 1,end);
            swap(nums[i],nums[first]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        permute1(0,nums.size());
        return result;
    }
#endif /* _6______h */
