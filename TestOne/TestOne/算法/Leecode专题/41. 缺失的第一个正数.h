//
//  41. 缺失的第一个正数.h
//
//  Created by lg on 2020/8/1.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _1___________h
#define _1___________h

int firstMissingPositive(vector<int>& nums) {
    if(nums.size() == 0) {
        return 1;
    }
    sort(nums.begin(),nums.end());
    int startOf1 = -1;
    for(int i = 0;i < nums.size(); i++) {
        if(nums[i] <= 0) {
            continue;
        } else if(startOf1 == -1) {
            if(nums[i] != 1) {
                return 1;
            }
            startOf1 = i;
        } else {
            if(nums[i] != nums[startOf1] + 1 && nums[i] != nums[i-1]) {
                return nums[startOf1] + 1;
            } else {
                startOf1 = i;
            }
        }
    }
    return startOf1 == -1 ? 1 : nums[startOf1] + 1;
}

int firstMissingPositive(vector<int>& nums) {
    int n=nums.size();
    if(n==0)
        return 1;
    for(int i=0;i<n;i++){
        while(nums[i]>0 && nums[i]<n && nums[i]!=nums[nums[i]])//注意此处应为while循环，而不是if
            swap(nums[i],nums[nums[i]]);// 把num[i]放在第num[i]位置上
    }
    for(int i=1;i<n;i++){
        if(nums[i]!=i)
            return i;
    }
    return nums[0]==n?n+1:n;
}

https://leetcode-cn.com/problems/first-missing-positive/solution/jian-ji-dai-ma-on-shuang-bai-yi-li-jie-by-jeffery-/


#endif /* _1___________h */
