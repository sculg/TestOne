//
//  43最小的K个数.h
//
//  Created by lg on 2020/6/19.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _3___K___h
#define _3___K___h

//最小的K个数
//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

//调整为最大堆
void AdjustHeap(vector<int> &arr, int node, int size) {
    int child = 2*node + 1;
    if (child < size) {
        if (child+1<size && arr[child + 1] > arr[child]) {
            child = child +1;
        }
        if (arr[child]>arr[node]) {
            swap(arr[node], arr[child]);
            AdjustHeap(arr, child, size);
        }
    }
}
//堆排序
//void heapSort(vector<int> &arr,int k) {
//    //先初始化堆
//    for (int i = arr.size()/2-1; i>=0; i--) {
//        AdjustHeap(arr,i,k);
//    }
//    //进行堆排序，即将堆顶的最大值交换到数组最后
//    for (int i = k-1; i>0; i--) {
//        swap(arr[i], arr[0]);
//        AdjustHeap(arr,0,i);
//    }
//}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> result;
    if (input.size() == 0||k == 0|| k>input.size()) {
        return  result;
    }
    //初始化一个大小为K的最大堆
    for (int i = input.size()/2-1; i>=0; i--) {
        AdjustHeap(input,i,k);
    }
    int i = k;
    while (i<input.size()) {
        if (input[0]>input[i]) {
            swap(input[0], input[i]);
            AdjustHeap(input,0,k);
        } else {
            i++;
        }
    }
    for(int i=0;i<k;i++){
        result.push_back(input[i]);
    }
    return result;
}
#endif /* _3___K___h */
