//
//  矩阵的最小路径和.h
//  TestOne
//
//  Created by lg on 2021/4/13.
//  Copyright © 2021 sculg. All rights reserved.
//

#ifndef _________h
#define _________h

int minPathSum(vector<vector<int> >& matrix) {
    // write code here
    int row = matrix.size();
    if (row == 0) {
        return 0;
    }
    int clom = matrix[0].size();
    int dp[row][clom];
    dp[0][0] = matrix[0][0];
    for(int i = 1;i < clom; i++) {
        dp[0][i] = dp[0][i-1] + matrix[0][i];
    }
    for(int i = 1;i < row; i++) {
        dp[i][0] = dp[i-1][0] + matrix[i][0];
    }
    for(int i = 1;i < row; i++) {
        for(int j = 1;j < clom; j++) {
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + matrix[i][j];
        }
    }
    return dp[row-1][clom-1];
}

#endif /* _________h */
