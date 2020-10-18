//
//  59数字在排序数组中出现的次数.h
//
//  Created by lg on 2020/6/24.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _9______________h
#define _9______________h

//数字在排序数组中出现的次数
//统计一个数字在排序数组中出现的次数。
//思路：因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5。这两个数应该插入的位置，然后相减即可。
int biSearch(vector<int>data, double num) {
    int s = 0, e = data.size()-1;
    while(s <= e){
        int mid = (e - s)/2 + s;
        if(data[mid] < num)
            s = mid + 1;
        else if(data[mid] > num)
            e = mid - 1;
    }
    return s;//注意这里不是返回的mid，而是插入的位置
}

int GetNumberOfK(vector<int> data ,int k) {
    return biSearch(data, k+0.5) - biSearch(data, k-0.5) ;
}

#endif /* _9______________h */
