//
//  4. 寻找两个正序数组的中位数.h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef ________________h
#define ________________h

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double result;
    vector<int> temp;
    int nums1Length = nums1.size();
    int nums2Length = nums2.size();
    int leftIndex = 0;
    for (int i = 0; i < nums2Length; i++) {
        while(leftIndex < nums1Length && nums1[leftIndex] <= nums2[i]) {
            temp.push_back(nums1[leftIndex]);
            leftIndex++;
        }
        temp.push_back(nums2[i]);
    }
    while(leftIndex < nums1Length) {
        temp.push_back(nums1[leftIndex]);
        leftIndex++;
    }
    if(temp.size() & 0x01) {
        result = temp[temp.size()/2];
    } else {
        result = (double)(temp[(temp.size() + 1)/2] + temp[(temp.size() - 1)/2])/(double)2.0;
    }
    return result;
}

#endif /* ________________h */
