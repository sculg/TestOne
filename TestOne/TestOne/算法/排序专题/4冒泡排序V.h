//
//  BubbleSort.h
//
//  Created by lg on 2019/9/16.
//  Copyright © 2019 sculg. All rights reserved.
//

#ifndef BubbleSort_h
#define BubbleSort_h

void BubbleSort(int arr[], int length) {
    if (arr == nullptr || length == 0) {
        return;
    }
    for (int i = 0; i<length; i++) {
        //注意这里为什么要多-1，防止下面的判断越界
        for (int j = 0; j<length - i -1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
Solution().BubbleSort(array,len);
cout<<"The sorted array are:"<<endl;
for(int i=0; i<len; ++i)
{
    cout<< array[i] << " ";
}
cout<<endl;

#endif /* BubbleSort_h */
