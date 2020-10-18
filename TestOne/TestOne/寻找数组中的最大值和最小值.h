//
//  寻找数组中的最大值和最小值.h
//
//  Created by lg on 2020/7/25.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef ______________h
#define ______________h

vector<int> findMaxAndMin(vector<int> &arr) {
    vector<int> result;
    if(arr.size() == 0) {
        return result;
    }
    if(arr.size() == 1) {
        result.push_back(arr[0]);
        result.push_back(arr[0]);
        return result;
    }
    for(int i = 0;i<arr.size();i = i + 2) {
        if(arr[i] < arr[i+1]) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    int max = 0;
    for (int i = 0; i < arr.size(); i = i+2) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    int min = 0;
    for (int i = 1; i < arr.size(); i = i+2) {
        if(min > arr[i]) {
            min = arr[i];
        }
    }
    result.push_back(max);
    result.push_back(min);
    return result;
}

#endif /* ______________h */
