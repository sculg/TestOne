//
//  199. 二叉树的右视图.h
//
//  Created by lg on 2020/8/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _99__________h
#define _99__________h

vector<int> result;

//深度优先算法
vector<int> rightSideView(TreeNode* root) {
    if(root == nullptr) {
        return result;
    }
    dfs(root,0);
    return result;
}
void dfs(TreeNode* root,int depth) {
    if(root == nullptr) {
        return;
    }
    if(result.size() == depth) {
        result.push_back(root->val);
    }
    dfs(root->right,depth+1);
    dfs(root->left,depth+1);
}

//广度优先算法
vector<int> rightSideView(TreeNode* root) {
    if(root == nullptr) {
        return result;
    }
    queue<TreeNode*> queue;
    queue.push(root);
    while(!queue.empty()) {
        int n = queue.size();
        result.push_back(queue.front()->val);
        TreeNode* temp;
        while(n--) {
            temp = queue.front();
            queue.pop();
            if(temp->right) queue.push(temp->right);
            if(temp->left) queue.push(temp->left);
        }
    }
    return result;
}
#endif /* _99__________h */
