//
//  72. 编辑距离.h
//
//  Created by lg on 2020/6/28.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _2_______h
#define _2_______h

//72. 编辑距离
//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
//你可以对一个单词进行如下三种操作：
//插入一个字符
//删除一个字符
//替换一个字符

int minDistance(string word1, string word2) {
    int length1 = word1.size();
    int length2 = word2.size();
    vector<vector<int>> dp(length1+1,vector<int>(length2+1,0));
    for(int i = 1;i<=length2;i++) {
        dp[0][i] = i;
    }
    for(int i = 1;i<=length1;i++) {
        dp[i][0] = i;
    }
    for (int i = 1;i<=length1;i++) {
        for(int j = 1;j<=length2;j++) {
            if(word1[i-1]== word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])) + 1;
            }
        }
    }
    return dp[length1][length2];
}

#endif /* _2_______h */
