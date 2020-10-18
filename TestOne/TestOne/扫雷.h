//
//  扫雷.h
//
//  Created by lg on 2020/7/25.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef ___h
#define ___h
class Solution {
    
public:
    //右 -> 右下 -> 下 -> 左下 -> 左 -> 左上 -> 上 -> 右上
    int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int stat[50][50];                               //状态
    typedef pair<int, int> Point;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int rsize = board.size(), csize = board[0].size();
        queue<Point> que;
        //点击到地雷
        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        //初始化状态
        memset(stat, 0, sizeof(stat));
        que.push({click[0], click[1]});
        stat[click[0]][click[1]] = 1;
        while(!que.empty()) {
            Point p = que.front(); que.pop();
            //计算相邻的地雷的数量
            int cnt = 0, r = p.first, c = p.second;
            for(int i = 0; i != 8; ++i) {
                int nnr = r + dr[i], nnc = c + dc[i];
                //没有越界, 并且为地雷的情况。
                if(nnr >= 0 && nnr < rsize && nnc >= 0 && nnc < csize
                   && (board[nnr][nnc] == 'M' || board[nnr][nnc] == 'X'))
                    ++cnt;
            }
            // 如果有地雷, 直接揭露。
            if(cnt > 0)
                board[r][c] = cnt + '0';
            // 否则揭露为B, 并增广其相邻的元素
            else {
                board[r][c] = 'B';
                for(int i = 0; i != 8; ++i) {
                    int nnr = r + dr[i], nnc = c + dc[i];
                    //相邻的顶点没有越界, 并且没有被增加到增广队列当中, 且没有被翻过为E
                    if(nnr >= 0 && nnr < rsize && nnc >= 0 && nnc < csize  && stat[nnr][nnc] == 0 && board[nnr][nnc] == 'E') {
                        que.push({nnr, nnc});
                        stat[nnr][nnc] = 1;
                    }
                }
            }
        }
        return board;
    }
};

#endif /* ___h */
