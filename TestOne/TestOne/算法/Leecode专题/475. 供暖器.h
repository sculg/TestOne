//
//  475. 供暖器.h
//
//  Created by lg on 2020/6/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _75______h
#define _75______h

//475. 供暖器
//
//输入: [1,2,3,4],[1,4]
//输出: 1
//解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
//对每个房屋，在供暖器中进行二分查找第一个大于等于房屋位置的供暖器位置，如果找到，则可以求出之间差值dist1，如果这个数不是首个供暖器位置，可以求出和前一个供暖器的位置差值dist2，最后在两者之间求最小值，并更新加热半径。

int findRadius(vector<int>& houses, vector<int>& heaters) {
    int result = 0;
    int length = heaters.size();
    sort(heaters.begin(),heaters.end());
    for (int house : houses) {
        int left = 0, right = length-1;
        while(left<=right) {
            int midlle = left + (right-left)/2;
            if(heaters[midlle] < house) {
                left = midlle + 1;
            }
            else {
                right = midlle - 1;
            }
        }
        // 供暖器在房子右边：
        int rightDis = (left == length) ? INT_MAX:house - heaters[right];
        // 供暖器在房子左边：
        int leftDis = (left == 0) ? INT_MAX:heaters[left]-house ;
        result = max(result,min(leftDis,rightDis));
    }
    return result;
}


#endif /* _75______h */
