//
//  最长公共子序列.h
//  TestOne
//
//  Created by lg on 2021/4/13.
//  Copyright © 2021 sculg. All rights reserved.
//

#ifndef ________h
#define ________h

string LCS(string s1, string s2) {
    // write code here
    int m = s1.size();
    int n = s2.size();
    string result = "";
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(int i = 0;i <= m;i++) {
        dp[i][0] = 0;
    }
    for(int i = 0;i <= n;i++) {
        dp[0][i] = 0;
    }
    for(int i = 1;i <= m; i++) {
        for(int j = 1;j <= n; j++) {
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    if(dp[m][n] == 0) {
        return "-1";
    }
    
    int p = m,q = n;
    while(p>0 && q>0) {
        if(s1[p-1] == s2[q-1]) {
            result = s1[p-1] + result;
            p--;
            q--;
        } else {
            if(dp[p-1][q] >= dp[p][q-1]){
                p--;
            }else {
                q--;
            }
        }
    }
    return result;
}

#endif /* ________h */
