//
//  HeapSort.h
//
//  Created by lg on 2019/9/16.
//  Copyright © 2019 sculg. All rights reserved.
//

#ifndef HeapSort_h
#define HeapSort_h

void AdjustHeap(int arr[], int node, int size)
{
    int left = 2*node + 1;
    int right = 2*node + 2;
    int max = node;
    if( left < size && arr[left] > arr[max])
        max = left;
    if( right < size && arr[right] > arr[max])
        max = right;
    if(max != node)
    {
        swap( arr[max], arr[node]);
        AdjustHeap(arr, max, size);
    }
}

void HeapSort(int arr[], int len)
{
    // 构建大根堆
    for(int i = len/2 -1; i >= 0; --i)
        AdjustHeap(arr, i, len);
    
    // 调整大根堆
    for(int i = len - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);          // 将当前最大的放置到数组末尾
        AdjustHeap(arr, 0 , i);      // 将未完成排序的部分继续进行堆排序
    }
}

int array[] = {12,234,45,32,54,556,32};
int len = sizeof(array)/sizeof(int);
cout<<"The orginal array are:"<<endl;
for(int i=0; i<len; ++i)
{
    cout<< array[i] << " ";
}
cout<<endl;
Solution().HeapSort(array,len);
cout<<"The sorted array are:"<<endl;
for(int i=0; i<len; ++i)
{
    cout<< array[i] << " ";
}
cout<<endl;

#endif /* HeapSort_h */
