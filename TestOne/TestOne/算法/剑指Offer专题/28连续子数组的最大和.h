//
//  连续子数组的最大和.h
//
//  Created by lg on 2020/6/17.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef __________h
#define __________h

//连续子数组的最大和
//贪婪算法
int FindGreatestSumOfSubArray(vector<int> array) {
    if (array.size() == 0) {
        return  0;
    }
    //注意，别遗漏了所有数字均为负数的情况，用array【0】代入初始值，可以避免该情况的遗漏。
    int result = array[0];
    int curSum = array[0];
    for (int i = 1; i<array.size(); i++) {
        if (curSum<0) {
            curSum = 0;
        }
        curSum = curSum + array[i];
        if (curSum > result) {
            result = curSum;
        }
    }
    return result;
}

#endif /* __________h */
