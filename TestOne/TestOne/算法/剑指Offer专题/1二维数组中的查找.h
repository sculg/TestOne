//
//  Find.h
//
//  Created by lg on 2020/6/14.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef Find_h
#define Find_h
//《剑指offer》二维数组中的查找

//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

bool Find(int target, vector<vector<int>> array) {
    if (array.size() == 0) {
        return false;
    }
    int row = 0;
    int col = array[0].size()-1;//⚠️注意：这里需-1
    
    while (row < array.size() && col >= 0) {//⚠️注意：这里需>=0
        if (target == array[row][col]) {
            return true;
        } else if (target < array[row][col]) {
            col--;
        } else {
            row++;
        }
    }
    return false;
}

#endif /* Find_h */
