//
//  31二叉树的深度.h
//
//  Created by lg on 2020/6/18.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _1_______h
#define _1_______h

//二叉树的深度
//输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
int TreeDepth(TreeNode* pRoot)
{
    if(pRoot == nullptr) {
        return 0;
    }

    int leftDepth= TreeDepth(pRoot->left);
    int rightDepth= TreeDepth(pRoot->right);
    
    return leftDepth>rightDepth ? leftDepth+1 : rightDepth+1;
}
#endif /* _1_______h */
