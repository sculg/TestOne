//
//  144. 二叉树的前序遍历.h
//
//  Created by lg on 2020/8/9.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _44___________h
#define _44___________h
//方法一
vector<int> result;
void preorderTraversal1(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    result.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

vector<int> preorderTraversal(TreeNode* root) {
    if(root == nullptr) {
        return result;
    }
    preorderTraversal1(root);
    return result;
}

//方法二

vector<int> result;
vector<int> preorderTraversal(TreeNode* root) {
    if(root!=NULL) {
        result.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    return result;
}

#endif /* _44___________h */
