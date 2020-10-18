//
//  24从上到下打印二叉树 III.h
//
//  Created by lg on 2020/6/17.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _4__________III_h
#define _4__________III_h
// 从上到下打印二叉树 III
//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
vector<vector<int>> PrintFromTopToBottom3(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode *> myQueue;
    if (root == nullptr) {
        return result;
    }
    myQueue.push(root);
    int odd = 1;
    while (!myQueue.empty()) {
        vector<int> ans;
        int length = myQueue.size();
        for (int i = 0; i<length; i++) {
            TreeNode* frontNode= myQueue.front();
            ans.push_back(frontNode->val);
            if (frontNode->left != nullptr) {
                myQueue.push(frontNode->left);
            }
            if (frontNode->right != nullptr) {
                myQueue.push(frontNode->right);
            }
            myQueue.pop();
        }
        if(odd%2 == 0) {
            reverse(ans.begin(),ans.end());//注意翻转数组的方法
        }
        result.push_back(ans);
        odd++;
    }
    return result;
}
#endif /* _4__________III_h */
