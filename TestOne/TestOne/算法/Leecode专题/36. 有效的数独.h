//
//  36. 有效的数独.h
//
//  Created by lg on 2020/7/30.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _6________h
#define _6________h

bool isValidSudoku(vector<vector<char>>& board) {
    int row[9][10] = {0};
    int col[9][10] = {0};
    int box[9][10] = {0};
    for(int i = 0; i < 9;i++) {
        for(int i = 0; i < 9;i++) {
            if(board[i][j] == '.') {
                continue;
            }
            int curNum = borad[i][j] - '0';
            if(row[i][curNum]) {
                return false;
            }
            if(row[j][curNum]) {
                return false;
            }
            if(box[j/3 + (i/3)*3][curNum]) {
                return false;
            }
            row[i][curNum] = 1;
            col[i][curNum] = 1;
            box[j/3 + (i/3)*3][curNum] = 1;
        }
    }
    return true;
}

#endif /* _6________h */
