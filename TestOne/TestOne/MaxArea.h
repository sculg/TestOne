//
//  MaxArea.h
//
//  Created by lg on 2019/9/24.
//  Copyright © 2019 sculg. All rights reserved.
//

#ifndef MaxArea_h
#define MaxArea_h

//给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//
//说明：你不能倾斜容器，且 n 的值至少为 2。

int MaxArea(int arr[],int length){
    
    int left = 0;
    int right = length - 1;
    int waterArea = min(arr[left],arr[right]) * (right-left);
    while (left<right) {
        if (arr[left]<arr[right]) {
            ++left;
        }
        else
            --right;
        waterArea = max(waterArea,min(arr[left],arr[right]) * (right-left));
    }
    return waterArea;
}

int arr[] = {2,3,1,6,4,8,7,9,5,11};
int max = Solution().MaxArea(arr, 10);
std::cout<<max<<endl;

#endif /* MaxArea_h */
