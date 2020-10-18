//
//  34和为S的连续正数序列.h
//
//  Created by lg on 2020/6/18.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _4__S________h
#define _4__S________h
//和为S的连续正数序列
//小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int> > result;
    if (sum < 2) {
        return result;
    }
    int left = 1,right = 1, curSum = 1;
    while (left <= right) {
        right++;
        curSum += right;
        while (curSum > sum) {
            curSum -= left;
            left++;
        }
        if (sum == curSum && left!=right) {
            vector<int> res;
            for (int i = left; i<=right; i++) {
                res.push_back(i);
            }
            result.push_back(res);
        }
    }
    return result;
}
#endif /* _4__S________h */
