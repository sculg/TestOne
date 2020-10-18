//
//  26二叉树中和为某一值的路径.h
//
//  Created by lg on 2020/6/17.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _6_____________h
#define _6_____________h
//二叉树中和为某一值的路径
//输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
vector<vector<int> > result;
vector<int> temp;
vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    
    if (root == nullptr) {
        return result;
    }
    temp.push_back(root->val);
    if (expectNumber-root->val == 0 && root->left == nullptr && root->right == nullptr) {
        result.push_back(temp);
    }
    if (root->left != nullptr) {
        FindPath(root->left,expectNumber-root->val);
    }
    if (root->right != nullptr) {
        FindPath(root->right,expectNumber-root->val);
    }
    if (temp.size() != 0) {
        temp.pop_back();
    }
    return result;
}
#endif /* _6_____________h */
