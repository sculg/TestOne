//
//  17. 电话号码的字母组合.h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _7____________h
#define _7____________h

vector<string> result;
string dict[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
string temp;
vector<string> letterCombinations(string digits) {
    if(digits.empty()) {
        return result;
    }
    temp.resize(digits.size());
    dfs(digits,0);
    return result;
}
void dfs(string& digits,int k) {
    if(k == digits.size()) {
        result.push_back(temp);
        return;
    }
    int t = digits[k] - '0';
    for(int i = 0; i < dict[t].size();i++) {
        temp[k] = dict[t][i];
        dfs(digits,k+1);
    }
}

#endif /* _7____________h */
