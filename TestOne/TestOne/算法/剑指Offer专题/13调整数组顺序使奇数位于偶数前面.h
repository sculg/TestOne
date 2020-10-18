//
//  13调整数组顺序使奇数位于偶数前面.h
//
//  Created by lg on 2020/6/16.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _3________________h
#define _3________________h

//调整数组顺序使奇数位于偶数前面
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
void reOrderArray(vector<int> &array) {
    vector<int> result;
    for (int i = 0; i<array.size(); i++) {
        if (array[i] & 0x01) {
            result.push_back(array[i]);
        }
    }
    for (int i = 0; i<array.size(); i++) {
        if (!(array[i] & 0x01)) {
            result.push_back(array[i]);
        }
    }
    array = result;
}
#endif /* _3________________h */
