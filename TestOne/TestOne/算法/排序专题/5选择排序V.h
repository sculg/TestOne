//
//  SelectSort.h
//
//  Created by lg on 2019/9/16.
//  Copyright © 2019 sculg. All rights reserved.
//

#ifndef SelectSort_h
#define SelectSort_h

void SelectSort(int arr[], int length) {
    for (int i = 0; i<length; i++) {
        int min = i;
        for (int j = i+1; j<length; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
Solution().SelectSort(array,len);
cout<<"The sorted array are:"<<endl;
for(int i=0; i<len; ++i)
{
    cout<< array[i] << " ";
}
cout<<endl;

#endif /* SelectSort_h */
