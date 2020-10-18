//
//  103. 二叉树的锯齿形层次遍历.h
//
//  Created by lg on 2020/8/8.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _03______________h
#define _03______________h

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode *> queue;
    if(root == nullptr) {
        return result;
    }
    queue.push(root);
    vector<int> tem;
    int layIndex = 1;
    while(!queue.empty()) {
        int size = queue.size();
        for(int i = 0; i < size; i++) {
            TreeNode* curNode = queue.front();
            tem.push_back(curNode->val);
            queue.pop();
            if(curNode->left != nullptr) {
                queue.push(curNode->left);
            }
            if(curNode->right != nullptr) {
                queue.push(curNode->right);
            }
        }
        if(layIndex%2==0) {
            reverse(tem.begin(),tem.end());
        }
        result.push_back(tem);
        tem.clear();
        layIndex++;
    }
    return result;
}

#endif /* _03______________h */
