//
//  18二叉树的镜像.h
//
//  Created by lg on 2020/6/16.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _8_______h
#define _8_______h

//二叉树的镜像
//操作给定的二叉树，将其变换为源二叉树的镜像。
void Mirror(TreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    if ((pRoot->left == nullptr) && (pRoot->right == nullptr)) {
        return;
    }
    TreeNode *pTemp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = pTemp;
    if (pRoot->left != nullptr) {
        Mirror(pRoot->left);
    }
    if (pRoot->right != nullptr) {
        Mirror(pRoot->right);
    }
}
void invertBinaryTree(TreeNode *root) {
    if(root == NULL)
        return;
    stack<TreeNode*> myStack;
    stk.push(root);
    while(!stk.empty())
    {
        TreeNode *tmp = myStack.top();
        myStack.pop();
        swapTree(tmp);
        if(tmp->left)
            myStack.push(tmp->left);
        if(tmp->right)
            myStack.push(tmp->right);
    }
}

void swapTree(TreeNode *&root){
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}


#endif /* _8_______h */
