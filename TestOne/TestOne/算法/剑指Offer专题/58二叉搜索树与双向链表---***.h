//
//  58二叉搜索树与双向链表.h
//
//  Created by lg on 2020/6/24.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _8___________h
#define _8___________h

//二叉搜索树与双向链表
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

void convertNode(TreeNode* pNode,TreeNode** pLastNodeInList) {
    if (pNode == nullptr) {
        return;
    }
    TreeNode *cur = pNode;
    //递归左子树
    if (cur->left != nullptr) {
        convertNode(cur->left,pLastNodeInList);
    }
    //构建双向链表
    cur->left = *pLastNodeInList;
    if (*pLastNodeInList != nullptr) {
        (*pLastNodeInList)->right = cur;
    }
    *pLastNodeInList = cur;
    //递归右子树
    if (cur->right != nullptr) {
        convertNode(cur->right,pLastNodeInList);
    }
}

TreeNode* Convert(TreeNode* pRootOfTree) {
    TreeNode* pLastNodeInList = nullptr;
    convertNode(pRootOfTree,&pLastNodeInList);
    //寻找头节点
    TreeNode* pHeadNode = pLastNodeInList;
    while (pHeadNode != nullptr && pHeadNode->left != nullptr) {
        pHeadNode = pHeadNode->left;
    }
    return pHeadNode;
}

#endif /* _8___________h */
