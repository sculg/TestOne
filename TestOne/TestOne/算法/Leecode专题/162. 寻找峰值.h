//
//  162. 寻找峰值.h
//
//  Created by lg on 2020/8/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _62_______h
#define _62_______h

int findPeakElement(vector<int>& nums) {
    int left=0;
    int right=nums.size()-1;
    while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]>nums[mid+1]){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    return left;
}

#endif /* _62_______h */
