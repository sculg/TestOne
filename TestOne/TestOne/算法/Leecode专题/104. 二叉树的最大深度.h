//
//  104. 二叉树的最大深度.h
//
//  Created by lg on 2020/8/8.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _04___________h
#define _04___________h

int maxDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    return max(maxDepth(root->left),maxDepth(root->right)) + 1;
}

#endif /* _04___________h */
