//
//  17树的子结构.h
//
//  Created by lg on 2020/6/16.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _7______h
#define _7______h

//树的子结构
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

bool isSubtree(TreeNode* pRootA, TreeNode* pRootB) {
    if (pRootB == nullptr) {
        return true;
    }
    if (pRootA == nullptr) {
        return false;
    }
    
    if (pRootA->val != pRootB->val) {
        return false;
    }
    return (isSubtree(pRootA->left,pRootB->left) && isSubtree(pRootA->right,pRootB->right) );
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if (pRoot1 == nullptr || pRoot2 == nullptr) {
        return false;
    }
    TreeNode* pLeft = pRoot1->left;
    TreeNode* pRight = pRoot1->right;
    return HasSubtree(pLeft, pRoot2) ||HasSubtree(pRight, pRoot2)||isSubtree(pRoot1,pRoot2);

}
#endif /* _7______h */
