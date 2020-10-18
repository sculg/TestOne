//
//  221. 最大正方形.h
//
//  Created by lg on 2020/6/28.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _21________h
#define _21________h

//221. 最大正方形
int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row,vector<int>(col));
    int maxSide = 0;
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            if(matrix[i][j] == '1') {
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                }
                maxSide = max(maxSide,dp[i][j]);
            }
        }
    }
    return maxSide*maxSide;
}

#endif /* _21________h */
