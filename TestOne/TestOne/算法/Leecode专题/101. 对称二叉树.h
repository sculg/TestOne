//
//  101. 对称二叉树.h
//
//  Created by lg on 2020/8/8.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _01________h
#define _01________h

bool isSymmetric(TreeNode* root) {
    if(root == nullptr) {
        return true;
    }
    return isSymmetric1(root->left,root->right);
}

bool isSymmetric1(TreeNode* root1,TreeNode* root2) {
    if(root1 == nullptr && root2 == nullptr) {
        return true;
    } else if(root1 == nullptr || root2 == nullptr) {
        return false;
    } else if(root1->val != root2->val) {
        return false;
    }
    return isSymmetric1(root1->left,root2->right) && isSymmetric1(root1->right,root2->left);
}

#endif /* _01________h */
