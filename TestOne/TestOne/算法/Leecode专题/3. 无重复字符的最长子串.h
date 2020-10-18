//
//  3. 无重复字符的最长子串.h
//
//  Created by lg on 2020/7/28.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef ______________h
#define ______________h

int lengthOfLongestSubstring(string s) {
    int length = s.size();
    int result = 0;
    if(s.size() == 0) {
        return result;
    }
    unordered_set<char> set;
    int start = 0;
    for(int i = 0;i < length; i++) {
        while(set.find(s[i]) != set.end()) {
            set.erase(s[start]);
            start++;
        }
        result = max(result,i-start + 1);
        set.insert(s[i]);
    }
    return result;
}
//双指针思想，i为慢指针，指向当前子串开始位置，j为快指针，指向当前判断的字符
//idx[s[j]]记录字符s[j]上次出现的位置
//每次迭代记录字符出现位置
//当字符s[j]上次出现的位置大于当前子串开始位置i时，比较当前子串长度与目前为止所有子串最大长度，取最大，同时将开始位置设为字符s[j]上次出现位置的下一位

int lengthOfLongestSubstring(string s) {
    int res = 0, i = 0, j = 0;
    vector<int> idx(128, -1);
    while(j < s.size()) {
        if(idx[s[j]] >= i) {
            res = max(res, j - i);
            i = idx[s[j]] + 1;
        }
        idx[s[j]] = j;
        j++;
    }
    res = max(res, j - i);
    return res;
}

#endif /* ______________h */
