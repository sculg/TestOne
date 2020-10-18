//
//  searchBin.h
//
//  Created by lg on 2019/9/10.
//  Copyright © 2019 sculg. All rights reserved.
//

#ifndef searchBin_h
#define searchBin_h

//二分查找算法

//递归法
int searchBin(int array[],int low,int high,int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (target == array[mid]) {
            return mid;
        }
        else if (target<array[mid]) {
            return searchBin(array, low, mid-1, target);
        } else {
            return searchBin(array, mid+1, high, target);
        }
    } else {
        return -1;
    }
}

int binarySeach(int arr[], int low, int high, int target) {
    if (arr == nullptr) {
        return -1;
    }
    if (low <= high) {
        int middle = low + (high-low)/2;
        if (target == arr[middle]) {
            return middle;
        }
        if (arr[middle] < target) {
            binarySeach(arr, middle+1, high, target);
        } else {
            binarySeach(arr, low, middle-1, target);
        }
    }
    return -1;
}


//非递归法
int searchBin(int array[],int low,int high,int target) {
    if (array == nullptr || low > high) {
        return -1;
    }
    while (low <= high) {
        int middle = low + (high-low)/2;
        if (array[middle] == target) {
            return middle;
        }
        else if (array[middle] > target) {
            high = middle-1;
        } else {
            low = middle+1;
        }
    }
    return -1;
}

int arr[] = {1,3,4,5,6,7,9};
int index = searchBin(arr, 0, 6, 6);
std::cout<<index<<endl;

#endif /* searchBin_h */
