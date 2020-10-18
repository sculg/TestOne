//
//  39数组中重复的数字.h
//
//  Created by lg on 2020/6/18.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _9_________h
#define _9_________h

//数组中重复的数字
//在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
bool duplicate(int numbers[], int length, int* duplication) {
    if (numbers == nullptr || length == 0) {
        return false;
    }
    for (int i = 0; i<length; i++) {
        if (numbers[i]<0 || numbers[i]>length) {
            return false;
        }
    }
    for (int i = 0; i<length; i++) {
        if (numbers[i] != i) {
            if (numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }
            //注意下面三行代码的写法
            int j = numbers[numbers[i]];
            numbers[numbers[i]] = numbers[i];
            numbers[i] = j;
        }
    }
    return false;
}
#endif /* _9_________h */
