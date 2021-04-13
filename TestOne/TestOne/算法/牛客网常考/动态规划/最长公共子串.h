//
//  最长公共子串.h
//  TestOne
//
//  Created by lg on 2021/4/13.
//  Copyright © 2021 sculg. All rights reserved.
//

#ifndef _______h
#define _______h

string LCS(string str1, string str2) {
        // write code here
        int size1 = str1.size();
        int size2 = str2.size();
        int dp[size1][size2];
        int endIndex1;
        int max = 0;
        for(int i = 0;i < size1; i++) {
            for(int j = 0;j < size2; j++) {
                if(str1[i] != str2[j]) {
                    dp[i][j] = 0;
                } else {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }else {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    if( dp[i][j] > max) {
                            max = dp[i][j];
                            endIndex1 = i;
                        }
                }
            }
        }
        return str1.substr(endIndex1 - max + 1,max);
    }

#endif /* _______h */
