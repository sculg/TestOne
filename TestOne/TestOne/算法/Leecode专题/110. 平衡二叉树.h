//
//  110. 平衡二叉树.h
//
//  Created by lg on 2020/8/5.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _10________h
#define _10________h
int treeNodeDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    return max(treeNodeDepth(root->left),treeNodeDepth(root->right)) + 1;
}

bool isBalanced(TreeNode* root) {
    if(root == nullptr) {
        return true;
    }
    int leftDept = treeNodeDepth(root->left);
    int rightDept = treeNodeDepth(root->right);
    if(abs(leftDept - rightDept) > 1) {
        return false;
    } else {
        return isBalanced(root->left) && isBalanced(root->right);
    }
}


#endif /* _10________h */
