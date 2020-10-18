//
//  29丑数.h
//
//  Created by lg on 2020/6/17.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _9___h
#define _9___h
//丑数
//把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
int Min(int num1,int num2, int num3) {
    int min = num1 < num2 ? num1 : num2;
    return min < num3 ? min : num3;
}

int GetUglyNumber_Solution(int index) {
    if (index<7) {
        return  index;
    }
    int t2 = 0;
    int t3 = 0;
    int t5 = 0;
    vector<int> arr(index);
    arr[0] = 1;
    for (int  i = 1; i < index; i++) {
        arr[i] = Min(arr[t2]*2, arr[t3]*3, arr[t5]*5);
        if (arr[i] == arr[t2] * 2) {
            t2++;
        }
        if (arr[i] == arr[t3] * 3) {
            t3++;
        }
        if (arr[i] == arr[t5] * 5) {
            t5++;
        }
    }
    return arr[index-1];
}
#endif /* _9___h */
