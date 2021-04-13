//
//  最小编辑代价.h
//  TestOne
//
//  Created by lg on 2021/4/13.
//  Copyright © 2021 sculg. All rights reserved.
//

#ifndef _______h
#define _______h

/**
 * min edit cost
 * @param str1 string字符串 the string
 * @param str2 string字符串 the string
 * @param ic int整型 insert cost
 * @param dc int整型 delete cost
 * @param rc int整型 replace cost
 * @return int整型
 */
int minEditCost(string str1, string str2, int ic, int dc, int rc) {
    // write code here
    int m = str1.size();
    int n = str2.size();
    int dp[m+1][n+1];
    dp[0][0] = 0;
    for(int i = 1;i <= m; i++) {
        dp[i][0] = dp[i-1][0] + dc;
    }
    for(int j = 1;j <= n; j++) {
        dp[0][j] = dp[0][j-1] + ic;
    }
    
    for(int i = 1;i <= m; i++) {
        for(int j = 1;j <= n; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] == dp[i-1][j-1];
            } else {
                int ins = dp[i][j-1] + ic;
                int del = dp[i-1][j] + dc;
                int rep = dp[i-1][j-1] + rc;
                dp[i][j] = min(ins,min(del,rep));
            }
        }
    }
    return dp[m][n];
}

#endif /* _______h */
