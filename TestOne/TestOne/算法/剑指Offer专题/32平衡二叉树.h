//
//  32平衡二叉树.h
//
//  Created by lg on 2020/6/18.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _2______h
#define _2______h

//平衡二叉树
//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
//在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树

int TreeDepth(TreeNode* pRoot)
{
    if(pRoot == nullptr) {
        return 0;
    }

    int leftDepth= TreeDepth(pRoot->left);
    int rightDepth= TreeDepth(pRoot->right);
    
    return leftDepth>rightDepth ? leftDepth+1 : rightDepth+1;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
    if (pRoot == nullptr) {
        return true;
    }
    int leftDepth = TreeDepth(pRoot->left);
    int rightDepth = TreeDepth(pRoot->right);
    if (leftDepth>rightDepth+1 || rightDepth>leftDepth+1) {
        return false;
    } else {
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
    }
}
#endif /* _2______h */
