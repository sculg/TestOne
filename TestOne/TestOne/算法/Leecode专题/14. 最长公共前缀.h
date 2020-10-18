//
//  14. 最长公共前缀.h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _4_________h
#define _4_________h

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) {
        return "";
    }
    string result;
    string firstStr = strs[0];
    int i ;
    for(i = 0;i < firstStr.size(); i++) {
        char a = firstStr[i];
        for(int j = 0;j < strs.size(); j++) {
            if(strs[j][i] != a) {
                return firstStr.substr(0,i);
            }
        }
    }
    return firstStr.substr(0,i);
}

#endif /* _4_________h */
