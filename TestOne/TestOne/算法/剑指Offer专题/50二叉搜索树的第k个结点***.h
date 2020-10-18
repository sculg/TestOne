//
//  50二叉搜索树的第k个结点.h
//
//  Created by lg on 2020/6/19.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _0_______k____h
#define _0_______k____h
//二叉搜索树的第k个结点
//给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
//中序遍历第K个就是
TreeNode* KthNodeCore(TreeNode *root, int &k){
    TreeNode* target = NULL;
    if (root->left != nullptr) {
        target = KthNodeCore(root->left,k);
    }
    if (target == nullptr) {
        if (k == 1) {
            target = root;
        }
        k--;
    }
    if (target == nullptr && root->right!=nullptr) {
        target = KthNodeCore(root->right,k);
    }
    return target;
}

TreeNode* KthNode(TreeNode* pRoot, int k){
    if (pRoot == nullptr || k == 0) {
        return nullptr;
    }
    return KthNodeCore(pRoot,k);
}
#endif /* _0_______k____h */
