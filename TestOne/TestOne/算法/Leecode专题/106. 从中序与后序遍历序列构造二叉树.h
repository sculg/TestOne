//
//  106. 从中序与后序遍历序列构造二叉树.h
//
//  Created by lg on 2020/8/8.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _06__________________h
#define _06__________________h

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(postorder.size() == 0 || inorder.size() == 0 || postorder.size() != inorder.size()) {
        return nullptr;
    }
    int rootVale = postorder[postorder.size()-1];
    TreeNode *rootNode = new TreeNode(rootVale);
    vector<int> postLeft,postRight,inLeft,inRight;
    int leftLength = 0;
    while(inorder[leftLength] != rootVale) {
        leftLength++;
    }
    for(int i = 0;i < leftLength; i++) {
        postLeft.push_back(postorder[i]);
        inLeft.push_back(inorder[i]);
    }
    for(int i = leftLength;i < postorder.size()-1; i++) {
        postRight.push_back(postorder[i]);
        inRight.push_back(inorder[i+1]);
    }
    rootNode->left = buildTree(inLeft,postLeft);
    rootNode->right = buildTree(inRight,postRight);
    return rootNode;
}
#endif /* _06__________________h */
