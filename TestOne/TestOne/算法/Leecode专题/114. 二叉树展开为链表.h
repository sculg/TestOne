//
//  114. 二叉树展开为链表.h
//
//  Created by lg on 2020/8/9.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _14___________h
#define _14___________h

void flatten(TreeNode* root) {
    while(root != nullptr) {
        if(root->left == nullptr) {
            root = root->right;
        } else {
            TreeNode* pre = root->left;
            while(pre->right != nullptr) {
                pre = pre->right;
            }
            pre->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
}

#endif /* _14___________h */
