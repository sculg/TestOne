//
//  107. 二叉树的层次遍历 II.h
//
//  Created by lg on 2020/8/8.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _07___________II_h
#define _07___________II_h
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode *> queue;
    if(root == nullptr) {
        return result;
    }
    queue.push(root);
    vector<int> tem;
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
        result.push_back(tem);
        tem.clear();
    }
    reverse(result.begin(),result.end());
    return result;
}

#endif /* _07___________II_h */
