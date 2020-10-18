//
//  Construct.h
//
//  Created by lg on 2019/9/24.
//  Copyright © 2019 sculg. All rights reserved.
//

#ifndef Construct_h
#define Construct_h


//由前序遍历和中序遍历构造二叉树

struct BinaryTreeNode {
    int pValue;
    BinaryTreeNode *pLeft;
    BinaryTreeNode *pRight;
};

BinaryTreeNode* Construct(int* preorder,int* inorder, int length){
    if (preorder == nullptr || inorder == nullptr || length<0) {
        return nullptr;
    }
    return ConstructCore(preorder,preorder + length - 1,inorder,inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder) {
    
    // 前序遍历序列的第一个数字是根结点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode *rootNode = new BinaryTreeNode();
    rootNode->pValue = rootValue;
    rootNode->pLeft = rootNode->pRight = nullptr;
    
    if (startPreorder == endInorder) {
        if (startInorder == endInorder) {
            return rootNode;
        }
        else {
            throw ("Invalid input");

        }
    }
    // 在中序遍历中找到根结点的值
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue) {
        rootInorder++;
    }
    
    if (rootInorder > endInorder || *rootInorder != rootValue) {
        throw ("Invalid input");
    }
    
    int leftLength = (int)(rootInorder - startInorder);
    int *leftPreorderEnd = startPreorder + leftLength;
    
    if (leftLength > 0) {
        // 构建左子树
        rootNode->pLeft = ConstructCore(startPreorder + 1,leftPreorderEnd,startInorder,rootInorder - 1);
    }
    
    if (leftLength < endPreorder - startPreorder) {
         // 构建右子树
        rootNode->pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
    return rootNode;
}


//用例
int preOrder[8] = { 1, 2, 4, 7, 3, 5, 6, 8 };
int inOrder[8] = { 4, 7, 2, 1, 5, 3, 8, 6 };
BinaryTreeNode* root = Solution().Construct(preOrder, inOrder, 8);

#endif /* Construct_h */
