//
//  22从上往下打印二叉树.h
//
//  Created by lg on 2020/6/17.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _2__________h
#define _2__________h

//从上往下打印二叉树
//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> result;
    queue<TreeNode *> myQueue;
    if (root == nullptr) {
        return result;
    }
    myQueue.push(root);
    TreeNode* frontNode;
    while (!myQueue.empty()) {//注意，这里的条件是!myQueue.empty()，不能用myQueue.front() != nullptr
        frontNode= myQueue.front();
        result.push_back(frontNode->val);
        if (frontNode->left != nullptr) {
            myQueue.push(frontNode->left);
        }
        if (frontNode->right != nullptr) {
            myQueue.push(frontNode->right);
        }
        myQueue.pop();
    }
    return result;
}
#endif /* _2__________h */
