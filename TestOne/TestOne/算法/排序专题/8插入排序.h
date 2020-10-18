//
//  InsertSort.h
//
//  Created by lg on 2019/9/16.
//  Copyright © 2019 sculg. All rights reserved.
//

#ifndef InsertSort_h
#define InsertSort_h

void InsertSort(int a[], int len)
{
    int i, j, key;
    for(i = 1; i < len; ++i){
        key = a[i];
        for(j = i-1; j >=0; --j){
            if(a[j] > key)
                a[j+1] = a[j];
            else
                break;
        }
        a[j+1] = key;
    }
}

#endif /* InsertSort_h */
