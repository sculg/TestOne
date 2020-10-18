//
//  找出数组中比左边的大比右边的小的元素.h
//
//  Created by lg on 2020/7/25.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef ___________________h
#define ___________________h
void ThePivotElements(int data[],int len) {
    int* rightmin = new int[len];
    int r_min = data[len-1];
    for (int i = len-1;i>=0;i--) {
        if(data[i]<r_min)
            r_min = data[i];
        rightmin[i] = r_min;
    }
    int l_max = data[0];
    for (int i= 0;i<len;i++) {
        if(data[i]>l_max)
            l_max = data[i];
        if(l_max == rightmin[i])
            cout<<data[i]<<endl;
    }
}


#endif /* ___________________h */
