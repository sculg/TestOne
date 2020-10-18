//
//  111. 二叉树的最小深度.h
//
//  Created by lg on 2020/8/8.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _11___________h
#define _11___________h

int minDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    int leftDep = minDepth(root->left);
    int rightDep = minDepth(root->right);
    if(!leftDep || !rightDep) {
        return leftDep + rightDep + 1;
    }
    return min(leftDep,rightDep)+1;
}

#endif /* _11___________h */
