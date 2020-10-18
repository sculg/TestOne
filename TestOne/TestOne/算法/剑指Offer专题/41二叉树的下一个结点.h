//
//  41二叉树的下一个结点.h
//
//  Created by lg on 2020/6/18.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _1__________h
#define _1__________h

//二叉树的下一个结点
//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    
    if (pNode == nullptr) {
        return nullptr;
    }
    TreeLinkNode* result = nullptr;
    if (pNode->right !=nullptr) {
        TreeLinkNode* rightNode = pNode->right;
        while(rightNode->left != nullptr) {
            rightNode = rightNode->left;
        }
        result = rightNode;
    }
    else if (pNode->next != nullptr){
        TreeLinkNode *cur = pNode;
        TreeLinkNode *parentNode = cur->next;
        while (parentNode != nullptr && parentNode->right == cur) {
            cur = parentNode;
            parentNode = parentNode->next;
        }
        result = parentNode;
    }
    return result;
}
#endif /* _1__________h */
