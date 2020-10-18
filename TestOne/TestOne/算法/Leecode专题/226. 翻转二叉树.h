//
//  226. 翻转二叉树.h
//
//  Created by lg on 2020/8/9.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _26________h
#define _26________h

TreeNode* invertTree(TreeNode* root) {
    TreeNode* res = root;
    if(res == nullptr) {
        return res;
    }
    TreeNode* temp = res->left;
    res->left = res->right;
    res->right = temp;
    if(res->left) {
        invertTree(res->left);
    }
    if(res->right) {
        invertTree(res->right);
    }
    return root;
}

#endif /* _26________h */
