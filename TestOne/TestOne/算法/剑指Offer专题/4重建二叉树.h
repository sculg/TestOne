//
//  reConstructBinaryTree.h
//
//  Created by lg on 2020/6/14.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef reConstructBinaryTree_h
#define reConstructBinaryTree_h

//重建二叉树

//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    int length = pre.size();
    if (length == 0) {
        return NULL;
    }
    vector<int> pre_left,pre_right,vin_left,vin_right;
    TreeNode* resultNode = new TreeNode(pre[0]);
    int leftLength = 0;
    for (int i = 0; i < length; i++) {
        if (vin[i] == pre[0]) {
            leftLength = i;
            break;
        }
    }
    for (int i = 0; i<leftLength; i++) {
        pre_left.push_back(pre[i+1]);//注意，这里是vin[i+1]
        vin_left.push_back(vin[i]);
    }
    
    for (int i = leftLength + 1; i<length; i++) {
        pre_right.push_back(pre[i]);
        vin_right.push_back(vin[i]);
    }
    resultNode->left = reConstructBinaryTree(pre_left,vin_left);
    resultNode->right = reConstructBinaryTree(pre_right,vin_right);
    return resultNode;
}

#endif /* reConstructBinaryTree_h */
