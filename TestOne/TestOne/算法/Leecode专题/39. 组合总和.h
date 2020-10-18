//
//  39. 组合总和.h
//
//  Created by lg on 2020/8/1.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _9_______h
#define _9_______h

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
            path.push_back(candidates[i]);
            DFS(i,target-candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates = candidates;
        DFS(0,target);
        return result;
    }
};
https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/
#endif /* _9_______h */
