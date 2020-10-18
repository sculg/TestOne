//
//  51构建乘积数组.h
//
//  Created by lg on 2020/6/19.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _1_______h
#define _1_______h

//构建乘积数组
//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
vector<int> multiply(const vector<int>& A) {
    int length = A.size();
    vector<int> multiLeft(length,1);
    vector<int> multiRight(length,1);
    vector<int> result(length,1);
    for (int i = 1; i < length; i++) {
        multiLeft[i] = multiLeft[i-1]*A[i-1];
    }
    for (int i = length - 2; i >= 0; i--) {
        multiRight[i] = multiRight[i+1]*A[i+1];
    }
    for (int i = 0; i < length; i++) {
        result[i] = multiLeft[i]*multiRight[i];
    }
    return result;
}

#endif /* _1_______h */
