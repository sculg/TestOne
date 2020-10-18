//
//  31. 下一个排列.h
//
//  Created by lg on 2020/7/30.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _1________h
#define _1________h
void quickSort(vector<int>& nums, int start, int end) {
    if(nums.size() == 0 || start >= end) {
        return;
    }
    int i = start;
    int j = end;
    int temp = nums[i];
    while(i < j) {
        while(i<j && nums[j] >= temp) {
            j--;
        }
        while(i<j && nums[i] <= temp) {
            i++;
        }
        swap(nums[i],nums[j]);
    }
    swap(nums[i],nums[start]);
    quickSort(nums,start,i-1);
    quickSort(nums,i+1,end);
}

void nextPermutation(vector<int>& nums) {
    int rightIndex = nums.size()-1;
    while(rightIndex > 0) {
        if(nums[rightIndex] <= nums[rightIndex-1]) {
            rightIndex--;
        } else {
            break;
        }
    }
    if(rightIndex == 0) {
        int p = 0;
        int q = nums.size()-1;
        while(p<=q) {
            swap(nums[p++],nums[q--]);
        }
        return;
    }
    int j = rightIndex;
    int slected = nums[rightIndex - 1];
    while(nums[j] >= slected) {
        j++;
        if(j == nums.size()) break;
    }
    while(nums[j-1] == slected) {
        j--;
    }
    swap(nums[rightIndex-1],nums[j-1]);
    quickSort(nums,rightIndex,nums.size()-1);
}


void Quick(vector<int>& a, int start, int end)
{
    if (start >= end) return;
    int i = start;
    int j = end;
    int temp = a[i];
    while (i < j)
    {
        while (i < j && a[j] >= temp) j--;
        while (i < j && a[i] <= temp) i++;
        swap(a[i],a[j]);
    }
    swap(a[i],a[start]);
    Quick(a,start,i-1);
    Quick(a,i+1,end);
}

void nextPermutation(vector<int>& nums) {
    int N = nums.size();
    int i = N - 1;
    //找到num[i] > nums[i - 1]的索引i
    while (i > 0)
    {
        if (nums[i] <= nums[i-1]) i--;
        else break;
    }
    //如果i指向了第一个元素，则证明此时是字典排序的最后一个，也证明此时数组是降序排列，应该输出整体升序排列
    if (i == 0)
    {
        int p = 0;
        int q = N - 1;
        //这里利用双指针交换，快速完成升序排列
        while (p <= q) swap(nums[p++],nums[q--]);
        return;
    }
    int j = i;
    int SELECT = nums[i-1];
    //找到比nums[i-1]大的，最小的值并跟nums[i-1]进行交换
    while (nums[j] >= SELECT) {
        j++;
        if (j == N) break;
    }
    while (nums[j - 1] == SELECT) j--;
    swap(nums[i-1],nums[j-1]);
    //i以后进行升序排列。
    Quick(nums,i,N-1);
}

#endif /* _1________h */
