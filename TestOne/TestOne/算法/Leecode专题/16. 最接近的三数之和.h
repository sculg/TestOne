//
//  16. 最接近的三数之和.h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _6___________h
#define _6___________h

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int minCount = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size() - 2; i ++) {
        int j = i + 1;
        int k = nums.size()-1;
        while (j < k) {
            int threeSum = nums[i] + nums[j] + nums[k];
            if(abs(threeSum - target) < abs(minCount - target)) {
                minCount = threeSum;
            }
            if (threeSum == target) {
                return target;
            } else if (threeSum < target) {
                j++;
            } else {
                k--;
            }
        }
    }
    return minCount;
}

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int minCount = nums[0] + nums[1] + nums[2];
    int n, j, k ;
    for (int i = 0; i < nums.size() - 2; i ++) {
        n = i;
        j = i + 1;
        k = nums.size()-1;
        int threeSum = nums[n] + nums[j] + nums[k];
        while (j < k) {
            if(abs(threeSum - target) < abs(minCount - target)) {
                minCount = threeSum;
            }
            int difference = target - threeSum;
            if (difference == 0) {
                return target;
            } else if (difference > 0) {
                j++;
            } else {
                k--;
            }
            threeSum = nums[n] + nums[j] + nums[k];
        }
    }
    return minCount;
}

#endif /* _6___________h */
