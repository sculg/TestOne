//
//  6. Z 字形变换.h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef ___Z______h
#define ___Z______h

string convert(string s, int numRows) {
    if(numRows == 1) {
        return s;
    }
    int curRow = 0;
    bool goDown = false;
    vector<string> rows(min(numRows,int(s.size())));
    for(char c: s) {
        rows[curRow] += c;
        if(curRow == 0 || curRow == numRows -1) {
            goDown = !goDown;
        }
        curRow += goDown ? 1 : -1;
    }
    string result;
    for (string row : rows) {
        result += row;
    }
    return result;
    
}

#endif /* ___Z______h */
