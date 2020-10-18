//
//  QuickSort.h
//
//  Created by lg on 2019/9/13.
//  Copyright © 2019 sculg. All rights reserved.
//

#ifndef QuickSort_h
#define QuickSort_h

//快速排序之标准算法
void QuickSort(int arr[], int start, int last) {
    int i = start;
    int j = last;
    int temp = arr[i];
    if (i<j) {
        while (i<j) {
            while (i<j && temp < arr[j]) {
                j--;
            }
            arr[i] = arr[j];
            while (i<j && temp > arr[i]) {
                i++;
            }
            arr[j] = arr[i];
        }
        arr[i] = temp;
        QuickSort(arr, start, i-1);
        QuickSort(arr, i+1, last);
    }
}

void QuickSort(int arr[], int start, int last) {
    int i = start;
    int j = last;
    int temp = arr[i];
    
    if (i<j) {
        while (i<j) {
            while (i<j && temp < arr[j]) {
                j--;
            }
            arr[i] = arr[j];
            while (i<j && temp > arr[i]) {
                i++;
            }
            arr[j] = arr[i];
        }
        arr[i] = temp;
        QuickSort(arr, start, i-1);
        QuickSort(arr, i+1, last);
    }
}





//快速排序之两端换位法
void QuickSort(int arr[], int start, int last) {
    int i = start,j = last;
    int temp = arr[i];
    if (i<j) {
        while (i<=j) {
            while (i<j && temp < arr[j]) {
                j--;
            }
            while (i<j && temp > arr[i]) {
                i++;
            }
            if(i<=j) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                i++;
                j--;
            }
        }
        QuickSort(arr, start, j);
        QuickSort(arr, i, last);
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
Solution().QuickSort(array,0,len-1);
cout<<"The sorted array are:"<<endl;
for(int i=0; i<len; ++i)
{
    cout<< array[i] << " ";
}
cout<<endl;

#endif /* QuickSort_h */
