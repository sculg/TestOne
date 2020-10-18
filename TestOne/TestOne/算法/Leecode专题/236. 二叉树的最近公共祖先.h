//
//  236. 二叉树的最近公共祖先.h
//
//  Created by lg on 2020/8/9.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _36_____________h
#define _36_____________h

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) {
        return nullptr;
    }
    if(root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);
    if(left == nullptr) {
        return right;
    }
    if(right == nullptr) {
        return left;
    }
    if(left && right) {
        return root;
    }
    return nullptr;
}

#endif /* _36_____________h */
