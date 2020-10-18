//
//  40. 组合总和 II.h
//
//  Created by lg on 2020/8/1.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _0_______II_h
#define _0_______II_h

private:
    vector<int> candidates;
    vector<vector<int>> result;
    vector<int> path;
public:
    void DFS(int start,int target) {
        if(target == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start;i<candidates.size()&& target-candidates[i]>=0;i++) {
            if (i > start && candidates[i] == candidates[i-1]){
                continue; // 相同层数相同数字只用一次
            }
            path.push_back(candidates[i]);
            DFS(i+1,target-candidates[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates = candidates;
        DFS(0,target);
        return result;
    }
};
#endif /* _0_______II_h */
