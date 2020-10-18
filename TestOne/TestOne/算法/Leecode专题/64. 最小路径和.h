//
//  64. 最小路径和.h
//
//  Created by lg on 2020/6/28.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _4________h
#define _4________h

//64. 最小路径和
//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
int minPathSum(vector<vector<int>>& grid) {
    if(grid.size() == 0|| grid[0].size() == 0 ) return 0;
    int row = grid.size();
    int col = grid[0].size();
    for(int i = 1;i<row;i++) {
        grid[i][0] = grid[i-1][0] + grid[i][0];
    }
    for(int i = 1;i<col;i++) {
        grid[0][i] = grid[0][i-1] + grid[0][i];
    }
    for (int i = 1; i < row; i++) {
        for (int j = 1;j < col;j++) {
            grid[i][j] = grid[i][j] + min(grid[i-1][j],grid[i][j-1]);
        }
    }
    return grid[row-1][col-1];
}

#endif /* _4________h */
