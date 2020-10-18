//
//  11. 盛最多水的容器.h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _1__________h
#define _1__________h

int maxArea(vector<int>& height) {
    int leftIndex = 0;
    int rightIndex = height.size() - 1;
    int maxWaterArea = min(height[leftIndex],height[rightIndex]) * (rightIndex-leftIndex);
    while (leftIndex < rightIndex) {
        if(height[leftIndex] < height[rightIndex]) {
            ++leftIndex;
        } else {
            --rightIndex;
        }
        maxWaterArea = max(maxWaterArea,min(height[leftIndex],height[rightIndex]) * (rightIndex-leftIndex));
    }
    return maxWaterArea;
}

#endif /* _1__________h */
