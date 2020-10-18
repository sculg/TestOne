//
//  33数组中只出现一次的数字.h
//
//  Created by lg on 2020/6/18.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _3____________h
#define _3____________h

//数组中只出现一次的数字
//一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    if (data.size() < 2) {
        return;
    }
    int tem = data[0];
    for (int i = 1; i<data.size(); i++) {
        tem ^= data[i];
    }
    int indexOf1 = FindFisrtOf1(tem);
    *num1 = *num2 = 0;
    for (int i = 0; i<data.size(); i++) {
        if (Is1Atindex(data[i],indexOf1)) {
            *num1 ^= data[i];
        } else {
            *num2 ^= data[i];
        }
    }
}
bool Is1Atindex(int number,int index) {
    number = number>>index;
    return number&0x01;;
}

int FindFisrtOf1(int number) {
    int index = 0;
    while ((number&0x01) == 0 && index<8*sizeof(int)) {
        number = number>>1;
        ++index;
    }
    return index;
}

#endif /* _3____________h */
