//
//  64. 最长不含重复字符的子字符串.h
//
//  Created by lg on 2020/7/19.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _4________________h
#define _4________________h
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

//暴力解法
int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    unordered_set<char> chars;
    for(int i = 0; i < s.size(); i++) {
        int len = 1;
        chars.clear();
        chars.insert(s[i]);
        for(int j = i + 1;j < s.size();j++) {
            if(chars.count(s[j])) {
                break;
            } else {
                chars.insert(s[j]);
                len ++;
            }
        }
        maxLen = max(maxLen,len);
    }
    return maxLen;
}

//双指针
int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    if(s.size() == 0) return 0;
    unordered_set<char> chars;
    int right = 0;
    for(int left = 0; left < s.size(); left ++){
        while(right < s.size() && !chars.count(s[right])){
            chars.insert(s[right]);
            right ++;
        }
        maxLen = max(maxLen, right - left);
        if(right == s.size()) break;
        chars.erase(s[left]);
    }
    return maxLen;
}

//对双指针的优化

int lengthOfLongestSubstring(string s) {
    vector<int> m(128, -1);
    int res = 0, left = -1;
    for(int i = 0; i < s.size(); ++i) {
        left = max(left, m[s[i]]);
        m[s[i]] = i;
        res = max(res, i - left);
    }
    return res;
    
}

#endif /* _4________________h */
