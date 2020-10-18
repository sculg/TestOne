//
//  和为S的两个数字.h
//
//  Created by lg on 2020/6/18.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef __S______h
#define __S______h

//和为S的两个数字
//输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    int leftIndex = 0;
    int rightIndex = array.size()-1;
    int curSum = 0;
    vector<int> res;
    while(leftIndex < rightIndex) {
        curSum = array[leftIndex] + array[rightIndex];
        if(curSum > sum) {
            rightIndex--;
        } else if(curSum < sum){
            leftIndex++;
        } else {
            res.push_back(array[leftIndex]);
            res.push_back(array[rightIndex]);
            break;
        }
    }
    return res;
}
#endif /* __S______h */
