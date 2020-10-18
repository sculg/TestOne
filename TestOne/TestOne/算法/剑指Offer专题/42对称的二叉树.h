//
//  42对称的二叉树.h
//
//  Created by lg on 2020/6/18.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _2_______h
#define _2_______h

//对称的二叉树
//请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
bool isSymmetrical(TreeNode* node1,TreeNode* node2) {
    if (node1== nullptr && node2 == nullptr) {
        return true;
    }
    if (node1== nullptr || node2 == nullptr) {
        return false;
    }
    if (node1->val != node2->val) {
        return false;
    }
    return isSymmetrical(node1->left,node2->right)&&isSymmetrical(node1->right,node2->left);
}
bool isSymmetrical(TreeNode* pRoot) {
    if(pRoot == nullptr) {
        return true;
    }
    return isSymmetrical(pRoot->left,pRoot->right);
}
#endif /* _2_______h */
