//
//  187. 重复的DNA序列.h
//
//  Created by lg on 2020/8/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _87_____DNA___h
#define _87_____DNA___h

vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string,int> map;
    vector<string> result;
    int n = s.size();
    for (int i = 0; i + 10 <= n;i++) {
        string t = s.substr(i,10);
        if(map[t] == 1) {
            result.push_back(t);
        }
        map[t]++;
    }
    return result;
}

#endif /* _87_____DNA___h */
