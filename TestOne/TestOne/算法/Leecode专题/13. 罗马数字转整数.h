//
//  13. 罗马数字转整数.h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _3__________h
#define _3__________h

int romanToInt(string s) {
    map<char,int> map = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int result = 0;
    for(int i = 0;i < s.size(); i++) {
        if(map[s[i]]<map[s[i+1]]) {
            result -= map[s[i]];
        } else {
            result += map[s[i]];
        }
    }
    return result;
}

int romanToInt(string s) {
    int m[256] = {};
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int sum = 0;
    for(int i = 0 ; i < s.size(); ++i) {
        sum = m[s[i]] < m[s[i+1]] ? sum -= m[s[i]]:sum += m[s[i]];
    }
    return sum;
}

#endif /* _3__________h */
