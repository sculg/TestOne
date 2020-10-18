//
//  23从上到下打印二叉树 II.h
//
//  Created by lg on 2020/6/17.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _3__________II_h
#define _3__________II_h

//从上到下打印二叉树 II
//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
vector<vector<int>> PrintFromTopToBottom2(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode *> myQueue;
    if (root == nullptr) {
        return result;
    }
    myQueue.push(root);
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
        result.push_back(ans);
    }
    return result;
}
#endif /* _3__________II_h */
