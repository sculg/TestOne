//
//  旋转数组的最小数字.h
//
//  Created by lg on 2020/6/14.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef __________h
#define __________h
//旋转数组的最小数字

//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.size() == 0) {
        return 0;
    }
    //二分法，采用双指针
    int indexLeft = 0;
    int indexRight = rotateArray.size() - 1;
    int middle = indexLeft;
    while (rotateArray[indexLeft] >= rotateArray[indexRight]) {
        if (indexRight - indexLeft == 1) {//终止条件
            middle = indexRight;
            break;
        }
        middle = indexLeft + (indexRight- indexLeft)/2;
        if (rotateArray[middle]>=rotateArray[indexLeft]) {
            indexLeft = middle;
        } else if (rotateArray[middle]<=rotateArray[indexRight]) {
            indexRight = middle;
        }
    }
    return rotateArray[indexRight];
}

//⚠️注意题目是非递减排序，有可能是这样的{1,0,1,1,1},这种情况，会出现rotateArray[indexLeft] = rotateArray[indexRight] = rotateArray[middle]，此时，再进行顺序查找

#endif /* __________h */
