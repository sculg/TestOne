//
//  最长回文子串.h
//  TestOne
//
//  Created by lg on 2021/4/13.
//  Copyright © 2021 sculg. All rights reserved.
//

#ifndef _______h
#define _______h

int getLongestPalindrome(string A, int n) {
    // write code here
    int left = 0;
    int right = 0;
    int maxLen = 0;
    for(int i = 0;i < n;i++) {
        left = i;
        right = i;
        while(right < n && left >= 0 && A[right] == A[left]) {
            left--;
            right++;
        }
        maxLen = max(maxLen,right-left-1);
        left = i;
        right = i + 1;
        while(right < n && left >= 0 && A[right] == A[left]) {
            left--;
            right++;
        }
        maxLen = max(maxLen,right-left-1);
    }
    return maxLen;
}

#endif /* _______h */
