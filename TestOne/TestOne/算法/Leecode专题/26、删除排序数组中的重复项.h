//
//   26、删除排序数组中的重复项.h
//
//  Created by lg on 2020/7/25.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _26_____________h
#define _26_____________h

int removeDuplicates(vector<int>& arr) {
    if(arr.size() < 1)   //判断数组大小
        return 0;
    int num = 0;    //记录不重复的数目
    arr[num] = arr[0];
    for(int i=0;i<arr.size()-1;i++) {
        if(arr[i+1] != arr[i]) {  //已经排好序的数组，当不相等时记录该数
            arr[++num] = arr[i+1];
        }
    }
    return num+1;
}

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0) {
        return 0;
    }
    int index = 0 ;
    for (int i = 1;i < nums.size() ; i++) {
        if(nums[index]!= nums[i]) {
            nums[++index] = nums[i];
        }
    }
    return index + 1;
}





#endif /* _26_____________h */
